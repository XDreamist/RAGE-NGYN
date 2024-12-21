#include "ConfigManager.h"

#include <iostream>
#include <QtCore/QFile>


ConfigManager& ConfigManager::getInstance()
{
    static ConfigManager manager;
    return manager;
}

ConfigManager::ConfigManager()
{
    configFound = findConfig();
}

ConfigManager::~ConfigManager()
{
    settings.reset();
}

bool ConfigManager::isValid() const
{
    return configFound;
}

bool ConfigManager::findConfig()
{
    if (QFile::exists(configFilePath)) {
        settings = std::make_unique<QSettings>(configFilePath, QSettings::IniFormat);

        if (settings->status() != QSettings::NoError) {
            qDebug() << "Error reading config.ini.";
            return false;
        }

        QStringList keys = settings->allKeys();
        for (const QString& key : keys) {
            qDebug() << "Key:" << key << ", Value:" << settings->value(key).toString();
        }

        QVariant projectName = settings->value(projectNameKey);
        if (projectName.isValid()) {
            qDebug() << "Found config.ini. Project Name:" << projectName.toString();
        }
        else {
            qDebug() << "Project Name key not found in config.ini.";
        }

        return true;
    }

    qDebug() << "No config.ini file found in the current directory.";
    return false;
}

QString ConfigManager::getValue(const QString& key, const QString& defaultValue) const
{
    return settings ? settings->value(key, defaultValue).toString() : defaultValue;
}

void ConfigManager::setValue(const QString& key, const QString& value)
{
    if (settings) {
        settings->setValue(key, value);
    }
}
