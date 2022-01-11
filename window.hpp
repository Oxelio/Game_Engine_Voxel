# pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace engine{
    class Window
    {
    private:
        const int width;
        const int height;
        const char* window_name;

        GLFWwindow* window;

    public:
        Window(int w, int h, const char* name);
        ~Window();

        // Eviter les doublons
        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        void initWindow(int width, int height, const char* name);
        bool shouldClose();
    };
}