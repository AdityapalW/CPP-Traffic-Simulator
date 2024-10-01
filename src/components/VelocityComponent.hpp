#ifndef VELOCITY_COMPONENT_HPP
#define VELOCITY_COMPONENT_HPP

#include "../ecs/Component.hpp"

// VelocityComponent inherits from Component
class VelocityComponent : public Component {
public:
    float speed;
    float direction; // Angle in radians

    VelocityComponent(float s, float d) : speed(s), direction(d) {}
};

#endif // VELOCITY_COMPONENT_HPP
