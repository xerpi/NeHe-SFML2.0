
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
    sf::Window App(sf::VideoMode(800, 600, 32), "SFML OpenGL");

    // Create a clock for measuring time elapsed
    sf::Clock Clock;

    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);

    // Start game loop
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

            // Resize event : adjust viewport
            if (Event.type == sf::Event::Resized)
                glViewport(0, 0, Event.size.width, Event.size.height);
        }

        // Set the active window before using OpenGL commands
        // It's useless here because active window is always the same,
        // but don't forget it if you use multiple windows or controls
        App.setActive();

        // Clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(Clock.getElapsedTime().asSeconds () * 50, 1.f, 0.f, 0.f);
        glRotatef(Clock.getElapsedTime().asSeconds () * 30, 0.f, 1.f, 0.f);
        glRotatef(Clock.getElapsedTime().asSeconds () * 90, 0.f, 0.f, 1.f);

        // Draw a cube
        glBegin(GL_QUADS);

            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f( 50.f,  50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);

            glVertex3f(-50.f, -50.f, 50.f);
            glVertex3f(-50.f,  50.f, 50.f);
            glVertex3f( 50.f,  50.f, 50.f);
            glVertex3f( 50.f, -50.f, 50.f);

            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f(-50.f,  50.f, -50.f);
            glVertex3f(-50.f,  50.f,  50.f);
            glVertex3f(-50.f, -50.f,  50.f);

            glVertex3f(50.f, -50.f, -50.f);
            glVertex3f(50.f,  50.f, -50.f);
            glVertex3f(50.f,  50.f,  50.f);
            glVertex3f(50.f, -50.f,  50.f);

            glVertex3f(-50.f, -50.f,  50.f);
            glVertex3f(-50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f, -50.f);
            glVertex3f( 50.f, -50.f,  50.f);

            glVertex3f(-50.f, 50.f,  50.f);
            glVertex3f(-50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f, -50.f);
            glVertex3f( 50.f, 50.f,  50.f);

        glEnd();

        // Finally, display rendered frame on screen
        App.display();
    }

    return EXIT_SUCCESS;
}
