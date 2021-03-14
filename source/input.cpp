#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"

bool cannon_keyboard_input = true;
bool drag_pan = false, old_cki;
double drag_oldx = -1, drag_oldy = -1;
bool rotate_cam = false;
bool rotate_obj = false;
bool position_1 = false;
bool position_2 = false;
bool position_3 = false;
int obj = 1;

using namespace std;

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE)
    {
        // switch (key) {
        // case GLFW_KEY_C:
        // rectangle_rot_status = !rectangle_rot_status;
        // break;
        // case GLFW_KEY_P:
        // triangle_rot_status = !triangle_rot_status;
        // break;
        // case GLFW_KEY_X:
        //// do something ..
        // break;
        // default:
        // break;
        // }
    }
    else if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        default:
            break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar(GLFWwindow *window, unsigned int key)
{
    switch (key)
    {
    case 'Q':
    case 'q':
        quit(window);
        break;
    case 'r':
        if(rotate_cam == true)
            rotate_cam = false;
        else
            rotate_cam = true;
        break;
    case '7':
        if(rotate_obj == true)
            rotate_obj = false;
        else
            rotate_obj = true;
        break;
    case '8':
        position_1 = true;
        break;
    case '9':
        position_2 = true;
        break;
    case '0':
        position_3 = true;
        break;
    case 'i':
        obj = 1;
        break;
    case 'o':
        obj = 2;
        break;
    case 'p':
        obj = 3;
        break;
    default:
        break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton(GLFWwindow *window, int button, int action, int mods)
{
    switch (button)
    {
    case GLFW_MOUSE_BUTTON_LEFT:
        if (action == GLFW_PRESS)
        {
            // Do something
            return;
        }
        else if (action == GLFW_RELEASE)
        {
            // Do something
        }
        break;
    // case GLFW_MOUSE_BUTTON_RIGHT:
    // if (action == GLFW_RELEASE) {
    // rectangle_rot_dir *= -1;
    // }
    // break;
    default:
        break;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    // Do something
}
