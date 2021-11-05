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

    /*sf::Font font;

    font.loadFromFile("font/consola.ttf");

    sf::Text text;

    text.setFont(font);
    text.setString("Dziala");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Green);

    text.setPosition(sf::Vector2f(150.f, 150.f));

    */

    auto lastFrame = getCurrentTime();
    int fpsInterval = 1000 / fps;
    Bomb bomb;

    bomb.setX(4);
    bomb.setY(4);
#

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
        Vector2f nextMove = map->calculatePlayerMovement(player1);

        if (player1->isCanPlaceBomb()) {
            map->addBomb(&bomb);
        }

        player1->moveBy(nextMove);
        player1->drawPlayer(map->getSingleElementWidth(), map->getSingleElementHeight(),window);



        //window->draw(text);
        window->display();
    }
}

RenderWindow* GameEngine::getWindow()
{
    return window;
}
