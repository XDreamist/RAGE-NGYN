#pragma once

#include <QtCore/QLibrary>
#include <QtCore/QString>
#include <iostream>
#include <vector>

struct TransformComponent
{
    std::vector<float> Position = std::vector<float>(3, 0.0f);
    std::vector<float> Rotation = std::vector<float>(4, 0.0f);
    std::vector<float> Scale = std::vector<float>(3, 1.0f);
};

struct EntityDescriptor
{
    TransformComponent transform;
};

class LibManager {
public:
    explicit LibManager(const QString& dllPath)
        : library(dllPath) {}

    bool load() {
        if (!library.load()) {
            qDebug() << "Failed to load DLL:" << library.errorString();
            return false;
        }
        return initFunctions();
    }

    ~LibManager() {
        if (library.isLoaded()) {
            library.unload();
        }
    }

    int createEntity() {
        if (func_createEntity) {
            EntityDescriptor* desc = new EntityDescriptor;

            return func_createEntity(desc);
        }
        throw std::runtime_error("Function not loaded");
    }

    int removeEntity(int index) {
        if (func_removeEntity) {
            return func_removeEntity(index);
        }
        throw std::runtime_error("Function not loaded");
    }

private:
    QLibrary library;

    // Function pointers
    typedef int (*createEntityType)(EntityDescriptor*);
    createEntityType func_createEntity = nullptr;

    typedef int (*removeEntityType)(int);
    removeEntityType func_removeEntity = nullptr;

    bool initFunctions() {
        func_createEntity = reinterpret_cast<createEntityType>(library.resolve("createEntity"));
        func_removeEntity = reinterpret_cast<removeEntityType>(library.resolve("removeEntity"));
        if (!func_createEntity && func_removeEntity) {
            qDebug() << "Failed to resolve some functions";
            return false;
        }
        return true;
    }
};