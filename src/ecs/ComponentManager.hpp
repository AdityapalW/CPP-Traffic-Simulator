#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <unordered_map>
#include <memory>
#include "Component.hpp"

// Component Manager for managing components with polymorphism
class ComponentManager {
public:
    // Add a component to an entity
    void addComponent(Entity entity, std::unique_ptr<Component> component) {
        components[entity] = std::move(component);
    }

    // Retrieve a component for an entity
    Component* getComponent(Entity entity) {
        if (components.find(entity) != components.end()) {
            return components[entity].get();
        }
        return nullptr;
    }

    // Remove a component from an entity
    void removeComponent(Entity entity) {
        components.erase(entity);
    }

private:
    std::unordered_map<Entity, std::unique_ptr<Component>> components;
};

#endif // COMPONENT_MANAGER_HPP
