#include "cube.h"

Cube::Cube()
{
    ShaderCube = new Shader("/home/sysop/Snake3D/shaders/CubeVertexShader.vert", "/home/sysop/Snake3D/shaders/CubeFragmentShader.frag");
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glGenTextures(1, &texture);
}

Cube::~Cube(){
    delete(ShaderCube);
}

void Cube::Texture(unsigned char* image, int twidth, int theight)
{
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, twidth, theight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Cube::SendToMemory()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
}

void Cube::ActivateShader(){
        ShaderCube->Use();
};

void Cube::Render(glm::mat4 model, glm::mat4 view, glm::mat4 projection, glm::vec3 position, GLfloat rotation)
{


    GLint modelLoc = glGetUniformLocation(ShaderCube->Program, "model");
    GLint viewLoc = glGetUniformLocation(ShaderCube->Program, "view");
    GLint projLoc = glGetUniformLocation(ShaderCube->Program, "projection");
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
    model = glm::translate(model, position);
/*
    printf("modelLoc: %i\n", modelLoc);
    printf("viewLoc: %i\n",  viewLoc);
    printf("projlLoc: %i\n", projLoc);
*/
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glDrawArrays(GL_TRIANGLES, 0, 36);
}
//Old one.
void Cube::Render()
{
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::SetColor(glm::vec3 color) {
    GLint colorLoc = glGetUniformLocation(ShaderCube->Program, "choosenColor");
    glUniform3f(colorLoc, color.x, color.y, color.z);
}

GLuint Cube::GetVAO()
{
    return VAO;
}

GLuint Cube::GetVBO()
{
    return VBO;
}

GLuint Cube::GetTexture()
{
    return texture;
}

