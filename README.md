
# AimKill

## Introduction

AimKill is a C++ library designed for educational purposes, aimed at enhancing your gaming experience by providing automated aiming and damage functionalities in your game. This library is particularly useful for educational projects exploring automation techniques and game mechanics.

## Features

- **Automated Aiming**: Automatically aim and eliminate enemies without the need for manual input or firing.
- **Dynamic Damage Calculation**: Calculate damage dynamically based on various factors such as distance, weapon type, and player attributes.
- **Optimized Performance**: Designed for optimal performance to ensure smooth automation without compromising on functionality.
- **Educational Purpose**: AimKill is intended for educational use only, providing a hands-on exploration of automation techniques in gaming environments.

## Installation

To integrate AimKill into your educational project, follow these simple steps:

1. Clone this repository to your local machine using the following command:

```bash
git clone https://github.com/springmusk026/AimKill.git
```

2. Include the necessary header files (`AimKill.h` and `Il2Cpp.h`) in your project.

3. Incorporate the provided functions and classes into your game logic as needed.

4. Build your project to compile the AimKill library with your game.

## Usage

To utilize AimKill in your educational project, follow these steps:

1. Check the `config.aimkill` flag to determine if AimKill functionality should be enabled.

2. If AimKill is enabled and an enemy is detected at a non-zero location, start the AimKill functionality using the `Start()` function with appropriate player and enemy parameters.

3. Enjoy automated aiming and enemy elimination without the need for manual input or firing.

4. Remember that this project is for educational purposes only and should not be used for any other purposes.

## Example

```cpp
#include "AimKill.h"

int main() {
    // Initialize AimKill library
    AimKill aimKill;

    // Check if AimKill functionality is enabled and an enemy is detected
    if (this->config.aimkill) {
        if (enemyLocation != Vector3::Zero()) {
            // Start AimKill functionality
            aimKill.Start(localPlayer, closestEnemy);
        }
    }

    // Game logic...

    return 0;
}
```

## Contributing

Contributions to AimKill are welcome! If you have any ideas for improvements or new features, feel free to submit a pull request or open an issue on GitHub.

## License

This project is licensed under the [MIT License](LICENSE).
