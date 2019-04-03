#include "json_loader.h"

#include "json_data.h"

RES ResourceFormatLoaderJson::load(const String &p_path, const String &p_original_path, Error *r_error) {
	JsonData *data = memnew(JsonData);
	*r_error = data->parse_file(p_path);
	return Ref<JsonData>(data);
}

void ResourceFormatLoaderJson::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("json");
}

bool ResourceFormatLoaderJson::handles_type(const String &p_type) const {
	return p_type == "JsonData";
}

String ResourceFormatLoaderJson::get_resource_type(const String &p_path) const {
	return p_path.get_extension().to_lower() == "json" ? "JsonData" : "";
}
