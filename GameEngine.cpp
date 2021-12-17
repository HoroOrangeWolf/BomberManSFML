#include "GameEngine.h"
#include <chrono>
#include "Bomb.h"
#include <iostream>
#include "HealthBar.h"
#include "EndGameScreen.h"

/**
 * .
 * \brief Konstruktor silnika gry
 * \param title Tytul
 * \param width Szerokosc
 * \param height Wysokosc
 */
GameEngine::GameEngine(std::string title, int width, int height)
{
	window = new RenderWindow(sf::VideoMode(width, height), "SFML", sf::Style::Close);
}

/**
 * .
 * \brief Dodanie gracza
 * \param player Gracz
 */
void GameEngine::addPlayer(Player& player)
{
    playerList.push_back(&player);
}

/**
 * .
 * \brief Pobiera obeczny czas
 * \return Zwraca obecny czas
 */
auto GameEngine::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * .
 * \brief Usuwa graczy
 */
void GameEngine::clearPlayers()
{
    playerList.clear();
}

/**
 * .
 * \brief Ustawia ilosc FPS
 * \param fps FPS
 */
void GameEngine::setFps(int fps)
{
    this->fps = fps;
}

/**
 * .
 * \brief Ustawia mape gry
 * \param map Mapa
 */
void GameEngine::setGameMap(GameMap& map)
{
	this->map = &map;
}

/**
 * .
 * \brief Glowna petla gry
 */
void GameEngine::run()
{
    auto lastFrame = getCurrentTime();
    int fpsInterval = 1000 / fps;

    if (!texture.loadFromFile("images/map_background.png"))
        Logger::log("Nie udalo sie zaladowac font consola");

    shape.setTexture(&texture);
    shape.setPosition(0, 0);

    for (int i = 0; i < playerList.size(); ++i) {
        playerList[i]->initAnimation();
        playerList[i]->setHealth(3);
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

/**
 * .
 * \brief Zwraca wskaznik na okno
 * \return 
 */
RenderWindow* GameEngine::getWindow()
{
    return window;
}
