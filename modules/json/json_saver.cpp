#include "json_saver.h"

#include "core/os/file_access.h"

#include "json_data.h"

Error ResourceFormatSaverJson::save(const String &p_path, const RES &p_resource, uint32_t p_flags) {
	Ref<JsonData> res = p_resource;
	ERR_FAIL_COND_V(res.is_null(), ERR_INVALID_PARAMETER);

	Error error;
	FileAccess *file = FileAccess::open(p_path, FileAccess::WRITE, &error);
	ERR_FAIL_COND_V(!file, ERR_CANT_OPEN);

	if (!error) {
		file->store_string(res->to_string());
		if (file->get_error() && file->get_error() != ERR_FILE_EOF) {
			error = ERR_CANT_CREATE;
		}
	}

	file->close();
	return error;
}

bool ResourceFormatSaverJson::recognize(const RES &p_resource) const {
	return Object::cast_to<JsonData>(*p_resource) != NULL;
}

void ResourceFormatSaverJson::get_recognized_extensions(const RES &p_resource, List<String> *p_extensions) const {
	if (Object::cast_to<JsonData>(*p_resource)) {
		p_extensions->push_front("json");
	}
}
