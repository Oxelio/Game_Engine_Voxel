/*
        Game Engine en Voxel

        Nom : Owedia
        Auteur : Wiplier Stephen

        Bonne pratiques :
        class : Class
        fonction : fonctionFonction
        variable : variable_variable

*/

// Libraries

# include <vulkan/vulkan.h>
# include <iostream>
# include <stdexcept>

# include "application.hpp"

// Fonction principale

int main() {

    engine::Application owedia_appli;

    try {
        owedia_appli.run(); // On test si l'appli se lance
    } 
    catch (const std::exception& error) 
    {
        std::cerr << error.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}