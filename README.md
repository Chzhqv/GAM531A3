# GAM531A3

Group Assignment #3 — 2D Sprites, Character Design, World Building, and Collision Detection (OpenGL Game Engine Fundamentals).

## Game Concept — *The Trollspire*

A 2D game prototype: an animated sprite hero following a guarded forest path
from his village to a mountain fortress, blocked along the way by AABB-collision
obstacles.

### Character Creation

- **Name:** Arthas
- **Role:** Gnome tracker and villager, a reluctant hero rather than a trained fighter
- **Appearance:** Short, sturdy gnome build; worn leather and a travel cloak;
  carries a short blade and a lit torch. (Final appearance will follow whichever
  CraftPix character sprite sheet the team selects — see Character Creation role below.)
- **Abilities/Skills:** Expert tracker, able to read trails and terrain most
  people would miss; knows the forest well; fights through persistence and
  familiarity with the land rather than combat training.
- **Description:** Arthas is a gnome from Thornwatch, more tracker than
  warrior — the kind of person neighbors ask to find a lost goat, not fight a
  war. He carries a short blade he barely knows how to use and a torch that
  rarely goes out. What he lacks in combat training he makes up for in
  stubbornness: once he's found a trail, he doesn't stop following it,
  mountain or not.

### Background Narrative

Arthas is a gnome from Thornwatch, a small village tucked against the edge of
a great forest that runs up into the mountains. He has never been a fighter.
Neighbors know him as the one who finds lost livestock and reads a trail
better than anyone else in the village — useful, but not the kind of skill
anyone expects to matter in a real fight.

That changes the night trolls come down from the mountains and raid
Thornwatch. They take his wife and vanish back into the trees before anyone
can stop them. Arthas doesn't wait for help. He follows the tracks alone,
into a forest he's walked a hundred times but never this far.

The trail leads him to a neighboring village, already looted and burned by
the same raiding party. Among the survivors he meets a guide who knows a path
through the forest that the trolls don't watch as closely — a way up the
mountain that avoids their usual patrols, if Arthas is careful.

The path isn't empty. Troll guardians hold sections of the trail, and Arthas
has to find ways around them rather than through. Every obstacle he clears
puts him closer to the mountain, and further from anything resembling safety.

At the top waits the Trollspire, the fortress of the troll chieftain Abaddon,
the one who ordered the raid. Arthas has no army and no plan beyond getting
inside. His objective is simple, even if the odds aren't: reach his wife, get
her out, and get both of them back down the mountain alive.

### World Setting

- **Environment:** Thornwatch (starting village) on the edge of a dense
  forest that climbs into rocky mountains; a second, ruined village along the
  way; a guarded forest trail; the Trollspire fortress at the peak.
- **Theme:** Dark fantasy rescue journey.
- **Atmosphere:** Quiet dread — a familiar village turned unsafe overnight, a
  forest that feels watched, and a mountain that looms closer and more
  hostile the further the player travels.
- **Obstacles:** Troll guardians posted along the trail, fallen trees and
  rubble blocking the direct route, wreckage from the burned village — 5+
  placed across the scene as required AABB collision obstacles.

## Team Members & Roles

Pick an open role below and replace the placeholder with your name and
student number. Nikita owns Core Engine, Integration & World/Scene Assets
(built out below), and also floats across the other systems to help unblock
whoever needs it.

| Role | What you'll do | Assigned To |
|---|---|---|
| **Core Engine, Integration & World/Scene Assets** | Own `main.cpp`/build architecture, source CraftPix tileset/environment assets, lay out the village-to-mountain scene, merge everyone's systems into one working build, resolve merge conflicts. | Nikita Chizhikov — 173740234 |
| **Character Creation** | Pick/import Arthas's CraftPix character sprite sheet into `assets/textures/`, finalize his character sheet (name/role/appearance/abilities) to match the chosen art. | _choose a role & add your name + student #_ |
| **Sprite Sheet & Animation** | Implement UV-based frame-cycling animation for Arthas's sprite sheet on top of the existing `Texture`/`Shader` classes. | _choose a role & add your name + student #_ |
| **Player Movement & Input** | WASD/arrow-key movement, frame-rate independent via the delta time already wired into the main loop, keep player within scene bounds. | _choose a role & add your name + student #_ |
| **Collision Detection (AABB)** | Define AABBs for the player and 5+ obstacles (troll guardians, fallen trees, rubble) along the forest path, implement overlap testing, block the player from passing through. | _choose a role & add your name + student #_ |
| **Background Narrative & World Setting (Docs)** | Keep the narrative within 200–400 words, flesh out the world setting section, maintain asset credits and controls in this README, help with final QA pass. | _choose a role & add your name + student #_ |

Team roster: Ryaan Farrukh, Shan-Yun Wang, Aaron Klem, Xena Illarionov, Nikita Chizhikov, Theo Oey

## Project Plan

Due Friday, July 17, 11:59 PM.

- **Now – Jul 15:** Core render loop + texture pipeline done (Nikita). Everyone
  else picks a role above. Character/asset selection, sprite animation,
  movement, and collision tracks start in parallel, each on its own branch.
- **Jul 15 – Jul 16:** Feature branches come together — CraftPix character and
  environment assets in `assets/textures/`, animation playing, movement
  working, obstacles blocking the player. Open a PR into `main` as soon as
  your piece runs on its own; don't wait until it's perfect.
- **Jul 16 – Jul 17 (integration day):** Merge all systems into one scene —
  Arthas moving along the village-to-mountain path, blocked by troll/forest
  obstacles he can't walk through. Fix integration bugs, clean up code
  comments, finalize README (character sheet, narrative, world setting,
  asset credits, controls), submit.

## Controls

- `ESC` — quit
- TODO: movement keys once player movement is implemented

## Implementation Status

- [x] Core render loop (window/context creation, delta time, main loop)
- [x] Texture loading pipeline (`Texture` class, stb_image) — verified with a
      procedurally generated placeholder checkerboard texture
- [ ] Character sprite sheet sourced from CraftPix and imported
- [ ] Sprite sheet loading + UV-based frame animation
- [ ] Player movement (WASD/arrow keys, frame-rate independent)
- [ ] AABB collision detection (5+ obstacles)
- [ ] World/scene assets (tileset, environment) sourced from CraftPix and laid out
- [ ] Asset credits filled in below

## Asset Credits

All game assets must come from [CraftPix](https://craftpix.net/) (free
section) or another free source, credited here.

| Asset | Source | Author | License |
|---|---|---|---|
| _TBD_ | _TBD_ | _TBD_ | _TBD_ |

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
