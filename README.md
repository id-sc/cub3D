*This project has been created as part of the 42 curriculum by hesainte, vikaradu.*

# cub3D

## Description

cub3D is a small first-person maze renderer inspired by Wolfenstein 3D. It uses
ray casting and the MiniLibX graphics library to display a 3D view from a map
described in a `.cub` file.

The program parses wall textures, floor and ceiling colors, validates the map,
initializes the player from an `N`, `S`, `E`, or `W` spawn point, and renders the
scene with different textures for each wall direction.

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- Linux with X11 development libraries, or the appropriate MiniLibX setup for
  the target system

### Compilation

```bash
make
```

Other available rules:

```bash
make clean
make fclean
make re
make bonus
make both
```

### Execution

Run the program with one `.cub` scene file:

```bash
./cub3D maps/valid_big_map.cub
```

### Controls

- `W`: move forward
- `S`: move backward
- `A`: move left
- `D`: move right
- Left arrow: rotate left
- Right arrow: rotate right
- `ESC`: close the program

The window can also be closed with its red close button.

## Scene Format

A scene contains four XPM texture paths, floor and ceiling RGB colors, and a
closed map. Configuration elements may appear in any order, but the map must be
last.

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
111111
```

Map characters:

- `1`: wall
- `0`: empty space
- `N`, `S`, `E`, `W`: player position and starting direction
- Space: empty area outside or between map sections

The map must contain exactly one player and must be completely enclosed by
walls.

## Project Structure

- `src/parser`: scene parsing and map validation
- `src/draw_map`: graphics initialization, ray casting, and rendering
- `src/player`: player initialization, movement, and rotation
- `bonus/minimap`: minimap implementation
- `include`: project headers
- `maps`: valid and invalid test scenes
- `textures`: XPM wall textures
- `libft`: local Libft implementation
- `lib`: MiniLibX sources

## Resources

- [42 MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [DDA algorithm](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
- MiniLibX source code and manual pages included in `lib/`
- The cub3D subject provided by 42

## AI Usage

AI tools were used as supporting tools during development to review the project
structure, suggest test cases, help identify integration and resource-cleanup
issues, and improve documentation. The generated suggestions were reviewed and
tested by the project authors.

## Testing

The `maps` directory contains valid and invalid scenes for parser and integration
testing. Memory checks can be run with Valgrind on Linux:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/valid_big_map.cub
```
