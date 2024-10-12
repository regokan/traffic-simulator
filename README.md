# Traffic Simulation

## Overview

This project simulates a traffic system with intersections, vehicles, and traffic lights using modern C++ techniques such as multi-threading, smart pointers, and move semantics. It aims to demonstrate concurrency management through `std::thread`, `std::mutex`, and condition variables while building a real-world traffic simulation.

### Core Features

- **Traffic Light**: Manages the signal phases (green/red) with multi-threaded updates.
- **Intersection**: Handles vehicle queuing and ensures safe crossing using promises, futures, and traffic light signals.
- **Street**: Connects intersections and manages vehicle paths.
- **Vehicle**: Simulates driving through intersections using asynchronous programming and constant velocity models.
- **Graphics**: Provides visual rendering of traffic objects.

---

## Installation

### Dependencies

- **OpenCV 4.1+**: For rendering graphics.
- **CMake**: Build system generator.
- **g++ or clang++**: C++ compiler with C++17 support.

---

### Setup and Build Instructions

1. **Clone the repository**:

   ```bash
   git clone https://github.com/regokan/traffic-simulator.git
   cd traffic-simulator
   ```

2. **Install dependencies**:

   - **For Linux (Debian-based)**:

     ```bash
     make setup-debian
     ```

   - **For macOS**:
     ```bash
     make setup-mac
     ```

3. **Build the project**:

   ```bash
   make build
   cd build
   ```

4. **Run the simulation**:

   ```bash
   ./traffic_simulation
   ```

5. **Format the code** (optional):

   ```bash
   make format
   ```

6. **Build with debugging symbols** (optional):

   ```bash
   make debug
   ```

7. **Clean build artifacts**:
   ```bash
   make clean
   ```

---

## High-Level Structure

The project consists of several core classes:

### `TrafficLight`

- Manages traffic signal changes between **red** and **green** using threads.
- Includes methods like `waitForGreen` and `simulate` to control traffic flow.

### `Intersection`

- Manages vehicle queues and ensures vehicles cross intersections safely.
- Uses **promises** and **futures** to control vehicle entry based on traffic light status.
- Starts in a thread using the `simulate` function.

### `Street`

- Connects intersections to form routes for vehicles.
- Maintains links to both inbound and outbound intersections.

### `Vehicle`

- Simulates a vehicle driving between intersections.
- Uses asynchronous programming to request access to intersections.
- Updates position along streets and manages driving speed dynamically.

### `Graphics`

- Renders all traffic objects on a map (e.g., Paris or NYC).
- Displays intersections, streets, and vehicles with color-coded elements.

---

## Project Structure

- **`src/`**: Contains the source files implementing the logic for intersections, vehicles, traffic lights, and graphics.
- **`include/`**: Header files for all core classes.
- **`data/`**: Image files for city maps (Paris and NYC).
- **`CMakeLists.txt`**: Configuration file for CMake.
- **`Makefile`**: Makefile for building and managing the project.

---

## Running the Simulation

1. Choose a city map (Paris or NYC) in the source code (`main.cpp`).
2. Build and run the project.
3. Observe the vehicles moving through intersections based on the traffic light phases.

---

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your improvements.

---

## License

This project is licensed under the **Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)**.  
See the full license at [http://creativecommons.org/licenses/by-nc-nd/4.0](http://creativecommons.org/licenses/by-nc-nd/4.0).
