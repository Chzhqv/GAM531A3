# GAM531A3

Group Assignment #3 — Sprites, Collision Detection, and Phong Lighting (OpenGL Game Engine Fundamentals).

## Game Concept — *The Trollspire*

A short tech demo built to show off three systems working together along one
path: an animated sprite hero, AABB collision against forest and mountain
obstacles, and a Phong-lit 3D object marking the troll castle at the journey's end.

**The Hero — Arthas:** A gnome of Thornwatch, a small village on the edge of a
great forest bordering the mountains. When trolls take his wife, he leaves the
village alone to bring her back.

**Story:**

1. **The Kidnapping** — Trolls raid Thornwatch at night and drag Arthas's wife
   into the forest, toward the mountains. Arthas sets out after them.
2. **The Burned Village** — Following their trail, Arthas reaches a neighboring
   village, looted and burned by the same troll gang. Among the survivors he
   meets a guide who knows a hidden path through the forest to the mountain.
3. **The Forest Path** — The hidden path is watched. Arthas has to get past
   troll guardians posted along the trail before he can reach the mountain.
4. **The Trollspire** — At the top of the mountain stands the troll castle,
   lit from within by a light no one should be able to see from the village.
   Arthas enters and faces the troll chieftain, Abaddon, to take his wife back.

**Gameplay mapping:** the whole game is one continuous path from the village to
the mountain, split into zones matching the four story beats above. The 5+
required obstacles are troll guardians and forest/rubble debris placed along
the path so the player has to route around them rather than walk straight
through; the required Phong-lit 3D object is the troll castle's light at the
top of the mountain, marking the end of the path and the final encounter with
Abaddon.

## Team Members & Roles

Pick an open role below and replace the placeholder with your name and student
number. Nikita already owns Core Engine & Integration (built out below), and
also floats across the other systems to help unblock whoever needs it.

| Role | What you'll do | Assigned To |
|---|---|---|
| **Core Engine & Integration** | Own `main.cpp`/build architecture, merge everyone's systems into one working scene, keep the CMake build green, resolve merge conflicts. | Nikita Chizhikov — 173740234 |
| **Sprite Sheet & Animation** | Source/import Arthas's sprite sheet into `assets/textures/`, implement UV-based frame-cycling animation on top of the existing `Texture`/`Shader` classes. | _choose a role & add your name + student #_ |
| **Player Movement & Input** | WASD/arrow-key movement, frame-rate independent via the delta time already wired into the main loop, keep player within scene bounds. | _choose a role & add your name + student #_ |
| **Collision Detection (AABB)** | Define AABBs for the player and 5+ obstacles (troll guardians, fallen trees, rubble) along the forest path, implement overlap testing, block the player from passing through. | _choose a role & add your name + student #_ |
| **Phong Lighting** | Add the troll castle as a 3D object at the end of the path, write the GLSL Phong shader (ambient + diffuse + specular) for its light, tune light/material uniforms. | _choose a role & add your name + student #_ |
| **Path/Scene Layout, Art & Docs** | Lay out the village-to-mountain path and obstacle placement across the four story beats, source and credit sprite/texture assets, keep this README current (controls, credits), help with final QA pass. | _choose a role & add your name + student #_ |

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
- **Jul 16 – Jul 17 (integration day):** Merge all systems into one path —
  Arthas moving along the village-to-mountain route, blocked by troll/forest
  obstacles he can't walk through, ending at the Phong-lit troll castle. Fix
  integration bugs, clean up code comments, finalize README (credits,
  controls), submit.

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
