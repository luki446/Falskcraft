#include "Texture.hpp"
#include <glad/glad.h>
#include "stb/stb_image.h"
#include <iostream>
#include "log.hpp"

Texture::Texture(const char* path)
{
    glGenTextures(1,(GLuint *) &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);
    data = stbi_load(path, &width, &height, &nrChannels, 3);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        LOGy("Texture loaded ", path)
        LOGy("Width: ", width)
        LOGy("Height: ", height)
        LOGy("Number of channels: ", nrChannels)
    }
    else
    {
        std::cerr << "Failed to load texture " << path << std::endl;
    }
}

Texture::~Texture()
{
    stbi_image_free(data);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}