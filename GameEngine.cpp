#include "GameEngine.h"
#include <chrono>
#include "Bomb.h"
#include <iostream>

void GameEngine::setBackGroundColor(Color color)
{
	this->color = color;
}

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
    Bomb *bomb = new Bomb();

    bomb->setX(4);
    bomb->setY(4);

    for (int i = 0; i < playerList.size(); ++i)
        map->addPlayer(*playerList[i]);

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

        map->gameCycle();

        window->clear();
        map->drawMap(window);

        for(int i = 0; i < playerList.size(); ++i)
            playerList[i]->drawPlayer(map->getSingleElementWidth(), map->getSingleElementHeight(),window);

        window->display();
    }
}

RenderWindow* GameEngine::getWindow()
{
    return window;
}
