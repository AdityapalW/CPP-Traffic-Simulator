#ifndef ROUTE_COMPONENT_HPP
#define ROUTE_COMPONENT_HPP

#include "../ecs/Component.hpp"
#include <vector>

class RouteComponent : public Component {
public:
    std::vector<std::pair<float, float>> waypoints; // List of points to follow
    std::size_t currentWaypoint = 0;

    RouteComponent(std::vector<std::pair<float, float>> waypoints_)
        : waypoints(std::move(waypoints_)) {}
};

#endif // ROUTE_COMPONENT_HPP
