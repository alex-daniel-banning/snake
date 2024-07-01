#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Shader.h"
#include "Game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glEnable(GL_DEPTH_TEST);


	Shader shader("C:\\Users\\banni\\source\\repos\\snake\\snake\\resources\\shaders\\basic.vs",
		"C:\\Users\\banni\\source\\repos\\snake\\snake\\resources\\shaders\\basic.fs");
    shader.use();
    shader.setVec4("color", 1.0f, 1.0f, 1.0f, 1.0f);
    Game game;
    game.initialize();

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        game.render(shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}