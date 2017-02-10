#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <shader.h>
#include <cube.h>

#include "SnakeGame.h"
#include "SnakeUtility.h"

int main(){
    int width, height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Snake3D demo v1.0 by Pawel Sobocinski", 0, nullptr);
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

    SnakeGame game(window);


    glEnable(GL_DEPTH_TEST);

    Cube cube;
    cube.SendToMemory();
    int nbFrames = 0;
    float lastTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    while(!glfwWindowShouldClose(window)) {
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 projection;
        GLfloat currentFrame = glfwGetTime();
        auto deltaTime = currentFrame - lastFrame;

        lastFrame = currentFrame;
        nbFrames++;
        glfwPollEvents();
        game.HandlePlayerMovement(deltaTime);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (currentFrame - lastTime >= 0.5){
            lastTime += 0.5;
            game.UpdateGamePositions();
        }
        //Board
        cube.ActivateShader();
        view = game.GetCamera()->GetViewMatrix();
        projection = glm::perspective(glm::radians(45.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);

        glBindVertexArray(cube.GetVAO());
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        cube.SetColor(glm::vec3(1.0f, 0.5f, 0.0f));
        for (glm::vec3 board_cube_pos: game.GetBoardPosition()){
            //Board Rendering
            cube.Render(model, view, projection, board_cube_pos, 0.0f);
        }

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        //Player Rendering
        cube.SetColor(glm::vec3(0.0f, 0.0f, 1.0f));
        cube.Render(model, view, projection,game.GetPlayerPosition(), 0.0f);

        //Food Rendering
        cube.SetColor(glm::vec3(0.0f, 1.5f, 1.0f));
        cube.Render(model, view, projection, game.GetFoodPosition(), 0.0f);

        //Tail Rendering
        cube.SetColor(glm::vec3(5.0f, 0.9f, 0.3f));
        for(auto tail_pos: game.GetTailPosition()){
            cube.Render(model, view, projection, tail_pos, 0.0f);
        }
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}