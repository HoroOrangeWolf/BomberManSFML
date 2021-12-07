#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "StaticBlock.h"
#include "GameEngine.h"
#include "SoundModule.h"
#include "GameMenu.h"
#include "Chest.h"
#include <iostream>
#include "BitmapHandler.h"

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


    SoundModule::SoundModule::loadSounds();

    Player player1, player2;

    sf::Image ims[] = { BitmapHandler::getImageFromFile("images/playerFrames/13.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/14.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/15.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/16.png")
    };

    player1.setFramesFront(ims, 4);
    player2.setFramesFront(ims, 4);


    sf::Image ims1[] = { BitmapHandler::getImageFromFile("images/playerFrames/9.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/10.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/11.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/12.png")
    };

    player1.setFramesBack(ims1, 4);
    player2.setFramesBack(ims1, 4);

    sf::Image ims2[] = {
        BitmapHandler::getImageFromFile("images/playerFrames/1.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/2.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/3.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/4.png")
    };

    player1.setFramesRight(ims2, 4);
    player2.setFramesRight(ims2, 4);

    sf::Image ims3[] = { BitmapHandler::getImageFromFile("images/playerFrames/5.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/6.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/7.png"),
        BitmapHandler::getImageFromFile("images/playerFrames/8.png")
    };

    player1.setFramesLeft(ims3, 4);
    player2.setFramesLeft(ims3, 4);

    HealthBar health(sf::Vector2f(0.f, 0.f), 3);
    health.setDrawDirection(Direction::LEFT);

    player2.setHealthBar(health);

    player1.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, -3.5f)));

    player1.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::S, sf::Vector2f(0.f, 3.5f)));

    player1.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::A, sf::Vector2f(-3.5f, 0.f)));

    player1.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::D, sf::Vector2f(3.5f, 0.f)));
    player1.setPlaceBomb(sf::Keyboard::Space);

    player2.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Up, sf::Vector2f(0.f, -3.5f)));

    player2.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Down, sf::Vector2f(0.f, 3.5f)));

    player2.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Left, sf::Vector2f(-3.5f, 0.f)));

    player2.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::Right, sf::Vector2f(3.5f, 0.f)));

    player2.setPlaceBomb(sf::Keyboard::RControl);

    GameMap gameMap = GameMap::loadMapFromFile("maps/map.txt");;
    
    engine.setGameMap(gameMap);
    engine.addPlayer(player1);
    engine.addPlayer(player2);


    engine.run();
    

    return 0;
}