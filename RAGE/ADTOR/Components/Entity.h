#pragma once

#include "../Common/Block.h"
#include <string>
#include <vector>
#include <memory>
#include <cassert>
#include <functional>
#include <algorithm>

class Component;
class Scene;

class Entity : public RBlock
{
public:
    Entity(Scene* scene) {
        assert(scene != nullptr && "Scene cannot be null");
        ParentScene = scene;
    }

    // Getter for Name
    const std::string& getName() const {
        return _name;
    }

    // Setter for Name
    void setName(const std::string& value) {
        if (_name != value) {
            _name = value;
            notify("Name");
        }
    }

    // Getter for Components (read-only)
    const std::vector<std::shared_ptr<Component>>& GetComponents() const {
        return _components;
    }

    // Add a component
    void addComponent(const std::shared_ptr<Component>& component) {
        _components.push_back(component);
    }

    // Remove a component
    void removeComponent(const std::shared_ptr<Component>& component) {
        auto it = std::find(_components.begin(), _components.end(), component);
        if (it != _components.end()) {
            _components.erase(it);
        }
    }

    // Getter for ParentScene
    Scene* getParentScene() const {
        return ParentScene;
    }

private:
    std::string _name; // Internal name variable
    Scene* ParentScene = nullptr; // Pointer to the parent scene
    std::vector<std::shared_ptr<Component>> _components; // Collection of components
};
