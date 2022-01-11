#include "window.hpp"

namespace engine {
    Window::Window(int w, int h, const char* name) : width{w}, height{h}, window_name{name}
    {
        initWindow(width,height,window_name);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::initWindow(int width, int height, const char* name){
        glfwInit(); // Initialisation de GLFW

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // On n'utilise pas OpenGL
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // On ne peut pas redimensionner

        window = glfwCreateWindow(width, height, "Owedia Engine", nullptr, nullptr);
    }

    bool Window::shouldClose(){
        return glfwWindowShouldClose(window);
    }
}