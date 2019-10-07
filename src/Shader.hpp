#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader(const char* vertex, const char* fragment);
    void use();
    void setFloat(const char* name, float value) const;
    void setInt(const char* name, int value) const;
    void setBool(const char* name, bool value) const;
    void setMatrix(const char* name, glm::mat4 value) const;
    GLuint getID() const;
private:
    GLuint ID;
};

#endif