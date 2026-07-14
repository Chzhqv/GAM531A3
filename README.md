# GAM531A3

Group Assignment #3 — Sprites, Collision Detection, and Phong Lighting (OpenGL Game Engine Fundamentals).

## Game Concept — *Embercrypt*

A short dungeon-crawl tech demo built to show off three systems working together
in one scene: an animated sprite hero, AABB collision against dungeon obstacles,
and a Phong-lit 3D object acting as the vault's light source.

**Story:** The kingdom's oldest sealed vault has cracked open on its own after a
century shut away. Rumors of a light still burning inside — one that never should
have survived this long — have drawn scavengers, soldiers, and fools alike into
the dark below.

**The Hero — Kael Ashworth:** A disgraced ex-guard turned relic hunter, Kael enters
the vault chasing one thing: proof that the light inside is real, and worth more
than the reputation lost getting here. No map, no backup — just a blade, a torch,
and whatever is waiting in the dark.

## Team Members & Roles

Pick an open role below and replace the placeholder with your name and student
number. Nikita already owns Core Engine & Integration (built out below), and
also floats across the other systems to help unblock whoever needs it.

| Role | What you'll do | Assigned To |
|---|---|---|
| **Core Engine & Integration** | Own `main.cpp`/build architecture, merge everyone's systems into one working scene, keep the CMake build green, resolve merge conflicts. | Nikita Chizhikov — 173740234 |
| **Sprite Sheet & Animation** | Source/import Kael's sprite sheet into `assets/textures/`, implement UV-based frame-cycling animation on top of the existing `Texture`/`Shader` classes. | _choose a role & add your name + student #_ |
| **Player Movement & Input** | WASD/arrow-key movement, frame-rate independent via the delta time already wired into the main loop, keep player within scene bounds. | _choose a role & add your name + student #_ |
| **Collision Detection (AABB)** | Define AABBs for the player and 5+ dungeon obstacles (rubble, pillars, cages, etc.), implement overlap testing, block the player from passing through. | _choose a role & add your name + student #_ |
| **Phong Lighting** | Add the 3D light-source object (e.g. an enchanted brazier/orb), write the GLSL Phong shader (ambient + diffuse + specular), tune light/material uniforms. | _choose a role & add your name + student #_ |
| **Dungeon Scene, Art & Docs** | Lay out the dungeon scene/obstacle placement, source and credit sprite/texture assets, keep this README current (controls, credits), help with final QA pass. | _choose a role & add your name + student #_ |

Team roster: Ryaan Farrukh, Shan-Yun Wang, Aaron Klem, Xena Illarionov, Nikita Chizhikov, Theo Oey

## Project Plan

Due Friday, July 17, 11:59 PM.

- **Now – Jul 15:** Core render loop + texture pipeline done (Nikita). Everyone
  else picks a role above. Sprite sheet, movement, collision, and Phong tracks
  start in parallel, each on its own branch.
- **Jul 15 – Jul 16:** Feature branches come together — animation playing,
  movement working, obstacles blocking the player, cube lit with full Phong.
  Open a PR into `main` as soon as your piece runs on its own; don't wait until
  it's perfect.
- **Jul 16 – Jul 17 (integration day):** Merge all systems into one scene —
  animated hero moving around dungeon obstacles it can't walk through, next to
  a Phong-lit object. Fix integration bugs, clean up code comments, finalize
  README (credits, controls), submit.

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
