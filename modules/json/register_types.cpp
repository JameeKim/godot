#include "register_types.h"

#include "core/class_db.h"

#include "json_data.h"
#include "json_loader.h"

static ResourceFormatLoaderJson *json_loader = NULL;

void register_json_types() {
	json_loader = memnew(ResourceFormatLoaderJson);
	ResourceLoader::add_resource_format_loader(json_loader);

	ClassDB::register_class<JsonData>();
}

void unregister_json_types() {
	memdelete(json_loader);
}
