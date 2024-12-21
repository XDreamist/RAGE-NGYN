#pragma once

#include <QtCore/QLibrary>
#include <QtCore/QString>
#include <iostream>

class LibManager {
public:
    LibManager(const QString& dllPath) {
        library.setFileName(dllPath);
        if (!library.load()) {
            throw std::runtime_error("Failed to load DLL");
        }
        else {
            std::cout << "Yeay!";
        }
        initFunctions();
    }

    ~LibManager() {
        library.unload();
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

    void initFunctions() {
        someFunction = reinterpret_cast<SomeFunctionType>(library.resolve("SomeFunction"));
        if (!someFunction) {
            throw std::runtime_error("Failed to resolve SomeFunction");
        }
    }
};