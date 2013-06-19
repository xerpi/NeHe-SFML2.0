
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
int main()
{
    // Create the main window
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Events");

    // Get a reference to the input manager associated to our window, and store it for later use


    // Start main loop
    while (App.isOpen())
    {
        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();

            // Escape key : exit
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
                App.close();
        }

        // Get some useless input states, just to illustrate the tutorial
        bool         LeftKeyDown     = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool         RightButtonDown = sf::Mouse::isButtonPressed(sf::Mouse::Right);
        bool         JoyButton1Down  = sf::Joystick::isButtonPressed(0, 1);
        sf::Vector2i MousePos        = sf::Mouse::getPosition(App);
        unsigned int MouseX          = MousePos.x;
        unsigned int MouseY          = MousePos.y;
        int          JoystickX       = sf::Joystick::getAxisPosition(1, sf::Joystick::Z);
        int          JoystickY       = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
        int          JoystickPOV     = sf::Joystick::getAxisPosition(1, sf::Joystick::PovX);

        // Display window on screen
        App.display();
    }

    return EXIT_SUCCESS;
}
