#include "main.h"

#ifndef HEXAGONALDIPYRAMID_H
#define HEXAGONALDIPYRAMID_H

class Hexagonaldipyramid
{
public:
    Hexagonaldipyramid() {}
    Hexagonaldipyramid(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;

private:
    VAO *object[12];
};

#endif // BALL_H
