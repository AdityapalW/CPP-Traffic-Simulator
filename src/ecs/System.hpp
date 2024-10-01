#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "../ecs/EntityManager.hpp"

// Base class for systems
class System {
public:
    virtual ~System() = default;
    virtual void update(EntityManager& entityManager, float deltaTime) = 0;
};

#endif // SYSTEM_HPP
