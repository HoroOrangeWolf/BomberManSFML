#include "GameEngine.h"
#include <chrono>
#include "Bomb.h"
#include <iostream>
#include "HealthBar.h"
#include "EndGameScreen.h"

GameEngine::GameEngine(std::string title, int width, int height)
{
	window = new RenderWindow(sf::VideoMode(width, height), "SFML");
}

void GameEngine::addPlayer(Player& player)
{
    playerList.push_back(&player);
}


auto GameEngine::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void GameEngine::clearPlayers()
{
    playerList.clear();
}

void GameEngine::setFps(int fps)
{
    this->fps = fps;
}

void GameEngine::setGameMap(GameMap& map)
{
	this->map = &map;
}

void GameEngine::run()
{
    auto lastFrame = getCurrentTime();
    int fpsInterval = 1000 / fps;

    texture.loadFromFile("images/map_background.png");
    shape.setTexture(&texture);
    shape.setPosition(0, 0);

    for (int i = 0; i < playerList.size(); ++i) {
        playerList[i]->initAnimation();
        map->addPlayer(*playerList[i]);
    }

    map->setUpPlayers(window);

    while (window->isOpen())
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            
        }


        auto currentFrame = getCurrentTime();

        if ((currentFrame - lastFrame) < fpsInterval)
            continue;

        lastFrame = getCurrentTime();

        if (!map->gameCycle(window))
            return;

        window->clear();
        shape.setSize(sf::Vector2f(window->getSize()));
        window->draw(shape);
        map->drawMap(window);

        for (int i = 0; i < playerList.size(); ++i) {
            playerList[i]->animate();
            playerList[i]->drawPlayer(map->getSingleElementWidth(), map->getSingleElementHeight(), window);
        }

        window->display();
    }
}

RenderWindow* GameEngine::getWindow()
{
    return window;
}
