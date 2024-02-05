#include "iostream"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

int WIDTH = 800;
int HEIGHT = 800;

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void errorCallback(int error, const char* description);

int main() {
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit()) {
        std::cerr << "Failed to initialize glfw." << std::endl;
        return EXIT_FAILURE;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Tutorial 1", nullptr, nullptr);
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

    // Write a while loop that shows the window
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    std::cout << "Width: " << width << ", Height: " << height << std::endl;
}

void errorCallback(int error, const char* description){
    std::cerr << "GLFW Error: " << description << std::endl;
}