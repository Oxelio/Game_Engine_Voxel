#include "device.hpp"

namespace engine {
    Device::Device()
    {
        createInstance();
    }
    
    Device::~Device()
    {
        vkDestroyInstance(instance, nullptr);
    }

    void Device::createInstance()
    {
        VkApplicationInfo app_info{};
        app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        app_info.pApplicationName = "Owedia Enfine";
        app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        app_info.pEngineName = "Owedia Engine";
        app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        app_info.apiVersion = VK_API_VERSION_1_0;

        // Les extensions disponibles
        std::unordered_set<std::string> available_extensions = glfwAvailableInstanceExtensions();

        // Les extensions requises
        auto extensions = glfwRequiredInstanceExtensions(available_extensions);

        VkInstanceCreateInfo create_info{};
        create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        create_info.pApplicationInfo = &app_info;
        create_info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        create_info.ppEnabledExtensionNames = extensions.data();
        create_info.enabledLayerCount = 0;

        VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
        if (vkCreateInstance(&create_info, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create instance!");
        }
    }

    std::unordered_set<std::string> Device::glfwAvailableInstanceExtensions(){
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        std::cout << "available extensions:" << std::endl;
        std::unordered_set<std::string> available;
        for (const auto &extension : extensions) 
        {
            std::cout << "\t" << extension.extensionName << std::endl;
            available.insert(extension.extensionName);
        }
        
        return available;
    }

    std::vector<const char *> Device::glfwRequiredInstanceExtensions(std::unordered_set<std::string> available){
        uint32_t glfwExtensionCount = 0;
        const char **glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char *> required_extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
        if (enableValidationLayers) {
            required_extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        std::cout << "required extensions:" << std::endl;
        for (const auto &required : required_extensions) 
        {
            std::cout << "\t" << required << std::endl;
            if (available.find(required) == available.end()) 
            {
                throw std::runtime_error("Missing required glfw extension");
            }
        }

        return  required_extensions;
    }
}