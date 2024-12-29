#pragma once

#include <string>
#include <iostream>

#define RAGE_WARN(msg) warning(msg, __FILE__, __LINE__)

namespace {
    void warning(const std::string& message, const char* file, int line) {
        std::cerr << "Warning: " << message << "\n"
            << "  In file: " << file << "\n"
            << "  At line: " << line << std::endl;
    }
}