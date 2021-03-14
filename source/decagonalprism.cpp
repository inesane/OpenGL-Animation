#include "decagonalprism.h"
#include "main.h"

Decagonalprism::Decagonalprism(float x, float y, color_t color)
{
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[40][9] = {

        {1.0f, 0.0f, 0.0f,
        0.81f, 0.59f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {0.81f, 0.59f, 0.0f,
        0.31f, 0.95f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {0.31f, 0.95f, 0.0f,
        -0.31, 0.95f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {-0.31f, 0.95f, 0.0f,
        -0.81f, 0.59f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {-0.81f, 0.59f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {-1.0f, 0.0f, 0.0f,
        -0.81f, -0.59f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {-0.81f, -0.59f, 0.0f,
        -0.31f, -0.95f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {-0.31f, -0.95f, 0.0f,
        0.31f, -0.95f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {0.31f, -0.95f, 0.0f,
        0.81f, -0.59f, 0.0f,
        0.0f, 0.0f, 0.0f},
        {0.81f, -0.59f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f},

        {1.0f, 0.0f, 1.0f,
        0.81f, 0.59f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {0.81f, 0.59f, 1.0f,
        0.31f, 0.95f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {0.31f, 0.95f, 1.0f,
        -0.31, 0.95f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {-0.31f, 0.95f, 1.0f,
        -0.81f, 0.59f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {-0.81f, 0.59f, 1.0f,
        -1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {-1.0f, 0.0f, 1.0f,
        -0.81f, -0.59f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {-0.81f, -0.59f, 1.0f,
        -0.31f, -0.95f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {-0.31f, -0.95f, 1.0f,
        0.31f, -0.95f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {0.31f, -0.95f, 1.0f,
        0.81f, -0.59f, 1.0f,
        0.0f, 0.0f, 1.0f},
        {0.81f, -0.59f, 1.0f,
        1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f},

        {1.0f, 0.0f, 0.0f,
        0.81f, 0.59f, 0.0f,
        0.81f, 0.59f, 1.0f},
        {0.81f, 0.59f, 1.0f,
        1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f},

        {0.81f, 0.59f, 0.0f,
        0.31f, 0.95f, 0.0f,
        0.31f, 0.95f, 1.0f},
        {0.31f, 0.95f, 1.0f,
        0.81f, 0.59f, 1.0f,
        0.81f, 0.59f, 0.0f},

        {0.31f, 0.95f, 0.0f,
        -0.31f, 0.95f, 0.0f,
        -0.31f, 0.95f, 1.0f},
        {-0.31f, 0.95f, 1.0f,
        0.31f, 0.95f, 1.0f,
        0.31f, 0.95f, 0.0f},

        {-0.31f, 0.95f, 0.0f,
        -0.81f, 0.59f, 0.0f,
        -0.81f, 0.59f, 1.0f},
        {-0.81f, 0.59f, 1.0f,
        -0.31f, 0.95f, 1.0f,
        -0.31f, 0.95f, 0.0f},

        {-0.81f, 0.59f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 1.0f},
        {-1.0f, 0.0f, 1.0f,
        -0.81f, 0.59f, 1.0f,
        -0.81f, 0.59f, 0.0f},

        {-1.0f, 0.0f, 0.0f,
        -0.81f, -0.59f, 0.0f,
        -0.81f, -0.59f, 1.0f},
        {-0.81f, -0.59f, 1.0f,
        -1.0f, 0.0f, 1.0f,
        -1.0f, 0.0f, 0.0f},

        {-0.81f, -0.59f, 0.0f,
        -0.31f, -0.95f, 0.0f,
        -0.31f, -0.95f, 1.0f},
        {-0.31f, -0.95f, 1.0f,
        -0.81f, -0.59f, 1.0f,
        -0.81f, -0.59f, 0.0f},

        {-0.31f, -0.95f, 0.0f,
        0.31f, -0.95f, 0.0f,
        0.31f, -0.95f, 1.0f},
        {0.31f, -0.95f, 1.0f,
        -0.31f, -0.95f, 1.0f,
        -0.31f, -0.95f, 0.0f},

        {0.31f, -0.95f, 0.0f,
        0.81f, -0.59f, 0.0f,
        0.81f, -0.59f, 1.0f},
        {0.81f, -0.59f, 1.0f,
        0.31f, -0.95f, 1.0f,
        0.31f, -0.95f, 0.0f},

        {0.81f, -0.59f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 1.0f},
        {1.0f, 0.0f, 1.0f,
        0.81f, -0.59f, 1.0f,
        0.81f, -0.59f, 0.0f}


    };

    color_t colors[4] = {COLOR_BLACK, COLOR_RED, COLOR_BLUE, COLOR_GREEN};

    for (int i = 0; i < 40; i++)
    {
        if(i<10)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[0], GL_FILL);
        else if(i<20)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[1], GL_FILL);
        else if (i<22)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[2], GL_FILL);
        else if (i<24)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[3], GL_FILL);
        else if (i<26)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[2], GL_FILL);
        else if (i<28)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[3], GL_FILL);
        else if (i<30)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[2], GL_FILL);
        else if (i<32)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[3], GL_FILL);
        else if (i<34)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[2], GL_FILL);
        else if (i<36)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[3], GL_FILL);
        else if (i<38)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[2], GL_FILL);
        else if (i<40)
            this->object[i] = create3DObject(GL_TRIANGLES, 1 * 3, vertex_buffer_data[i], colors[3], GL_FILL);
    }
}

void Decagonalprism::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position); // glTranslatef
    glm::mat4 rotate = glm::rotate((float)(this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for (int i = 0; i < 40; i++)
    {
        draw3DObject(this->object[i]);
    }
}

void Decagonalprism::set_position(float x, float y)
{
    this->position = glm::vec3(x, y, 0);
}

void Decagonalprism::tick()
{
    if(rotate_obj == true)
        this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
