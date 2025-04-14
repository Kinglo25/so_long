# so_long

so_long is a 2D game project developed as part of the 42 curriculum. The project challenges you to create a simple game where the player navigates through a map, collects items, and reaches the exit. This project focuses on mastering graphical libraries (typically MLX), handling game logic, and ensuring smooth user interaction.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Bonus](#bonus)
- [Authors](#authors)
- [License](#license)

## Introduction

The so_long project is designed to help you build a small-scale 2D game using a graphical library like MLX. The objective is to create a playable game that demonstrates your understanding of game mechanics, event handling, and dynamic graphics in C. The project adheres to the standards and guidelines of the 42 curriculum.

## Features

- **2D Map Rendering:** Display a game map loaded from a file with characters representing walls, collectibles, exit, and the player.
- **Player Movement:** Implement keyboard controls to move the player around the map.
- **Collision Detection:** Ensure that the player cannot move through walls and interacts correctly with collectibles and the exit.
- **Move Counter:** Track and display the number of moves made by the player.
- **Error Handling:** Provide appropriate feedback for invalid maps or errors during execution.

## Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Kinglo25/so_long.git
   cd so_long
   ```

2. **Compile the Project:**

   Use the provided Makefile to build the project. Run:

   ```bash
   make
   ```

   This command compiles all source files and generates the executable (typically named `so_long`).

3. **Clean Up:**

   To remove compiled files and other build artifacts, run:

   ```bash
   make clean
   ```

## Usage

After compiling the project, run the game from the terminal by passing a valid map file:

```bash
./so_long maps/example.ber
```

- **Map Files:** The game expects map files with a `.ber` extension. The map should be properly formatted with designated characters:
  - `1` — Wall
  - `0` — Empty space
  - `C` — Collectible
  - `E` — Exit
  - `P` — Player start position

Use the arrow keys or WASD (depending on your implementation) to move the player around and collect all items to unlock the exit.

## Testing

To ensure the game works as expected:

- **Map Validation:** Test with different map configurations, including edge cases like maps with missing exit or duplicate player start positions.
- **Gameplay Testing:** Verify that player movement, collision detection, and move counting function properly.
- **Bug Reporting:** Keep an eye out for any graphical glitches or unexpected behavior. Use logs or debugger outputs to diagnose issues.

## Project Structure

A suggested project structure is provided below:

```
so_long/
├── includes/
│   └── so_long.h         # Header file(s) with function prototypes and type definitions
├── src/
│   ├── main.c            # Main program entry point
│   ├── init.c            # Initialization functions (graphics, map, etc.)
│   ├── game_logic.c      # Core game logic and mechanics
│   ├── move_player.c     # Functions to handle player movement and collision detection
│   ├── utils.c           # Utility functions
│   └── ...               # Additional source files as needed
├── maps/
│   └── example.ber       # Sample map for testing the game
├── Makefile              # Compilation script
└── README.md             # Project documentation (this file)
```

## Bonus

To earn bonus points, consider implementing additional features such as:

- **Enhanced Graphics:** Add animations or a smoother graphical interface.
- **Sound Effects:** Integrate sound to enhance the gameplay experience.
- **Improved UI:** Display a move counter, collectible count, or additional game information on screen.
- **Advanced Error Handling:** Provide detailed error messages for different map validation failures.

## Authors

- **Loic M.** ([Kinglo25 on GitHub](https://github.com/Kinglo25))

Special thanks to the 42 community and mentors for their continuous support and inspiration.
