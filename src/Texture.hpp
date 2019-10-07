#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Texture
{
public:
    Texture(const char* path);
    ~Texture();
    void bind();
private:
    unsigned char* data;
    int width, height, nrChannels, ID;
};

#endif