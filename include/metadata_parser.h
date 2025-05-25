//
// Created by rr on 22.05.25.
//
#pragma once

#ifndef AUDIO_METADATA_PARSER_H

#include "iosfwd"
#include "music_handler.h"

class metadata_parser {
public:
	virtual ~metadata_parser() = default;
	virtual bool parse(std::istream& file) = 0;
	virtual std::string get_title() const = 0;
	virtual std::string get_artist() const = 0;
	virtual std::string get_album() const = 0;
};


#define AUDIO_METADATA_PARSER_H

#endif //AUDIO_METADATA_PARSER_H
