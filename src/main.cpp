#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
//GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
//other
#include "shader.h"
#include "camera.h"
#include "cube.h"
#include <SOIL.h>
#include <unistd.h>


struct player_mv{
    int x, y;
};

player_mv player_vector = {0, 0};

Camera *camera = new Camera();
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

GLfloat lastX  =  800/ 2.0;
GLfloat lastY  =  600 / 2.0;

glm::vec3 playerPosition = glm::vec3(0.0f,  0.0f,  -19.0f);

bool keys[1024];

using namespace std;

const GLuint WIDTH = 800, HEIGHT = 600;


bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to left
    lastX = xpos;
    lastY = ypos;

    camera->ProcessMouseMovement(xoffset, yoffset);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if(action == GLFW_PRESS)
        keys[key] = true;
    else if(action == GLFW_RELEASE)
        keys[key] = false;
}

void do_movement()
{
    if(keys[GLFW_KEY_W])
        camera->ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
    if(keys[GLFW_KEY_S])
        camera->ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
    if(keys[GLFW_KEY_A])
        camera->ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
    if(keys[GLFW_KEY_D])
        camera->ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
    if(keys[GLFW_KEY_UP]) {
        player_vector.y = 1;
        player_vector.x = 0;
    }
    if(keys[GLFW_KEY_LEFT]) {
        player_vector.x = -1;
        player_vector.y = 0;
    }
    if(keys[GLFW_KEY_RIGHT]) {
        player_vector.x = 1;
        player_vector.y = 0;
    }
    if(keys[GLFW_KEY_DOWN]) {
        player_vector.y = -1;
        player_vector.x = 0;
    }
}

void texture_parameters()
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void generate_board_vector_xy(std::vector<glm::vec3> cubeBoardPosition)
{
    cubeBoardPosition.reserve(7*7);
    for(float i = 0; i < 7; i++)
    {
        for(float j =0; j< 7; j++)
        {
            cubeBoardPosition.push_back(glm::vec3( i,  j,  0.0f));
        }
    }
}

