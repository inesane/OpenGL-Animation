#include "main.h"

#ifndef AXES_H
#define AXES_H


class Axes {
public:
    Axes() {}
    Axes(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // BALL_H
