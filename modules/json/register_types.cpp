#include "register_types.h"

#include "core/class_db.h"
#include "core/io/resource_loader.h"
#include "core/io/resource_saver.h"

#include "json_data.h"
#include "json_loader.h"
#include "json_saver.h"

static Ref<ResourceFormatLoaderJson> json_loader;
static Ref<ResourceFormatSaverJson> json_saver;

void register_json_types() {
	json_loader.instance();
	ResourceLoader::add_resource_format_loader(json_loader);

	json_saver.instance();
	ResourceSaver::add_resource_format_saver(json_saver);

	ClassDB::register_class<JsonData>();
}

void unregister_json_types() {
	ResourceLoader::remove_resource_format_loader(json_loader);
	json_loader.unref();

	ResourceSaver::remove_resource_format_saver(json_saver);
	json_saver.unref();
}
