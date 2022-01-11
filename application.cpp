# include "application.hpp"

namespace engine {
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::run(){
        while (!owedia_window.shouldClose())
        {
            glfwPollEvents();
        }
    }
}