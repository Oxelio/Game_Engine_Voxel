# pragma once

# include "window.hpp"

namespace engine{
    class Application
    {
    private:
        Window owedia_window;
    
    public:
        // Constructeur et destructeur
        Application();
        ~Application();

        void run();
    };
}