#pragma once

using namespace std;

class ConfigManager
{
public:
    ConfigManager();
    ~ConfigManager();

    bool findConfig();

private:
    class QSettings* settings = nullptr;
};

