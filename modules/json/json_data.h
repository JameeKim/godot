#ifndef JSON_DATA_H
#define JSON_DATA_H

#include "core/dictionary.h"
#include "core/io/json.h"
#include "core/resource.h"

class JsonData : public Resource {
	GDCLASS(JsonData, Resource);

private:
	Dictionary data;

public:
	JsonData();
	~JsonData();

	Error parse_file(const String &path);

	operator String() const { return JSON::print(data); }

	String to_string() const { return String(*this); }
};

#endif // JSON_DATA_H
