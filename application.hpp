# pragma once

# include "window.hpp"
# include "device.hpp"

namespace engine{
    class Application
    {
    private:
        Window owedia_window{800,600,"Owedia engine"};
        Device owedia_device;
    
    public:
        // Constructeur et destructeur
        Application();
        ~Application();

        void run();
    };
}