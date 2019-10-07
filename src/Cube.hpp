#ifndef CUBE_HPP
#define CUBE_HPP

#include "glm/glm.hpp"

enum Type
{
    Grass = 0,
    Brick
};

class Cube
{
public:
    Cube(Type type, float x, float y, float z);
    Cube(Type type, glm::vec3 pos);

    static float vertices[40];
    static unsigned int indices[36];
    Type type;
    glm::vec3 pos;
};

#endif