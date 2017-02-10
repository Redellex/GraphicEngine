#pragma once

#include <vector>
#include <time.h>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "camera.h"
#include "SnakeUtility.h"

#ifndef SNAKE3D_SNAKEGAME_H
#define SNAKE3D_SNAKEGAME_H


class SnakeGame {

    std::vector<glm::vec3> cubeBoardPosition;
    glm::vec3 foodPosition = {0, 0, -6.0f};
    glm::vec3 OldFoodPosition;
    GLboolean isFood = false;

    //Player position stuff
    glm::vec2 player_vector;
    glm::vec3 playerPosition = {0, 0, -6.0f};
    std::vector<glm::vec3> tailPosition;
    GLint tailCount = 0;

    //Control stuff
    static Camera *camera;
    static bool keys[1024];
    static bool firstMouse;

    static GLfloat lastX;
    static GLfloat lastY;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

public:

    SnakeGame(GLFWwindow* window);
    void HandlePlayerMovement(GLfloat deltaTime);
    void UpdateGamePositions();
    void PlaceFood();
    void GenerateBoardPosition();

    std::vector<glm::vec3> GetBoardPosition() {
      return cubeBoardPosition;
    };

    std::vector<glm::vec3> GetTailPosition(){
        return tailPosition;
    };

    glm::vec3 GetPlayerPosition() {
      return playerPosition;
    };

    glm::vec3 GetFoodPosition(){
        return foodPosition;
    }

    Camera *GetCamera(){
        return camera;
    }
};

#endif //SNAKE3D_SNAKEGAME_H
