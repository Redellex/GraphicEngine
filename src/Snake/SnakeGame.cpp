#include "SnakeGame.h"

// static initialization
GLfloat SnakeGame::lastX = 800 / 2.0;
GLfloat SnakeGame::lastY = 600 / 2.0;
Camera *SnakeGame::camera = new Camera();
bool SnakeGame::firstMouse = true;
bool SnakeGame::keys[1024];

SnakeGame::SnakeGame(GLFWwindow* window) {
    firstMouse = true;
    glfwSetKeyCallback(window, this->key_callback);
    glfwSetCursorPosCallback(window, this->mouse_callback);
    GenerateBoardPosition();
}

void SnakeGame::UpdateGamePositions() {
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

    //Handle food logic.
    PlaceFood();
    if (playerPosition.x == foodPosition.x && playerPosition.y == foodPosition.y)
    {
        tailCount++;
        isFood = false;
        PlaceFood();
    }
}

void SnakeGame::HandlePlayerMovement(GLfloat deltaTime) {
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

void SnakeGame::PlaceFood() {
    if(!isFood){
        auto oldFoodPosition = foodPosition;
        while(oldFoodPosition == foodPosition){
            srand( time( NULL ) );
            foodPosition.x = rand() %13 -7;
            srand( time( NULL ) );
            foodPosition.y = rand() %12 -7;
        }
        isFood = true;
    }
}

void SnakeGame::GenerateBoardPosition()
{
    for(float i = 0; i < 14; i++)
    {
        for(float j =0; j< 14; j++)
        {
            cubeBoardPosition.push_back(glm::vec3( i-7,  j-7,  -7.0f));
        }
    }
}

void SnakeGame::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if(action == GLFW_PRESS)
        keys[key] = true;
    else if(action == GLFW_RELEASE)
        keys[key] = false;
}

void SnakeGame::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
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