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
`raygui` produces warnings, but you can ignore them. You could also remove `raygui` (from [CMakeLists.txt](CMakeLists.txt) if you don't intend on using it.

## Run
`.\build\CRaylibTemplate\CRaylibTemplate.exe`

This will open an empty window. *The feared blank canvas.*
