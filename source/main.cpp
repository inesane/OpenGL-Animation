#include "main.h"
#include "timer.h"
#include "ball.h"
#include "hexagonaldipyramid.h"
#include "axes.h"
#include "undecagonalpyramid.h"
#include "decagonalprism.h"

using namespace std;

float cam_x = 0, cam_y = 0, cam_z = 0, cam_x1 = 0, cam_y1 = 0, cam_z1 = 0;


GLMatrices Matrices;
GLuint programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

// Ball hexagonaldipyramid1;

Hexagonaldipyramid hexagonaldipyramid1;
Axes axes1;
Undecagonalpyramid undecagonalpyramid1;
Decagonalprism decagonalprism1;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 5;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw()
{
    // clear the color and depth in the frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram(programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye(cam_x + 5*cos(camera_rotation_angle*M_PI/180.0f), cam_y, cam_z + 5*sin(camera_rotation_angle*M_PI/180.0f));
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target(cam_x1, cam_y1, cam_z1);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up(0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt(eye, target, up); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP; // MVP = Projection * View * Model

    // Scene render
    if(obj == 1)
        hexagonaldipyramid1.draw(VP);
    else if(obj == 2)
        decagonalprism1.draw(VP);
    else if(obj == 3)
        undecagonalpyramid1.draw(VP);
}

void tick_input(GLFWwindow *window)
{
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int left = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int forward = glfwGetKey(window, GLFW_KEY_F);
    int backward = glfwGetKey(window, GLFW_KEY_B);
    int one = glfwGetKey(window, GLFW_KEY_1);
    int two = glfwGetKey(window, GLFW_KEY_2);
    int three = glfwGetKey(window, GLFW_KEY_3);
    int four = glfwGetKey(window, GLFW_KEY_4);
    int five = glfwGetKey(window, GLFW_KEY_5);
    int six = glfwGetKey(window, GLFW_KEY_6);
    if (down)
    {
        cam_y -= 0.1;
        cam_y1 -= 0.1;
    }
    if (up)
    {
        cam_y += 0.1;
        cam_y1 += 0.1;
    }
    if (left)
    {
        cam_x -= 0.1;
        cam_x1 -= 0.1;
    }
    if (right)
    {
        cam_x += 0.1;
        cam_x1 += 0.1;
    }
    if (forward)
    {
        cam_z -= 0.1;
        cam_z1 -= 0.1;
    }
    if (backward)
    {
        cam_z += 0.1;
        cam_z1 += 0.1;
    }
    if (one)
    {
        hexagonaldipyramid1.position.x += 0.1;
        decagonalprism1.position.x += 0.1;
        undecagonalpyramid1.position.x += 0.1;
    }
    if (two)
    {
        hexagonaldipyramid1.position.x -= 0.1;
        decagonalprism1.position.x -= 0.1;
        undecagonalpyramid1.position.x -= 0.1;
    }
    if (three)
    {
        hexagonaldipyramid1.position.y += 0.1;
        decagonalprism1.position.y += 0.1;
        undecagonalpyramid1.position.y += 0.1;
    }
    if (four)
    {
        hexagonaldipyramid1.position.y -= 0.1;
        decagonalprism1.position.y -= 0.1;
        undecagonalpyramid1.position.y -= 0.1;
    }
    if (five)
    {
        hexagonaldipyramid1.position.z += 0.1;
        decagonalprism1.position.z += 0.1;
        undecagonalpyramid1.position.z += 0.1;
    }
    if (six)
    {
        hexagonaldipyramid1.position.z -= 0.1;
        decagonalprism1.position.z -= 0.1;
        undecagonalpyramid1.position.z -= 0.1;
    }
}

void tick_elements()
{
    hexagonaldipyramid1.tick();
    axes1.tick();
    undecagonalpyramid1.tick();
    decagonalprism1.tick();
    if(rotate_cam == true)
    {
        // printf("ASDKASDKJKADSKUDSAK\n");
        // camera_rotation_angle += 1;
        hexagonaldipyramid1.position.x = 0;
        hexagonaldipyramid1.position.y = 0;
        hexagonaldipyramid1.position.z = 0;
        decagonalprism1.position.x = 0;
        decagonalprism1.position.y = 0;
        decagonalprism1.position.z = 0;
        undecagonalpyramid1.position.x = 0;
        undecagonalpyramid1.position.y = 0;
        undecagonalpyramid1.position.z = 0;
        cam_x1 = 0;
        cam_y1 = 0;
        cam_z1 = 0;
        cam_x = 0;
        cam_y = 0;
        cam_z = 0;
        camera_rotation_angle += 1;
        // rotate_cam = false;
    }
    if(position_1 == true)
    {
        cam_x1 = hexagonaldipyramid1.position.x;
        cam_y1 = hexagonaldipyramid1.position.y;
        cam_z1 = hexagonaldipyramid1.position.z;
        cam_x1 = decagonalprism1.position.x;
        cam_y1 = decagonalprism1.position.y;
        cam_z1 = decagonalprism1.position.z;
        cam_x1 = undecagonalpyramid1.position.x;
        cam_y1 = undecagonalpyramid1.position.y;
        cam_z1 = undecagonalpyramid1.position.z;
        cam_x = -2;
        cam_y = -2;
        cam_z = -2;
        position_1 = false;
    }
    if(position_2 == true)
    {
        cam_x1 = hexagonaldipyramid1.position.x;
        cam_y1 = hexagonaldipyramid1.position.y;
        cam_z1 = hexagonaldipyramid1.position.z;
        cam_x1 = decagonalprism1.position.x;
        cam_y1 = decagonalprism1.position.y;
        cam_z1 = decagonalprism1.position.z;
        cam_x1 = undecagonalpyramid1.position.x;
        cam_y1 = undecagonalpyramid1.position.y;
        cam_z1 = undecagonalpyramid1.position.z;
        cam_x = 1.5;
        cam_y = -2;
        cam_z = -1;
        position_2 = false;
    }
    if(position_3 == true)
    {
        cam_x1 = hexagonaldipyramid1.position.x;
        cam_y1 = hexagonaldipyramid1.position.y;
        cam_z1 = hexagonaldipyramid1.position.z;
        cam_x1 = decagonalprism1.position.x;
        cam_y1 = decagonalprism1.position.y;
        cam_z1 = decagonalprism1.position.z;
        cam_x1 = undecagonalpyramid1.position.x;
        cam_y1 = undecagonalpyramid1.position.y;
        cam_z1 = undecagonalpyramid1.position.z;
        cam_x = 2;
        cam_y = 2;
        cam_z = 2;
        position_3 = false;
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    hexagonaldipyramid1 = Hexagonaldipyramid(0, 0, COLOR_RED);
    axes1 = Axes(0, 0, COLOR_BLACK);
    undecagonalpyramid1 = Undecagonalpyramid(0, 0, COLOR_RED);
    decagonalprism1 = Decagonalprism(0, 0, COLOR_RED);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow(window, width, height);

    // Background color of the scene
    glClearColor(COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main(int argc, char **argv)
{
    srand(time(0));
    int width = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL(window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window))
    {
        // Process timers

        if (t60.processTick())
        {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b)
{
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen()
{
    float top = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left = screen_center_x - 4 / screen_zoom;
    float right = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
