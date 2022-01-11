# pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace engine{
    class Window
    {
    private:
        const int WIDTH = 800;
        const int HEIGHT = 600;

        GLFWwindow* window;

    public:
        Window();
        ~Window();

        void initWindow();
        bool shouldClose();
    };
}