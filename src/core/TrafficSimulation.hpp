#ifndef TRAFFIC_SIMULATION_HPP
#define TRAFFIC_SIMULATION_HPP

#include "../ecs/EntityManager.hpp"
#include "../systems/MovementSystem.hpp"
#include "../systems/TrafficLightSystem.hpp"
#include <iostream>

class TrafficSimulation {
public:
    TrafficSimulation() {
        // Initialize systems
        movementSystem = std::make_unique<MovementSystem>();
        trafficLightSystem = std::make_unique<TrafficLightSystem>();
    }
     MovementSystem& getMovementSystem() {
        return *movementSystem;
    }

    TrafficLightSystem& getTrafficLightSystem() {
        return *trafficLightSystem;
    }
    void run(float deltaTime) {
        // Update systems
        movementSystem->update(entityManager, deltaTime);
        trafficLightSystem->update(entityManager, deltaTime);
    }

    EntityManager entityManager;

    std::unique_ptr<MovementSystem> movementSystem;
    std::unique_ptr<TrafficLightSystem> trafficLightSystem;
};

#endif // TRAFFIC_SIMULATION_HPP
