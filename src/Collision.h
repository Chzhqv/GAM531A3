#pragma once

#include <glm/glm.hpp>
#include <vector>

// Axis-Aligned Bounding Box collision detection.
//
// NOT YET IMPLEMENTED — see the "Collision Detection (AABB)" role in the
// project README. The scene must contain at least 5 obstacles the player
// cannot pass through.

struct AABB
{
    glm::vec2 min{0.0f, 0.0f};
    glm::vec2 max{0.0f, 0.0f};
};

struct Obstacle
{
    AABB bounds;
    // Visual representation (texture/sprite) gets added once this is wired
    // up to the Character/World assets (see WorldAssets.h).
};

// Returns true if two AABBs overlap.
bool checkAABBCollision(const AABB& a, const AABB& b);

// Returns true if the player's AABB overlaps any obstacle in the scene.
bool checkSceneCollisions(const AABB& playerBounds, const std::vector<Obstacle>& obstacles);
