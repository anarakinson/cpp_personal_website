#pragma once

#include <json/json.h>

#include <iostream>
#include <fstream>
#include <string>


void load_json(const char *filename, Json::Value &value) {

    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        throw std::exception("Failed to open file");
    }

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    std::string errors;

    if (!parseFromStream(builder, ifs, &value, &errors)) {
        throw std::exception("Failed to parse json");
    }
}