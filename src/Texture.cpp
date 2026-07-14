#include "Texture.h"

#include <stb_image.h>

#include <iostream>
#include <stdexcept>
#include <vector>

Texture Texture::createFromPixels(const unsigned char* pixels, int width, int height, int channels, bool pixelArt)
{
    Texture tex;
    tex.m_width = width;
    tex.m_height = height;

    GLenum format = (channels == 4) ? GL_RGBA : (channels == 3) ? GL_RGB : GL_RED;

    glGenTextures(1, &tex.m_id);
    glBindTexture(GL_TEXTURE_2D, tex.m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Pixel art sprites want crisp nearest-neighbor sampling; larger
    // environment/background art can look better with linear filtering.
    GLint filter = pixelArt ? GL_NEAREST : GL_LINEAR;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    return tex;
}

Texture Texture::loadFromFile(const std::string& path, bool pixelArt)
{
    stbi_set_flip_vertically_on_load(true);

    int width, height, channels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (!data)
    {
        throw std::runtime_error("Texture: failed to load image '" + path + "' (" + stbi_failure_reason() + ")");
    }

    Texture tex = createFromPixels(data, width, height, channels, pixelArt);
    stbi_image_free(data);
    return tex;
}

Texture Texture::createCheckerboard(int size, int checks)
{
    std::vector<unsigned char> pixels(static_cast<size_t>(size) * size * 4);
    int cellSize = size / checks;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            bool isLight = ((x / cellSize) + (y / cellSize)) % 2 == 0;
            unsigned char value = isLight ? 220 : 60;

            size_t i = (static_cast<size_t>(y) * size + x) * 4;
            pixels[i + 0] = value;
            pixels[i + 1] = value;
            pixels[i + 2] = isLight ? 220 : 90; // slight tint so it reads as a placeholder, not a real asset
            pixels[i + 3] = 255;
        }
    }

    return createFromPixels(pixels.data(), size, size, 4, /*pixelArt=*/true);
}

void Texture::bind(unsigned int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_id);
}
