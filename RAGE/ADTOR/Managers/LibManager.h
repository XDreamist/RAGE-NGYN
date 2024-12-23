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

    int callSomeFunction(int param) {
        if (someFunction) {
            return someFunction(param);
        }
        throw std::runtime_error("Function not loaded");
    }

private:
    QLibrary library;

    // Function pointers
    typedef int (*SomeFunctionType)(int);
    SomeFunctionType someFunction = nullptr;

    bool initFunctions() {
        someFunction = reinterpret_cast<SomeFunctionType>(library.resolve("SomeFunction"));
        if (!someFunction) {
            qDebug() << "Failed to resolve SomeFunction";
            return false;
        }
        return true;
    }
};