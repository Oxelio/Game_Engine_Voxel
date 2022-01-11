#include "window.hpp"

namespace engine {
    Window::Window()
    {
        initWindow();
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::initWindow(){
        glfwInit(); // Initialisation de GLFW

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // On n'utilise pas OpenGL
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // On ne peut pas redimensionner

        window = glfwCreateWindow(WIDTH, HEIGHT, "Owedia Engine", nullptr, nullptr);
    }

    bool Window::shouldClose(){
        return glfwWindowShouldClose(window);
    }
}