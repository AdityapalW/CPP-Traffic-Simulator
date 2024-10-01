#ifndef TRAFFIC_LIGHT_SYSTEM_HPP
#define TRAFFIC_LIGHT_SYSTEM_HPP

#include "../ecs/System.hpp"
#include "../components/LightStateComponent.hpp"
#include "../ecs/ComponentManager.hpp"

class TrafficLightSystem : public System {
public:
    void update(EntityManager& entityManager, float deltaTime) override {
        for (Entity entity : entityManager.getEntities()) {
            auto* lightState = static_cast<LightStateComponent*>(lightStateManager.getComponent(entity));
            
            if (lightState) {
                lightState->cycleTime += deltaTime;
                
                if (lightState->cycleTime >= lightState->maxTime) {
                    // Change the light state
                    switch (lightState->currentState) {
                        case RED:
                            lightState->currentState = GREEN;
                            break;
                        case GREEN:
                            lightState->currentState = YELLOW;
                            break;
                        case YELLOW:
                            lightState->currentState = RED;
                            break;
                    }
                    lightState->cycleTime = 0.0f; // Reset the cycle timer
                }
            }
        }
    }

    ComponentManager lightStateManager;
};

#endif // TRAFFIC_LIGHT_SYSTEM_HPP
