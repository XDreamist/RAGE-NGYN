#pragma once

#include <QtCore/QSettings>
#include <QtCore/QString>
#include <QtCore/QDir>
#include <memory>

class ConfigManager
{
public:
    static ConfigManager& getInstance();

    ~ConfigManager();

    bool isValid() const;

    QString getValue(const QString& key, const QString& defaultValue = QString()) const;

    void setValue(const QString& key, const QString& value);

private:
    ConfigManager();

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    bool findConfig();

    QString configFilePath = QDir::currentPath() + "/config.ini";
    QString projectNameKey = "ProjectName";
    std::unique_ptr<QSettings> settings;

protected:
    bool configFound = false;
};