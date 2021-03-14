#include "hexagonaldipyramid.h"
#include "main.h"

Hexagonaldipyramid::Hexagonaldipyramid(float x, float y, color_t color)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    float b = (sqrt(3) / 2);
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[12][9] = {

        {-1.0f, 0.0f, 0.0f, // 1st
         -0.5f, -b, 0.0f,
         0.0f, 0.0f, 1.0f},
        {-1.0f, 0.0f, 0.0f, // 2nd
         -0.5f, -b, 0.0f,
         0.0f, 0.0f, -1.0f},
        {-0.5f, -b, 0.0f, // 3rd
         0.5f, -b, 0.0f,
         0.0f, 0.0f, 1.0f},
        {-0.5f, -b, 0.0f, // 4th
         0.5f, -b, 0.0f,
         0.0f, 0.0f, -1.0f},
        {0.5f, -b, 0.0f, // 5th
         1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 1.0f},
        {0.5f, -b, 0.0f, // 6th
         1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, -1.0f},
        {1.0f, 0.0f, 0.0f, // 7th
         0.5f, b, 0.0f,
         0.0f, 0.0f, 1.0f},
        {1.0f, 0.0f, 0.0f, // 8th
         0.5f, b, 0.0f,
         0.0f, 0.0f, -1.0f},
        {0.5f, b, 0.0f, // 9th
         -0.5f, b, 0.0f,
         0.0f, 0.0f, 1.0f},
        {0.5f, b, 0.0f, // 10th
         -0.5f, b, 0.0f,
         0.0f, 0.0f, -1.0f},
        {-0.5f, b, 0.0f, // 11th
         -1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, 1.0f},
        {-0.5f, b, 0.0f, // 12th
         -1.0f, 0.0f, 0.0f,
         0.0f, 0.0f, -1.0f}

    };

    color_t colors[4] = {COLOR_BLACK, COLOR_GREEN, COLOR_RED, COLOR_BLUE};

    for (int i = 0; i < 12; i++)
    {

        this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[i % 4], GL_FILL);
    }
}

void Hexagonaldipyramid::draw(glm::mat4 VP)
{
    // GLuint texture;
    // glGenTextures(1, &texture);
    // glBindTexture(GL_TEXTURE_2D, texture); 
    // int width= 1 , height = 1;
    // unsigned char* image = SOIL_load_image("./download.png", &width, &height, 0, SOIL_LOAD_RGB);
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    // glBindTexture(GL_TEXTURE_2D, 0); 

    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // glBindTexture(GL_TEXTURE_2D, texture);
    for (int i = 0; i < 12; i++)
    {
        draw3DObject(this->object[i]);
    }
}

void Hexagonaldipyramid::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Hexagonaldipyramid::tick()
{
    if (rotate_obj == true)
        this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
