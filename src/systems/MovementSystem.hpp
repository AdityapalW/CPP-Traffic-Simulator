#ifndef MOVEMENT_SYSTEM_HPP
#define MOVEMENT_SYSTEM_HPP

#include "../ecs/System.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/RouteComponent.hpp"
#include "../ecs/ComponentManager.hpp"
#include <cmath>

class MovementSystem : public System {
public:
    void update(EntityManager& entityManager, float deltaTime) override {
        for (Entity entity : entityManager.getEntities()) {
            auto* position = static_cast<PositionComponent*>(positionManager.getComponent(entity));
            auto* velocity = dynamic_cast<VelocityComponent*>(velocityManager.getComponent(entity));
            auto* route = static_cast<RouteComponent*>(routeManager.getComponent(entity));

            if (position && velocity && route) {
                // Move the vehicle along its current direction
                position->x += velocity->speed * std::cos(velocity->direction) * deltaTime;
                position->y += velocity->speed * std::sin(velocity->direction) * deltaTime;

                // Simple waypoint-based navigation
                if (route->currentWaypoint < route->waypoints.size()) {
                    auto nextPoint = route->waypoints[route->currentWaypoint];
                    float dx = nextPoint.first - position->x;
                    float dy = nextPoint.second - position->y;

                    if (std::sqrt(dx * dx + dy * dy) < 1.0f) {
                        route->currentWaypoint++;
                    }
                }
            }
        }
    }

    ComponentManager positionManager;
    ComponentManager velocityManager;
    ComponentManager routeManager;
};

#endif // MOVEMENT_SYSTEM_HPP
