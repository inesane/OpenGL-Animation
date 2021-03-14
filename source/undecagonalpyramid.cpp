#include "undecagonalpyramid.h"
#include "main.h"

Undecagonalpyramid::Undecagonalpyramid(float x, float y, color_t color)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[22][9] = {

        {0.0f, 0.0f, 1.0f,
         0.84f, 0.54f, 0.0f,
         0.41f, 0.91f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         0.41f, 0.91f, 0.0f,
         -0.14f, 0.99f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         -0.14f, 0.99f, 0.0f,
         -0.65f, 0.75f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         -0.65f, 0.75f, 0.0f,
         -0.96f, 0.28f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         -0.96f, 0.28f, 0.0f,
         -0.96f, -0.28f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         -0.96f, -0.28f, 0.0f,
         -0.65f, -0.75f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         -0.65f, -0.75f, 0.0f,
         -0.14f, -0.99f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         -0.14f, -0.99f, 0.0f,
         0.41f, -0.91f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         0.41f, -0.91f, 0.0f,
         0.84f, -0.54f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         0.84f, -0.54f, 0.0f,
         1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f,
         1.0f, 0.0f, 0.0f,
         0.84f, 0.54f, 0.0f},

        {0.0f, 0.0f, 0.0f,
         0.84f, 0.54f, 0.0f,
         0.41f, 0.91f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         0.41f, 0.91f, 0.0f,
         -0.14f, 0.99f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         -0.14f, 0.99f, 0.0f,
         -0.65f, 0.75f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         -0.65f, 0.75f, 0.0f,
         -0.96f, 0.28f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         -0.96f, 0.28f, 0.0f,
         -0.96f, -0.28f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         -0.96f, -0.28f, 0.0f,
         -0.65f, -0.75f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         -0.65f, -0.75f, 0.0f,
         -0.14f, -0.99f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         -0.14f, -0.99f, 0.0f,
         0.41f, -0.91f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         0.41f, -0.91f, 0.0f,
         0.84f, -0.54f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         0.84f, -0.54f, 0.0f,
         1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 0.0f,
         0.84f, 0.54f, 0.0f}

    };

    color_t colors[3] = {COLOR_BLACK, COLOR_RED, COLOR_BLUE};

    for (int i = 0; i < 22; i++)
    {
        if (i >= 11)
        {
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], COLOR_GREEN, GL_FILL);
        }
        else
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[i % 3], GL_FILL);
    }
}

void Undecagonalpyramid::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for (int i = 0; i < 22; i++)
    {
        draw3DObject(this->object[i]);
    }
}

void Undecagonalpyramid::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Undecagonalpyramid::tick()
{
    if(rotate_obj == true)
        this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
