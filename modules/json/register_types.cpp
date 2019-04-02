#include "register_types.h"

#include "core/class_db.h"

#include "json_data.h"

void register_json_types() {
	ClassDB::register_class<JsonData>();
}

void unregister_json_types() {}
