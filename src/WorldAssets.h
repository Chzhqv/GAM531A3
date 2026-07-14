#pragma once

#include "Texture.h"

#include <string>
#include <vector>

// Character sprite sheet and world/environment asset loading.
//
// NOT YET IMPLEMENTED — see the "Character Creation" and "Background
// Narrative & World Setting" roles in the project README. All assets must be
// sourced from CraftPix (or another free, credited source) and listed in the
// README's Asset Credits table.

struct SpriteAnimation
{
    Texture sheet;
    int frameCount = 0;
    float frameDuration = 0.0f;
};

struct WorldAssets
{
    Texture background;
    std::vector<Texture> tileset;
};

// Loads Arthas's sprite sheet and animation parameters (frame count, timing)
// from assets/textures/.
SpriteAnimation loadCharacterSpriteSheet(const std::string& path);

// Loads the world/environment art (background, tileset) used to build the
// village-to-mountain scene.
WorldAssets loadWorldAssets();
