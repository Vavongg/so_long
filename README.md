<div align="center">

# 🌟 so_long

_A tiny 2D game where Kirby collects stars and escapes. Built on MiniLibX._

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr/)
[![Grade](https://img.shields.io/badge/Grade-100%2F100-success?style=for-the-badge)]()
[![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white)]()
[![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-ff69b4?style=for-the-badge)]()
[![Norminette](https://img.shields.io/badge/Norminette-Passing-brightgreen?style=for-the-badge)]()

</div>

---

## 📖 About

**so_long** is the first graphical project of the 42 cursus — a top-down 2D game where the player must collect every collectible on the map before reaching the exit. Along the way, you learn:

- How to draw on screen with **MiniLibX** (42's minimal X11 graphics library)
- Event-driven programming with keyboard hooks and a render loop
- File parsing, map validation, and graph traversal (flood fill)
- Texture loading with `.xpm` images

This version stars **Kirby** on a grass field, hunting for ⭐ stars and dodging walls.

---

## 🎯 Project scope

- ✅ **Mandatory** — map parsing, rendering, movement, collectibles, win condition, move counter
- ⬜ **Bonus** — enemies, animations, sprite variations (not implemented)

---

## 🎮 Controls

| Key     | Action      |
|:-------:|:------------|
| `W`     | Move up     |
| `A`     | Move left   |
| `S`     | Move down   |
| `D`     | Move right  |
| `ESC`   | Quit        |
| `❌`    | Close window |

The move count prints to the terminal in real time. Collect all stars ⭐, then reach the exit 🚪 — the game congratulates you and exits.

---

## 🗺️ Map format

Maps are plain text files with the `.ber` extension. Each character represents a tile:

| Char | Meaning     | Tile                 |
|:----:|:------------|:---------------------|
| `1`  | Wall        | 🧱 (impassable)      |
| `0`  | Empty floor | 🟩 (grass)           |
| `P`  | Player      | 🐥 (Kirby spawn)     |
| `C`  | Collectible | ⭐ (must collect all)|
| `E`  | Exit        | 🚪 (win condition)   |

### Map rules (enforced at parse time)

- Must be **rectangular**
- Must be **surrounded by walls** on all sides
- Must contain **exactly one `P`**, **exactly one `E`**, and **at least one `C`**
- Must have a **valid path** from `P` to every `C` and to `E` (verified via flood fill)
- No invalid characters allowed

### Example

```
1111111111111
1CCCCCCCCCCC1
1C001000100C1
1C001000100C1
1C000000000C1
1C010000010C1
1C011000110C1
1C001111100C1
1P000000000E1
1111111111111
```

---

## 🧠 How it works

```
┌─────────────────────────────────────────────────────────────┐
│  1. PARSING  (src/parsing/)                                 │
│     ├─ check_file():   validates .ber extension & open      │
│     ├─ get_position(): measures map dimensions              │
│     ├─ malloc_map():   allocates 2D char array              │
│     ├─ load_map():     fills the grid from file             │
│     └─ check_map():    runs flood fill to verify solvability│
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│  2. INITIALIZATION  (src/render/)                           │
│     ├─ create_window():  mlx_init + mlx_new_window          │
│     ├─ load_textures():  loads 5 .xpm sprites               │
│     │     [0] grass  [1] wall  [2] star                     │
│     │     [3] Kirby  [4] exit                               │
│     └─ render(): paints the full grid once                  │
└─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│  3. GAME LOOP  (mlx_loop_hook + mlx_hook)                   │
│     key_hit()  ──►  keyboard[] buffer                       │
│                         │                                    │
│     key_loop() ─────────┤                                    │
│                         ▼                                    │
│                   ft_keyboard()                              │
│                         │                                    │
│          ┌──────────────┼──────────────┐                     │
│          ▼              ▼              ▼                     │
│     player_moves()  collision check  render()                │
│          │              │              │                     │
│          └─────► update coords ──► draw only changed tiles   │
└─────────────────────────────────────────────────────────────┘
```

### Flood fill for solvability

Before the window even opens, a recursive flood fill crawls from the player's starting position, marking all reachable `0`, `C` and `E` tiles. After the fill, the parser compares counts:

```
collectibles_found == collectible_total  ──► all C's are reachable ✅
exits_found >= 1                         ──► the exit is reachable  ✅
```

If either check fails → error, the game refuses to launch.

---

## 🛠️ Build

### Requirements

- **Linux** (the Makefile expects X11/XExt: `-lX11 -lXext`)
- A C compiler (`cc` / `gcc`)
- The `minilibx-linux/` folder at the project root (git submodule or bundled)

### Compile

```bash
# Clone
git clone --recursive https://github.com/Vavongg/so_long.git
cd so_long

# Build (compiles MiniLibX automatically)
make

# Cleanup
make clean    # remove .o files
make fclean   # remove .o files + binary + libmlx
make re       # full rebuild
```

---

## 🚀 Usage

```bash
# Launch with a map
./so_long src/maps/map1.ber

# Try the other maps
./so_long src/maps/map2.ber
./so_long src/maps/map3.ber
```

### Sample output

```
~~ so_long launched successfully! ~~
Moves : 0
Moves : 1
Moves : 2
...
Moves : 42
Congratulations! You finished within 42 moves.

 ~~ so_long closed successfully! ~~
```

Invalid maps are caught before the window opens:

```bash
$ ./so_long src/maps/mop1.ber
Error
No exit found
```

---

## 📁 Structure

```
so_long/
├── Makefile
├── include/
│   └── so_long.h              # Struct t_long + all prototypes
├── src/
│   ├── main.c
│   ├── parsing/
│   │   ├── parsing.c          # Orchestrator
│   │   ├── load_map.c         # File → 2D grid
│   │   └── check_map.c        # Flood fill + validation
│   ├── render/
│   │   ├── render.c           # Window + full redraw
│   │   ├── print_texture.c    # Texture loading & tile drawing
│   │   ├── player_moves.c     # Movement logic + win condition
│   │   └── key.c              # Keyboard hooks
│   ├── utils/
│   │   ├── get_next_line.c    # Recursive one-byte GNL
│   │   ├── free_errors.c      # Clean exit + error reporting
│   │   └── ft_utils*.c        # ft_putnbr, ft_strlen, etc.
│   ├── images/                # 5 XPM sprites (grass, wall, Kirby, star, exit)
│   └── maps/                  # Sample maps (.ber)
└── minilibx-linux/            # Graphics library
```

---

## 🧪 Key concepts learned

- **MiniLibX API** — `mlx_init`, `mlx_new_window`, `mlx_hook`, `mlx_loop_hook`, `mlx_put_image_to_window`, `mlx_xpm_file_to_image`
- **Event-driven programming** — distinguishing `KeyPress` (event 2) from `ClientMessage` (event 33) for the close button
- **Flood fill** — recursive graph traversal to verify map solvability before gameplay
- **Dynamic 2D memory** — allocating `char **map`, freeing it cleanly on every exit path
- **XPM format** — 64×64 pixel art tiles indexed as C string arrays
- **Render optimization** — redrawing only the previous + current player tiles instead of the full grid on each move

---

## 🎨 Credits

Sprite art inspired by Nintendo's **Kirby** universe. Used here for educational purposes as part of the 42 cursus.

---

<div align="center">

Built with ☕ at **42 School** · [github.com/Vavongg](https://github.com/Vavongg)

</div>
