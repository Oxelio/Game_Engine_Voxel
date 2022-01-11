# pragma once

# include "window.hpp"

namespace engine{
    class Application
    {
    private:
        Window owedia_window{800,600,"Owedia engine"};
    
    public:
        // Constructeur et destructeur
        Application();
        ~Application();

        void run();
    };
}