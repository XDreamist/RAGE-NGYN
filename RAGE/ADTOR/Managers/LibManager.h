#pragma once

#include <QtCore/QLibrary>
#include <QtCore/QString>
#include <iostream>
#include <vector>

struct TransformComponent
{
    float Position[3] = { 0.0f, 0.0f, 0.0f };
    float Rotation[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float Scale[3] = { 0.0f, 0.0f, 0.0f };
};

struct EntityDescriptor
{
    int id;
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
        if (!func_createEntity) throw std::runtime_error("Function not loaded");

        EntityDescriptor* desc = new EntityDescriptor;
        int index = func_createEntity(desc);
        if (index >= 0) {
            desc->id = index;
            descriptorsList.append(desc);
            emit entityCreated(index);

            return index;
        }
        return -1;
    }

    bool removeEntity(int index) {
        if (!func_removeEntity) throw std::runtime_error("Function not loaded");

        if (index < 0)  throw std::runtime_error("Invalid id tried to remove");

        func_removeEntity(index);
        descriptorsList.remove(index);
        emit entityRemoved(index);

        return true;
    }

signals:
    void entityCreated(int id);
    void entityRemoved(int id);

private:
    QLibrary library;

    QVector<EntityDescriptor*> descriptorsList;

    // Function pointers
    typedef int (*createEntityType)(EntityDescriptor*);
    createEntityType func_createEntity = nullptr;

    typedef void (*removeEntityType)(int);
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