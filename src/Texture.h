#pragma once

#include <glad/glad.h>
#include <string>

// Loads 2D textures for sprites/sprite sheets. Sprite-sheet frame slicing
// (sub-rectangle UVs) is intentionally not implemented here yet -- that
// belongs in the sprite/animation code once real sprite sheet assets are
// available in assets/textures/.
class Texture
{
public:
    // Loads an image file (PNG/JPG/etc, via stb_image) from disk into a GL texture.
    static Texture loadFromFile(const std::string& path, bool pixelArt = true);

    // Generates a small checkerboard pattern in memory. Used to verify the
    // texture pipeline works before any real assets exist in assets/textures/.
    static Texture createCheckerboard(int size = 64, int checks = 8);

    void bind(unsigned int unit = 0) const;

    unsigned int id() const { return m_id; }
    int width() const { return m_width; }
    int height() const { return m_height; }

private:
    unsigned int m_id = 0;
    int m_width = 0;
    int m_height = 0;

    static Texture createFromPixels(const unsigned char* pixels, int width, int height, int channels, bool pixelArt);
};
