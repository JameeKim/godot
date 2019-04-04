#include "json_data.h"

#include "core/class_db.h"
#include "core/os/file_access.h"

void JsonData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("to_string"), &JsonData::to_string);
	ClassDB::bind_method(D_METHOD("get_data"), &JsonData::get_data);
	ClassDB::bind_method(D_METHOD("set_data", "new_data"), &JsonData::set_data);

	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "data"), "set_data", "get_data");
}

Error JsonData::parse_file(const String &path) {
	Error file_error;
	FileAccess *file = FileAccess::open(path, FileAccess::READ, &file_error);

	if (!file) {
		return ERR_CANT_OPEN;
	}

	if (file_error) {
		file->close();
		return file_error;
	}

	String content = file->get_as_utf8_string();
	file->close();

	Variant ret;
	String parse_error_msg;
	int parse_error_line;
	Error parse_error = JSON::parse(content, ret, parse_error_msg, parse_error_line);

	if (parse_error) {
		print_error(String("Error while parsing JSON file on line {_}:").format(parse_error_line));
		print_error(parse_error_msg);
		return parse_error;
	}

	data = Dictionary(ret);
	return OK;
}
