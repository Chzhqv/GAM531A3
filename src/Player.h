#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Player state and WASD/arrow-key movement.
//
// NOT YET IMPLEMENTED — see the "Player Movement & Input" role in the
// project README. Movement must be frame-rate independent (scale by
// deltaTime) and should eventually be constrained by collision detection
// (see Collision.h) so the player cannot walk through obstacles.

struct Player
{
    glm::vec2 position{0.0f, 0.0f};
    glm::vec2 velocity{0.0f, 0.0f};
    float speed = 0.0f;
};

// Reads WASD/arrow-key input and updates the player's position accordingly.
void updatePlayerMovement(Player& player, GLFWwindow* window, float deltaTime);
