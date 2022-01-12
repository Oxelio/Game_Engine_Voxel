# pragma once

#include "window.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>
#include <unordered_set>
#include <cstring>
#include <set>

namespace engine{
    class Device
    {
    private:
        VkInstance instance;
    
    public:
        #ifdef NDEBUG
            const bool enableValidationLayers = false;
        #else
            const bool enableValidationLayers = true;
        #endif

        Device();
        ~Device();

        void createInstance();
        std::unordered_set<std::string> glfwAvailableInstanceExtensions();
        std::vector<const char *> glfwRequiredInstanceExtensions(std::unordered_set<std::string> available);
    };
}