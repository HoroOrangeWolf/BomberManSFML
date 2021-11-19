#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "StaticBlock.h"
#include "GameEngine.h"
#include "SoundModule.h"
#include "GameMenu.h"
#include <iostream>

int main()
{
    GameEngine engine("Sfml", 700, 700);
    GameMenu menu(engine.getWindow());
    
    Button bt = menu.run();

    if (bt == Button::PLAY_BUTTON)
        std::cout << "PLayButton\n";

    if (bt == Button::EXIT_BUTTON)
        std::cout << "ExitButton\n";

    SoundModule::SoundModule sounds;

    sounds.loadSounds();
    sounds.play(SoundModule::SOUNDS::CLICK);

    Player player;

    player.setUp(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::W, sf::Vector2f(0.f, -0.1f)));

    player.setDown(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::S, sf::Vector2f(0.f, 0.1f)));

    player.setLeft(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::A, sf::Vector2f(-0.1f, 0.f)));

    player.setRight(std::pair<sf::Keyboard::Key, sf::Vector2f>(sf::Keyboard::D, sf::Vector2f(0.1f, 0.f)));
    player.setPlaceBomb(sf::Keyboard::Space);

    GameMap gameMap(10, 10);
    
  

    gameMap.setElement(3, 3, new StaticBlock());
    gameMap.setElement(5, 3, new StaticBlock());
    gameMap.setElement(3, 1, new StaticBlock());
    gameMap.setElement(5, 1, new StaticBlock());

    engine.setGameMap(gameMap);
    engine.setPlayer1(player);


    engine.run();
    

    return 0;
}