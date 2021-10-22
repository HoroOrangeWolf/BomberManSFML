#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "StaticBlock.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    GameMap gameMap(10, 10);

    for(int x=0; x < 10; x++)
        for (int y = 0; y < 10; ++y)
            gameMap.setElement(x, y, new MapElement());
       

    gameMap.setElement(3, 3, new StaticBlock());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gameMap.drawMap(&window);
        window.display();
    }

    return 0;
}