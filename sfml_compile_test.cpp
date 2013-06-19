#include <SFML/System.hpp>
#include <iostream>

int main()
{
    sf::Clock Clock;
    while (Clock.getElapsedTime().asSeconds () < 5.f)
    {
        std::cout << Clock.getElapsedTime().asSeconds () << std::endl;
        sf::sleep(sf::seconds(0.5f));
    }

    return 0;
}
