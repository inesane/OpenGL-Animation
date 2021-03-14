#include "main.h"

#ifndef UNDECAGONALPYRAMID_H
#define UNDECAGONALPYRAMID_H

class Undecagonalpyramid
{
public:
    Undecagonalpyramid() {}
    Undecagonalpyramid(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;

private:
    VAO *object[22];
};

#endif // BALL_H
