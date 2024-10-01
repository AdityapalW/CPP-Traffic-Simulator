#ifndef LIGHT_STATE_COMPONENT_HPP
#define LIGHT_STATE_COMPONENT_HPP

#include "../ecs/Component.hpp"

enum LightState { RED, GREEN, YELLOW };

class LightStateComponent : public Component {
public:
    LightState currentState = RED;
    float cycleTime = 0.0f; // Time spent in the current state
    float maxTime;          // Max time for each state

    LightStateComponent(LightState initialState, float maxTime_)
        : currentState(initialState), maxTime(maxTime_) {}
};

#endif // LIGHT_STATE_COMPONENT_HPP
