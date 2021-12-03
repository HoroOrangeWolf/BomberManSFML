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
    HealthBar::loadHealthTextureFromFile("images/heart.png");
    GameMenu menu(engine.getWindow());

    
    Button bt = menu.run();

    if (bt == Button::PLAY_BUTTON)
        std::cout << "PLayButton\n";

    if (bt == Button::EXIT_BUTTON)
        std::cout << "ExitButton\n";

    SoundModule::SoundModule sounds;

    sounds.loadSounds();
    sounds.play(SoundModule::SOUNDS::CLICK);

    Player player1, player2;

    HealthBar health(sf::Vector2f(0.f, 0.f), 3);
    health.setDrawDirection(Direction::LEFT);

    player2.setHealthBar(health);

    player1.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, -0.1f)));

    player1.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::S, sf::Vector2f(0.f, 0.1f)));

    player1.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::A, sf::Vector2f(-0.1f, 0.f)));

    player1.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::D, sf::Vector2f(0.1f, 0.f)));
    player1.setPlaceBomb(sf::Keyboard::Space);

    player2.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Up, sf::Vector2f(0.f, -0.1f)));

    player2.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Down, sf::Vector2f(0.f, 0.1f)));

    player2.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Left, sf::Vector2f(-.1f, 0.f)));

    player2.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Right, sf::Vector2f(0.1f, 0.f)));

    GameMap gameMap = GameMap::loadMapFromFile("maps/map.txt");;
    
    engine.setGameMap(gameMap);
    engine.addPlayer(player1);
    engine.addPlayer(player2);


    engine.run();
    

    return 0;
}