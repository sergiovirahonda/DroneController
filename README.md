# DroneController - Arduino Drone Flight Controller

A simple Arduino-based drone flight controller, designed with clean architecture and robust unit testing.

## Overview

DroneController is an Arduino project that provides:
- **Attitude and motor control** for quadcopters
- **Modular, clean architecture** with separated domain, application, and infrastructure layers
- **Focused unit testing** for domain logic using GoogleTest and CMake

## Architecture

The project follows a clean architecture pattern with three main layers:

```
internal/
├── domain/           # Business logic and data structures
│   ├── attitude.h/cpp
│   ├── motor_output.h/cpp
│   └── drone_command.h/cpp
├── application/      # Application services
│   └── (e.g., flight control logic)
└── infrastructure/   # Hardware interfaces
    ├── mpu_driver.h/cpp
    ├── motor_driver.h/cpp
    └── radio_driver.h/cpp
```

## Hardware Requirements

- **Arduino board** (Uno, Nano, or compatible)
- **MPU6050 or similar IMU** (for attitude sensing)
- **nRF24L01 radio module** (for remote control)
- **Quadcopter frame, ESCs and motors**
- **Connecting wires**
- **LiPO battery**
- **PixHawk**


## Pin Configuration

```cpp
// Example pin configuration
#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9

#define MPU_SDA_PIN A4
#define MPU_SCL_PIN A5

#define RADIO_CE_PIN  9
#define RADIO_CSN_PIN 10
```

## Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/sergiovirahonda/DroneController
   cd DroneController
   ```

2. **Install Arduino IDE** and required libraries:
   - Wire (built-in)
   - MPU6050_light
   - nRF24L01
   - RF24

3. **Upload the sketch**
   - Open `DroneController.ino` in Arduino IDE
   - Select your board and port
   - Upload the sketch

## Usage

1. **Power on** the flight controller
2. **IMU calibration** occurs on startup (if implemented)
3. **Control the drone** using your paired transmitter

## Testing

The project includes a focused unit testing framework using GoogleTest for domain logic.

### Quick Start
```bash
# Build and run all tests
./tests/build_tests.sh

# Or manually
cd tests
mkdir build && cd build
cmake ..
make
./drone_controller_tests
```

### Test Coverage
- **Domain Layer**: Data structures and business logic (15+ tests)
- **Focus**: Core business logic that doesn't require hardware dependencies

For detailed testing information, see [tests/README.md](tests/README.md).

## Development

### Prerequisites
- **Arduino IDE** or **PlatformIO**
- **CMake** (for testing)
- **GoogleTest** (for testing)

### Building Tests
```bash
# Install dependencies (macOS)
brew install cmake googletest

# Build tests
./tests/build_tests.sh
```

### Adding Features
1. **Write tests first** (TDD approach) for domain logic
2. **Follow the architecture** layers
3. **Keep production code unchanged** for testing
4. **Update documentation** as needed

## Testing Philosophy

This project follows a pragmatic testing approach:
- **Test what's easily testable** without modifying production code
- **Focus on domain logic** which is the most critical business logic
- **Keep it simple** - no complex mocking or infrastructure dependencies
- **Don't force testing** on code that would require significant refactoring

## Contributing

1. Fork the repository
2. Create a feature branch
3. Write tests for new domain functionality
4. Implement the feature
5. Ensure all tests pass
6. Submit a pull request

## Troubleshooting

### Common Issues
- **IMU not detected**: Check wiring and I2C address
- **Radio not connecting**: Check wiring and address configuration
- **Motor not spinning**: Verify ESC/motor wiring and pin assignments
- **Test build failures**: Ensure GoogleTest is properly installed

### Debug Mode
```bash
# Build with debug information
cd tests
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
