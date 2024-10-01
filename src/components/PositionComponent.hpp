#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "../ecs/Component.hpp"

// PositionComponent inherits from Component
class PositionComponent : public Component {
public:
    float x, y;
    
    PositionComponent(float x_, float y_) : x(x_), y(y_) {}
};

#endif // POSITION_COMPONENT_HPP
