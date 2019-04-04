#include "json_loader.h"

#include "core/class_db.h"
#include "core/print_string.h"

#include "json_data.h"

RES ResourceFormatLoaderJson::load(const String &p_path, const String &p_original_path, Error *r_error) {
	Ref<JsonData> data;
	data.instance();

	Error parse_error = data->parse_file(p_path);

	if (parse_error) {
		print_error(String("error on json load: {_}").format(parse_error));
	}

	if (r_error) {
		*r_error = parse_error;
	}
	return data;
}

void ResourceFormatLoaderJson::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("json");
}

bool ResourceFormatLoaderJson::handles_type(const String &p_type) const {
	return ClassDB::is_parent_class(p_type, "JsonData");
}

String ResourceFormatLoaderJson::get_resource_type(const String &p_path) const {
	return p_path.get_extension().to_lower() == "json" ? "JsonData" : "";
}
