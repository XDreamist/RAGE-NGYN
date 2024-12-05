#include "ConfigManager.h"

#include <iostream>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QSettings>
#include <QtCore/QString>


namespace fs = std::filesystem;

ConfigManager::ConfigManager() : settings(nullptr)
{
}

ConfigManager::~ConfigManager()
{
    delete settings;
}

bool ConfigManager::findConfig()
{
    {
        QString configFilePath = QDir::currentPath() + "/config.ini";

        if (QFile::exists(configFilePath)) {
            settings = new QSettings(configFilePath, QSettings::IniFormat);

            if (settings->status() != QSettings::NoError) {
                std::cout << "Error found in config.ini." << std::endl;
                return false;
            }

            QStringList keys = settings->allKeys();

            for (const QString& key : keys) {
                std::cout << "Key: " << key.toStdString() << ", Value: " << settings->value(key).toString().toStdString() << std::endl;
            }

            QVariant prName = settings->value("Project Name");

            if (prName.isValid()) {
                std::cout << "Found and loaded config.ini file. Project Name: " << prName.toString().toStdString() << std::endl;
            }
            else {
                std::cout << "Project Name key not found in config.ini." << std::endl;
            }

            return true;
        }

        std::cout << "No config.ini file found in the current directory." << std::endl;
        return false;
    }
}
