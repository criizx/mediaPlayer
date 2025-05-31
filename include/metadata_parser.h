#pragma once

#include "music_metadata.h"

class metadata_parser {
public:
	static music_metadata parse(const QString& filepath);
};
