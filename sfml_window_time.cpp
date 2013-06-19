
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
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML Time");

    // Disable vertical synchronization to get maximum framerate
    App.setVerticalSyncEnabled(false);

    // Create a clock for measuring time
    sf::Clock Clock;

    // Some dummy variables to simulate an object that moves
    const float Speed = 50.f;
    float Left = 0.f;
    float Top  = 0.f;

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

        // Get elapsed time since last frame (we could as well use App.GetFrameTime())
        float ElapsedTime = Clock.getElapsedTime().asSeconds ();
        Clock.restart();

        // Make our virtual object move
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  Left -= Speed * ElapsedTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) Left += Speed * ElapsedTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    Top  -= Speed * ElapsedTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  Top  += Speed * ElapsedTime;

        // Display window on screen
        App.display();
    }

    return EXIT_SUCCESS;
}
