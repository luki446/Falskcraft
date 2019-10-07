#include "Cube.hpp"

Cube::Cube(Type typei, float x, float y, float z): type(typei), pos(x, y, z)
{
}

Cube::Cube(Type typei, glm::vec3 posi): type(typei), pos(posi)
{
}

float Cube::vertices[40] = {
    1.f, 1.0f, 1.0f, 0.33f, 0.0f,
    1.0f, -1.0f, 1.0f, 0.33f, 1.0f,
    -1.0f, -1.0f, 1.0f, 0.0f, 0.0f
    -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, -1.0f, 0.0f, 1.0f,
    1.0f, -1.0f, -1.0f, 0.0f, 0.0f
    -1.0f, -1.0f, -1.0f, 0.33f, 1.0f,
    -1.0f, 1.0f, -1.0f, 0.33f, 0.0f,
};

unsigned int Cube::indices[36] = {
    0, 1, 3,
    1, 2, 3,
    4, 1, 0,
    4, 5, 1,
    4, 5, 6,
    4, 6, 7,
    3, 2, 7,
    3, 6, 7,
    4, 0, 7,
    0, 3, 7,
    1, 5, 2,
    5, 6, 2
};
