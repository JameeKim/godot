#include "json_data.h"

#include "core/os/file_access.h"
#include "core/class_db.h"

void JsonData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("to_string"), &JsonData::to_string);
}

JsonData::JsonData() {
	data = Dictionary();
}

JsonData::~JsonData() {
	data.clear();
}

Error JsonData::parse_file(const String &path) {
	Error file_error;
	FileAccess *file = FileAccess::open(path, FileAccess::READ, &file_error);

	if (file_error) {
		return file_error;
	}

	String content = file->get_as_utf8_string();
	file->close();

	Variant ret;
	String parse_error_msg;
	int parse_error_line;
	Error parse_error = JSON::parse(content, ret, parse_error_msg, parse_error_line);

	if (parse_error) {
		print_error(String("Error while parsing JSON file on line {_}:").format(Variant(parse_error_line)));
		print_error(parse_error_msg);
		return parse_error;
	}

	data = Dictionary(ret);
	return OK;
}
