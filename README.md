# Smart Traffic Simulation
Aryan u there
**Smart Traffic Simulation** is a C++ project that simulates vehicle movements and traffic light behavior using an Entity-Component-System (ECS) architecture. This simulation allows multiple vehicles to move through predefined routes while following traffic light signals, with systems handling both movement and traffic control.

## Features

- **Entity-Component-System (ECS) Architecture**: The project uses a modular design where entities (vehicles, traffic lights) are composed of various components (position, velocity, route, light state).
- **Vehicle Movement System**: Simulates vehicle movement using velocity and route-following behavior.
- **Traffic Light System**: Simulates traffic light behavior with red, green, and yellow states that change based on a timed cycle.
- **Dynamic Component Management**: Components are dynamically assigned to entities, allowing for flexible simulation scenarios.

## Project Structure

```bash
/SmartTrafficSimulation
    /src
        /ecs           # Core ECS files
        /components    # Individual components like Position, Velocity, Route, etc.
        /systems       # Systems such as MovementSystem, TrafficLightSystem
        /core          # Core simulation logic
        main.cpp       # Main entry point
    /obj               # Compiled object files
    /bin               # Final executable
    Makefile           # Makefile for building the project
    README.md          # Project README
```

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/AdityapalW/CPP-Traffic-Simulator.git
   ```

2. **Navigate to the project directory:**

   ```bash
   cd SmartTrafficSimulation
   ```

3. **Build the project using `make`:**

   ```bash
   make all
   ```

## Usage

After building the project, you can run the simulation by executing the compiled binary:

```bash
./bin/SmartTrafficSimulation
```

This will simulate a scenario with:
- One vehicle following a predefined route.
- One traffic light cycling through red, green, and yellow states.



## Customization

- **Adding More Vehicles**: In `main.cpp`, create additional entities for vehicles and assign them components like `PositionComponent`, `VelocityComponent`, and `RouteComponent`.
  
- **Adding More Traffic Lights**: Similarly, create additional traffic light entities and assign them `LightStateComponent` with varying cycle times.

- **Modifying Simulation Time**: Adjust the `deltaTime` variable in `main.cpp` to control the speed of the simulation.

## Future Enhancements

- **Pathfinding**: Implement advanced pathfinding algorithms such as A* to allow vehicles to navigate more complex environments.
- **Collision Detection**: Detect and handle collisions between vehicles to simulate traffic congestion or accidents.
- **Visualization**: Integrate a graphics library like SDL2 or SFML to visualize vehicle movement and traffic lights on a 2D grid.

## License

This project is open source and available under the [MIT License](LICENSE).

