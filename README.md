# Project Readme: So_Long

## Overview
So_Long is a basic 2D game where the player controls a character to collect collectibles on a map and then escape. The game adheres to specific rules and guidelines, including the use of the MiniLibX for graphic management.

## Files
- **Makefile**: Compiles the source files. Includes targets `all`, `clean`, `fclean`, and `re`.
- **\*.h**: Header files.
- **\*.c**: Source code files.
- **maps**: Directory containing map description files with the .ber extension.
- **textures**: Directory containing images for the game.

## External Functions
- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`
- `strerror`, `exit`
- All functions of the math library (`-lm` compiler option)
- All functions of the MiniLibX
- `ft_printf` or an equivalent coded by the developer

## Libft
Libft is authorized for use in the project.

## Description
The player controls a character on a map, collecting items and escaping to win the game. The game is 2D with top-down or profile view. The movement is controlled by W, A, S, and D keys, or ZQSD/arrow keys. The player can only move into free spaces, not walls.

## Game Rules
- Collect all collectibles and reach the exit for victory.
- Display the current number of movements in the shell.
- Use a 2D view.
- The game is not real-time.

## Graphic Management
- Display the game in a window using MiniLibX.
- Ensure smooth window management (changing windows, minimizing, etc.).
- Pressing ESC or clicking the window's close button must close the program cleanly.

## Map
- Map components: walls (1), collectibles (C), free space (0), exit (E), player's starting position (P).
- Map must contain at least 1 exit, 1 collectible, and 1 starting position.
- Map must be rectangular and surrounded by walls.
- Check for duplicate characters for exit/start positions.
- Verify if the map has a valid path.
- Handle errors and exit cleanly for any misconfiguration in the map file.

## Example Maps
### Map 1
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
### MAP 2
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
## How to Run
- Clone the repository.
- Run make to compile the program.
- Execute the program with a valid .ber map file as a parameter.
./so_long maps/map1.ber

Enjoy playing So_Long! And thanks for all the fish! 🐬
