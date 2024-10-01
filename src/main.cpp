#include "core/TrafficSimulation.hpp"
#include "components/PositionComponent.hpp"
#include "components/VelocityComponent.hpp"
#include "components/RouteComponent.hpp"
#include "components/LightStateComponent.hpp"

int main() {
    TrafficSimulation simulation;

    // Setup some entities
    Entity vehicle1 = simulation.entityManager.createEntity();
    simulation.getMovementSystem().positionManager.addComponent(vehicle1, std::make_unique<PositionComponent>(0.0f, 0.0f));
simulation.getMovementSystem().velocityManager.addComponent(vehicle1, std::make_unique<VelocityComponent>(5.0f, 0.0f));
    simulation.getMovementSystem().positionManager.addComponent(vehicle1, std::make_unique<RouteComponent>(
        std::vector<std::pair<float, float>>{{10.0f, 10.0f}, {20.0f, 20.0f}}
    ));

    Entity trafficLight1 = simulation.entityManager.createEntity();
simulation.getTrafficLightSystem().lightStateManager.addComponent(trafficLight1, std::make_unique<LightStateComponent>(RED, 5.0f));

    // Simulate in a basic loop
    float deltaTime = 0.016f; // 60 FPS
    for (int i = 0; i < 100; ++i) {
        simulation.run(deltaTime);
    }

    return 0;
}
