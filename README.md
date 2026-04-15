*This project has been created as part of the 42 curriculum by adchebbi.*

## Description

So Long is a small 2D game built in C using the MiniLibX graphical library. The player navigates a map, collects all collectibles, and reaches the exit to win. The game handles window management, keyboard events, sprite rendering, and map validation from `.ber` files.

The project covers: window creation and event handling with MiniLibX, XPM texture loading and rendering, map parsing and validation (rectangular shape, wall enclosure, valid path via flood fill), and clean memory management verified with Valgrind.

## Instructions

### Dependencies (Linux/WSL)

```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Compilation

```
make
```

### Execution

```
./so_long maps/test.ber
```

### Controls

- `W` / `A` / `S` / `D` — Move up / left / down / right
- `ESC` or window close button — Quit the game

### Map format

Maps use the `.ber` extension with the following characters:
- `1` — Wall
- `0` — Empty space
- `P` — Player starting position (exactly one)
- `E` — Exit (exactly one)
- `C` — Collectible (at least one)

The map must be rectangular, enclosed by walls, and have a valid path from the player to all collectibles and the exit.

## Resources

- [MiniLibX documentation (42docs)](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Linux repository](https://github.com/42Paris/minilibx-linux)
- [X11 events reference](https://tronche.com/gui/x/xlib/events/)

### AI usage

Claude (Anthropic) was used as a collaborative coding assistant throughout this project. Specifically, AI was used for:
- **Architecture design**: structuring the project into logical files (parsing, validation, rendering, movement, cleanup).
- **Code writing**: generating initial implementations of each module, which were then reviewed, understood, and adapted.
- **Debugging**: identifying norminette violations and fixing them (e.g., splitting functions exceeding 25 lines).
- **XPM sprite generation**: creating placeholder 64x64 XPM texture files.
- **README generation**: drafting this file based on the subject requirements.

All code was reviewed and tested manually. The project was validated with Valgrind for memory leaks and tested with multiple valid and invalid maps./