////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    // Create the main window
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");

    // Start main loop
    bool Running = true;
    while (Running)
    {
        App.display();
    }

    return EXIT_SUCCESS;
}

