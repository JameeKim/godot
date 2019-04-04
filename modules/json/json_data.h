#ifndef JSON_DATA_H
#define JSON_DATA_H

#include "core/dictionary.h"
#include "core/io/json.h"
#include "core/resource.h"

class JsonData : public Resource {
	GDCLASS(JsonData, Resource);
	OBJ_SAVE_TYPE(JsonData);

private:
	Dictionary data;

protected:
	static void _bind_methods();

public:
	JsonData() { data = Dictionary(); }

	Error parse_file(const String &path);

	operator String() const { return JSON::print(data); }

	String to_string() const { return String(*this); }

	Dictionary get_data() const { return data; }
	void set_data(Dictionary new_data) { data = new_data; }
};

#endif // JSON_DATA_H
