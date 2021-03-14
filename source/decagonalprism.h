#include "main.h"

#ifndef DECAGONALPRISM_H
#define DECAGONALPRISM_H

class Decagonalprism
{
public:
    Decagonalprism() {}
    Decagonalprism(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;

private:
    VAO *object[40];
};

#endif // BALL_H
