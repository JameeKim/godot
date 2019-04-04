#ifndef JSON_SAVER_H
#define JSON_SAVER_H

#include "core/io/resource_saver.h"

class ResourceFormatSaverJson : public ResourceFormatSaver {
	GDCLASS(ResourceFormatSaverJson, ResourceFormatSaver);

public:
	virtual Error save(const String &p_path, const RES &p_resource, uint32_t p_flags = 0) override;
	virtual bool recognize(const RES &p_resource) const override;
	virtual void get_recognized_extensions(const RES &p_resource, List<String> *p_extensions) const override;
};

#endif // JSON_SAVER_H
