#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include "shaders.hpp"
#include "log.hpp"
#include <effolkronium/random.hpp>
#include "Shader.hpp"
#include "Texture.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.hpp"
#include "Cube.hpp"


#define WIDTH 1280
#define HEIGHT 720

#define SPEED 0.08f

float LastX = WIDTH / 2, LastY = HEIGHT / 2;

Camera cam({0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, -90.0f, 0.0f);

float deltaTime = 0.0, lastFrame = 0.0;

using Random = effolkronium::random_static;

void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow * window, double xpos, double ypos);

int main()
{
    // const float vertices[] = {
    // -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    //  0.5f, -0.5f, -0.5f,  0.33f, 0.0f,
    //  0.5f,  0.5f, -0.5f,  0.33f, 1.0f,
    //  0.5f,  0.5f, -0.5f,  0.33f, 1.0f,
    // -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    // -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    // -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    //  0.5f, -0.5f,  0.5f,  0.33f, 0.0f,
    //  0.5f,  0.5f,  0.5f,  0.33f, 1.0f,
    //  0.5f,  0.5f,  0.5f,  0.33f, 1.0f,
    // -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    // -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    // -0.5f,  0.5f,  0.5f,  0.33f, 0.0f,
    // -0.5f,  0.5f, -0.5f,  0.33f, 1.0f,
    // -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    // -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    // -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    // -0.5f,  0.5f,  0.5f,  0.33f, 0.0f,

    //  0.5f,  0.5f,  0.5f,  0.33f, 0.0f,
    //  0.5f,  0.5f, -0.5f,  0.33f, 1.0f,
    //  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //  0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    //  0.5f,  0.5f,  0.5f,  0.33f, 0.0f,

    // -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    //  0.5f, -0.5f, -0.5f,  0.33f, 1.0f,
    //  0.5f, -0.5f,  0.5f,  0.33f, 0.0f,
    //  0.5f, -0.5f,  0.5f,  0.33f, 0.0f,
    // -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    // -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    // -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    //  0.5f,  0.5f, -0.5f,  0.33f, 1.0f,
    //  0.5f,  0.5f,  0.5f,  0.33f, 0.0f,
    //  0.5f,  0.5f,  0.5f,  0.33f, 0.0f,
    // -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    // -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    // };
    // const GLuint indices[] = { 
    //     0, 1, 3,
    //     1, 2, 3
    // };  

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Falskcraft", NULL, NULL);
    if(window == NULL)
    {
        std::cerr << "Failded to create window" << '\n';
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << '\n';
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_DEPTH_TEST); 

    DEBUG(3+3)

    DEBUG(Random::get(-1.f, 1.f))

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cube::vertices), Cube::vertices, GL_DYNAMIC_DRAW);

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Cube::indices), Cube::indices, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1); 

    Shader basic(example_vertex_shader, example_fragment_shader);
    
    glActiveTexture(GL_TEXTURE0);
    Texture tex("pack.png");
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glm::mat4 model = glm::mat4(1.0f);
    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));


    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 100.0f);

    DEBUG(sizeof(projection))

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);

    //float time;

    while(!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        basic.use();
        basic.setMatrix("model", model);
        basic.setMatrix("view", cam.GetViewMatrix());
        basic.setMatrix("projection", projection);

        glBindVertexArray(VAO);

        //model = glm::rotate(model, glm::radians(0.86f), glm::vec3(0.5f, 1.0f, 0.0f));
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
        //LOGy("FPS: ", 1 / (glfwGetTime() - time ))
    }
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cam.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cam.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cam.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cam.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void mouse_callback(GLFWwindow * /*window*/, double xpos, double ypos)
{
    float xoffset = LastX - xpos;
    float yoffset = LastY - ypos;
    LastX = xpos;
    LastY = ypos;
    cam.ProcessMouseMovement(xoffset, yoffset);
}