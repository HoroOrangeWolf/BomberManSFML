#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "StaticBlock.h"
#include "GameEngine.h"
#include "SoundModule.h"
#include "GameMenu.h"
#include "Chest.h"
#include <iostream>

int main()
{
    GameEngine engine("Sfml", 700, 700);
    GameMenu menu(engine.getWindow());

    GameMap::loadMapFromFile("maps/map.txt");
    
    Button bt = menu.run();

    if (bt == Button::PLAY_BUTTON)
        std::cout << "PLayButton\n";

    if (bt == Button::EXIT_BUTTON)
        std::cout << "ExitButton\n";

    SoundModule::SoundModule sounds;

    sounds.loadSounds();
    sounds.play(SoundModule::SOUNDS::CLICK);

    Player player1, player2;

    player1.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, -0.1f)));

    player1.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::S, sf::Vector2f(0.f, 0.1f)));

    player1.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::A, sf::Vector2f(-0.1f, 0.f)));

    player1.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::D, sf::Vector2f(0.1f, 0.f)));
    player1.setPlaceBomb(sf::Keyboard::Space);

    player2.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Up, sf::Vector2f(0.f, -0.1f)));

    player2.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Down, sf::Vector2f(0.f, 0.1f)));

    player2.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Left, sf::Vector2f(-.1f, 0.f)));

    player2.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Right, sf::Vector2f(0.1f, 0.f)));

    GameMap gameMap(10, 10);
    
  

    gameMap.setElement(3, 3, new StaticBlock());
    gameMap.setElement(5, 3, new StaticBlock());
    gameMap.setElement(3, 1, new StaticBlock());
    gameMap.setElement(5, 1, new StaticBlock());
    gameMap.setElement(7, 1, new Chest(1));


    engine.setGameMap(gameMap);
    engine.addPlayer(player1);
    engine.addPlayer(player2);


    engine.run();
    

    return 0;
}