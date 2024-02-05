#include "iostream"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 800;


void framebufferSizeCallback(GLFWwindow *window,int width, int height);
void processInputs(GLFWwindow *window);

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize glfw." << std::endl;
        return EXIT_FAILURE;
    }
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tutorial 2", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create window." << std::endl;
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        std::cerr << "Failed to initialize GLAD." << std::endl;
        return EXIT_FAILURE;
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    while(!glfwWindowShouldClose(window)) {
        processInputs(window);
        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    std::cout << "Width: " << width << ", Height: " << height << std::endl;
}

void processInputs(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
