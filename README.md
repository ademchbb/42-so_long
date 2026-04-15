*This project has been created as part of the 42 curriculum by adchebbi.*

# So Long

## Description

So Long is a small 2D game built in C using the MiniLibX graphical library. The player navigates a map, collects all collectibles, and reaches the exit to win.

The project covers:
- **Window & events**: window creation, keyboard input handling with MiniLibX hooks
- **Rendering**: XPM texture loading and tile-based sprite rendering
- **Map parsing**: reading `.ber` files, building a 2D grid
- **Map validation**: rectangular shape, wall enclosure, element counts (P/E/C), and reachability via flood fill
- **Memory management**: clean resource freeing on exit and error, verified with Valgrind

## Instructions

### Dependencies (Linux/WSL)

Install the X11 libraries required to compile MiniLibX:

```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

> MiniLibX itself is automatically cloned from the [42Paris repository](https://github.com/42Paris/minilibx-linux) on the first `make` — no manual download needed.

### Compilation

```bash
make        # Clones MiniLibX if missing, compiles libft, MLX, then so_long
make clean  # Removes object files
make fclean # Removes object files and the binary
make re     # Full recompile
```

The project compiles with `cc` and the flags `-Wall -Wextra -Werror`.

### Execution

Run from the project root :

```bash
./so_long maps/test.ber
```

### Controls

| Key | Action |
|-----|--------|
| `W` or `↑` | Move up |
| `S` or `↓` | Move down |
| `A` or `←` | Move left |
| `D` or `→` | Move right |
| `ESC` or window close | Quit |

Move count is printed to the terminal after each step.

### Map format

Maps use the `.ber` extension. Valid characters:

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player starting position (exactly one) |
| `E` | Exit (exactly one) |
| `C` | Collectible (at least one) |

Rules:
- Must be rectangular
- Must be fully enclosed by walls (`1`)
- Must have a valid path from `P` to every `C` and to `E`

Example valid map (`maps/test.ber`)
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Example invalid map :
```
11111
1P0C1
100C1
1000E1  ← invalid: not rectangular
11111
```

### Textures

The game uses 64×64 XPM sprites located in `textures/`:

| File | Used for |
|------|---------|
| `wall.xpm` | Character `1` |
| `floor.xpm` | Background of all non-wall tiles |
| `player.xpm` | Character `P` |
| `collect.xpm` | Character `C` |
| `exit.xpm` | Character `E` |

## Resources

- [MiniLibX documentation (42docs)](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Linux repository](https://github.com/42Paris/minilibx-linux)
- [X11 events reference](https://tronche.com/gui/x/xlib/events/)

### AI usage

Claude (Anthropic) was used as a collaborative coding assistant throughout this project:
- **Architecture design**: structuring the project into logical modules (parsing, validation, rendering, movement, cleanup).
- **Code writing**: implementing each module, reviewed and understood line by line.
- **Debugging**: fixing norminette violations, memory leaks, and logic errors.
- **XPM texture generation**: creating 64×64 pixel-art XPM sprites via a Python generation script.
- **README writing**: drafting and updating this file.

All code was reviewed and tested manually. Validated with Valgrind (zero leaks from project code) and tested with multiple valid and invalid maps.
