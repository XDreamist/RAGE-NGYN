#pragma once

#include <vector>
#include <functional>
#include <string>

class RBlock {
public:
    using Listener = std::function<void(const std::string&)>;

    void addEventListener(Listener listener) {
        listeners.push_back(listener);
    }

    void notify(const std::string& message) {
        for (auto& listener : listeners) {
            listener(message);
        }
    }

private:
    std::vector<Listener> listeners;
};