# C Raylib Template

A simple template with boilerplate `raylib` code.

## Features
- Simple `cmake` files
- `raylib` and `raygui` via `FetchContent`
- Game Structure, containing main camera object
- Configuration structure
- Per-frame Update
- Fixed Update (configurable)
- Rendering boilerplate for Camera and UI

## Prerequisites
The following applications should be installed and accessible on `PATH`.
- CMake
- A C compiler, for example `clang`
- A build system, for example `ninja`

## Build
The configure command uses `Ninja` generator and `clang` compiler. Modify for your specific toolchain.
```sh
cmake --fresh -G Ninja -DCMAKE_C_COMPILER=clang -S . -B build
cmake --build build
```
`raygui` produces warnings, but you can ignore them.

## Run
`.\build\CRaylibTemplate\CRaylibTemplate.exe`

This will open an empty window. *The feared blank canvas.*


## Make Your Game
### [`game.c`](game.c)
- Update functions are here. Add code to them.
    - `update()` is for per-frame updates.
    - `fixedUpdate()` occurs at the rate specified in `config` object (defaults to 1/60 of a second).
- Rendering functions are here. Render your data here.
    - `renderUI()` is for camera-space rendering
    - `renderGame()` is for world-space rendering
- Initialize the camera if needed
    - Defaults to a zoom of 1 and spawns at (0, 0) world-space.
