#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <vector>
#include <unordered_map>
#include <functional>

using Entity = std::size_t;
constexpr Entity INVALID_ENTITY = static_cast<Entity>(-1);

class EntityManager {
public:
    Entity createEntity() {
        Entity newEntity = nextEntityID++;
        entities.push_back(newEntity);
        return newEntity;
    }

    void removeEntity(Entity entity) {
        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    }

    const std::vector<Entity>& getEntities() const {
        return entities;
    }

private:
    Entity nextEntityID = 0;
    std::vector<Entity> entities;
};

#endif // ENTITY_MANAGER_HPP