int main() {
    int width, height;
    bool isFood = false;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", 0, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }


    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, WIDTH, HEIGHT);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    Shader base_shader("/home/sysop/Snake3D/shaders/VertexShader", "/home/sysop/Snake3D/shaders/FragmentShader");
    Shader board_shader("/home/sysop/Snake3D/shaders/VertexBoardShader", "/home/sysop/Snake3D/shaders/FragmentBoardShader");
    Shader food_shader("/home/sysop/Snake3D/shaders/VertexBoardShader", "/home/sysop/Snake3D/shaders/FragmentYellowShader");
    Shader tail_shader("/home/sysop/Snake3D/shaders/VertexBoardShader", "/home/sysop/Snake3D/shaders/FragmentGreenShader");

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);


    int twidth, theight;
    unsigned char* image = SOIL_load_image("/home/sysop/Snake3D/resources/textures/awesomeface.png", &twidth, &theight, 0, SOIL_LOAD_RGB);

    glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    std::vector<glm::vec3> cubeBoardPosition;
    std::vector<glm::vec3> tailPosition;
    GLint tailCount = 0;
    glm::vec3 foodPosition = {0, 0, -16.0f};
    generate_board_vector_xy(cubeBoardPosition);


    for(float i = -7; i < 7; i++)
    {
        for(float j =-7; j< 7; j++)
        {
            cubeBoardPosition.push_back(glm::vec3( i,  j,  -17.0f));
        }
    }


    glEnable(GL_DEPTH_TEST);

    Cube object_1;
    object_1.Texture(image, twidth, theight);
    object_1.SendToMemory();
    int nbFrames = 0;
    float lastTime = 0.0f;

    while(!glfwWindowShouldClose(window)) {
        GLfloat currentFrame = glfwGetTime();
        nbFrames++;
        if ( currentFrame - lastTime >= 0.5 ){ // If last prinf() was more than 1 sec ago
            // printf and reset timer
           printf("%f ms/frame\n", 1000.0/double(nbFrames));
            printf("%f fps\n", nbFrames*1000/(currentFrame - lastTime));
            nbFrames = 0;
            lastTime += 0.5;
            if (playerPosition.x < -7)
            {
                player_vector.x = 0;
                player_vector.y = 0;
            }
            if(playerPosition.x > 6)
            {
                player_vector.x = 0;
                player_vector.y = 0;
            }

            if (playerPosition.y < -7)
            {
                player_vector.x = 0;
                player_vector.y = 0;
            }
            if (playerPosition.y > 6)
            {
                player_vector.x = 0;
                player_vector.y = 0;
            }
            if (tailPosition.size() != tailCount) {
                glm::vec3 value;
                auto vector_size = tailPosition.size() - 1;
                if (!vector_size){
                    value = tailPosition[vector_size];
                }
                else {
                    value = playerPosition;
                }
                value.x = value.x - player_vector.x;
                value.y = value.y - player_vector.y;
                tailPosition.push_back(value);
            }

            //Handle tail Positions.
            for (int i = tailPosition.size()-1; i >= 1; i--)
            {
                tailPosition[i] = tailPosition[i-1];
                if(tailPosition[i].x ==playerPosition.x && tailPosition[i].y == playerPosition.y)
                {
                    player_vector.x = 0;
                    player_vector.y = 0;
                }
            }
            if(tailPosition.size() >= 1){
                tailPosition[0] = playerPosition;
            }

            playerPosition.x += player_vector.x;
            playerPosition.y += player_vector.y;
        }
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();
        do_movement();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        base_shader.Use();
        glActiveTexture(GL_TEXTURE0);
        texture_parameters();
        glBindTexture(GL_TEXTURE_2D, object_1.GetTexture());
        glUniform1i(glGetUniformLocation(base_shader.Program, "ourTexture1"), 0);
        glActiveTexture(GL_TEXTURE1);
        glUniform1f(glGetUniformLocation(base_shader.Program, "value"), 0.6f);

        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 projection;
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view = camera->GetViewMatrix();
        projection = glm::perspective(glm::radians(45.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);

        // Get their uniform location
        GLint modelLoc = glGetUniformLocation(base_shader.Program, "model");
        GLint viewLoc = glGetUniformLocation(base_shader.Program, "view");
        GLint projLoc = glGetUniformLocation(base_shader.Program, "projection");

        // Pass them to the shaders
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(object_1.GetVAO());

       for(GLuint i = 0; i < 1; i++)
        {
            glm::mat4 model;
            model = glm::translate(model, playerPosition);
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            object_1.Render();
        }

        board_shader.Use();

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        GLint modelBoardLoc = glGetUniformLocation(board_shader.Program, "model");
        GLint viewBoardLoc = glGetUniformLocation(board_shader.Program, "view");
        GLint projBoardLoc = glGetUniformLocation(board_shader.Program, "projection");

        glUniformMatrix4fv(modelBoardLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewBoardLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projBoardLoc, 1, GL_FALSE, glm::value_ptr(projection));

        for(GLuint i = 0; i < cubeBoardPosition.size(); i++)
        {
            glm::mat4 model;
            model = glm::translate(model, cubeBoardPosition[i]);
            model = glm::translate(model, glm::vec3(0.0, 0.0, -3.0f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            object_1.Render();
        }
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        food_shader.Use();
        GLint modelFoodLoc = glGetUniformLocation(food_shader.Program, "model");
        GLint viewFoodLoc = glGetUniformLocation(food_shader.Program, "view");
        GLint projFoodLoc = glGetUniformLocation(food_shader.Program, "projection");

        glUniformMatrix4fv(modelFoodLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewFoodLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projFoodLoc, 1, GL_FALSE, glm::value_ptr(projection));
        {
            glm::mat4 model;
            if(!isFood)
            {
                auto oldFoodPosition = foodPosition;
                while(oldFoodPosition == foodPosition){
                 srand( time( NULL ) );
                 foodPosition.x = rand() %13 -7;
                 srand( time( NULL ) );
                 foodPosition.y = rand() %12 -7;
                }
                isFood = true;
            }
            model = glm::translate(model, foodPosition);
            model = glm::translate(model, glm::vec3(0.0, 0.0, -3.0f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            object_1.Render();
            if (playerPosition.x == foodPosition.x && playerPosition.y == foodPosition.y)
            {
                isFood = false;
                tailCount++;
            }
        }


        tail_shader.Use();
        GLint modelTailLoc = glGetUniformLocation(tail_shader.Program, "model");
        GLint viewTailLoc = glGetUniformLocation(tail_shader.Program, "view");
        GLint projTailLoc = glGetUniformLocation(tail_shader.Program, "projection");

        glUniformMatrix4fv(modelTailLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewTailLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projTailLoc, 1, GL_FALSE, glm::value_ptr(projection));

        for(GLuint i = 0; i < tailPosition.size(); i++)
        {
            glm::mat4 model;
            model = glm::translate(model, tailPosition[i]);
            //model = glm::translate(model, glm::vec3(0.0, 0.0, -3.0f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            object_1.Render();
        }

        //tailPosition
        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }
    //glDeleteBuffers(1, object_1.GetVBO());
   // glDeleteBuffers(1, &EBO);
   // glDeleteBuffers(1, &VAO);
    glfwTerminate();
    delete camera;
    return 0;
}