#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "StaticBlock.h"
#include "GameEngine.h"

int main()
{
    GameEngine engine("Sfml", 700, 700);

    Player player;

    player.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, -0.1f)));
    player.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::S, sf::Vector2f(0.f, 0.1f)));
    player.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::A, sf::Vector2f(-0.1f, 0.f)));
    player.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::D, sf::Vector2f(0.1f, 0.f)));

    GameMap gameMap(10, 10);
    
    gameMap.setElement(3, 3, new StaticBlock());

    engine.setGameMap(gameMap);
    engine.setPlayer1(player);

    engine.run();
    

    return 0;
}