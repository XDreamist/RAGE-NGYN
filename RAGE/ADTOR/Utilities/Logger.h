#pragma once

#include "../Common/RageBase.h"

class Logger : public RageBase {
public:
    void log(const std::string& message) {
        notify(message);
    }
};