#pragma once

#include <QtCore/QLibrary>
#include <QtCore/QString>
#include <iostream>

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

    int createEntity(class EntityDescriptor* descriptor) {
        if (func_createEntity) {
            return func_createEntity(descriptor);
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
    typedef int (*createEntityType)(class EntityDescriptor*);
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