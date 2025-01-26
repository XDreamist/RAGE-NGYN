#pragma once

#include "../Common/Block.h"
#include "Entity.h"
#include <cassert>

class Component : public RBlock {
public:
    // Constructor
    explicit Component(Entity* owner) {
        assert(owner != nullptr && "Owner cannot be null");
        Owner = owner;
    }

    // Getter for Owner
    Entity* GetOwner() const {
        return Owner;
    }

    // Setter for Owner
    void SetOwner(Entity* owner) {
        assert(owner != nullptr && "Owner cannot be null");
        Owner = owner;
    }

private:
    Entity* Owner = nullptr; // Pointer to the owning entity
};
