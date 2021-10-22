#include "GameEngine.h"
#include <chrono>

void GameEngine::setBackGroundColor(Color color)
{
	this->color = color;
}

GameEngine::GameEngine(std::string title, int width, int height)
{
	window = new RenderWindow(sf::VideoMode(width, height), "SFML");
}

void GameEngine::setPlayer1(Player& player)
{
    player1 = &player;
}

auto GameEngine::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void GameEngine::setPlayer2(Player& player)
{
    player2 = &player;
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


        window->clear();
        map->drawMap(window);
        Vector2f nextMove = map->calculatePlayerMovement(player1);
        player1->moveBy(nextMove);
        player1->drawPlayer(map->getSingleElementWidth(), map->getSingleElementHeight(),window);
        window->display();
    }
}
