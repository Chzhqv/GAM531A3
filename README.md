# GAM531A3

Group Assignment #3 — Sprites, Collision Detection, and Phong Lighting (OpenGL Game Engine Fundamentals).

## Team Members

Niktia Chizhikov 173740234

- TODO

## Controls

- `ESC` — quit
- TODO: movement keys once player movement is implemented

## Implementation Status

- [x] Core render loop (window/context creation, delta time, main loop)
- [x] Texture loading pipeline (`Texture` class, stb_image) — verified with a
      procedurally generated placeholder checkerboard texture
- [ ] Sprite sheet loading + UV-based frame animation
- [ ] Player movement (WASD/arrow keys, frame-rate independent)
- [ ] AABB collision detection (5+ obstacles)
- [ ] Phong lighting (ambient + diffuse + specular) on a 3D object
- [ ] Asset credits (sprite sheets / textures, once added)

## Building

Requires CMake 3.15+ and a C++17 compiler. GLFW and GLM are fetched
automatically by CMake; GLAD and stb_image are vendored under `external/`.

```
cmake -B build
cmake --build build
./build/bin/GAM531A3
```

## Project Layout

```
src/            engine/game source (Shader, Texture, main loop)
shaders/        GLSL shaders
assets/textures/  sprite sheets & texture assets (drop art here)
external/       vendored GLAD + stb_image
```
