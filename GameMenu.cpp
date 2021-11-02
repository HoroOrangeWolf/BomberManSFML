#include "GameMenu.h"
#include "GameEngine.h"
#include <chrono>

GameMenu::GameMenu(sf::RenderWindow* window)
{
	this->window = window;
}

auto GameMenu::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int GameMenu::run()
{
    auto lastFrame = getCurrentTime();
    int fpsInterval = 1000 / 60;

    background.setPosition(0, 0);
    playButton.setPosition(250, 200);
    exitButton.setPosition(250, 300);
    //background.setFillColor(sf::Color::Green);

    if (!this->texture.loadFromFile("images/bg.jpg"))
    {
        throw "Error ladowania tekstury tla!";
    }

    this->background.setTexture(&this->texture);

    playButton.setFillColor(sf::Color{80,80,80,180});
    exitButton.setFillColor(sf::Color{100,100,100,180});

    sf::Font font;
    font.loadFromFile("font/consola.ttf");
    sf::Text textPlay;
    textPlay.setFont(font);
    textPlay.setString("Play");
    textPlay.setCharacterSize(30);
    textPlay.setFillColor(sf::Color{255,255,255,200});
    textPlay.setPosition(sf::Vector2f(300.f, 200.f));

    sf::Text textQuit;
    textQuit.setFont(font);
    textQuit.setString("Quit");
    textQuit.setCharacterSize(30);
    textQuit.setFillColor(sf::Color{ 255,255,255,200 });
    textQuit.setPosition(sf::Vector2f(300.f, 300.f));

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

        this->background.setSize(
            sf::Vector2f(
                static_cast<float>(window->getSize().x),
                static_cast<float>(window->getSize().y)
            )
        );
        
        this->playButton.setSize(sf::Vector2f(200.f, 50.f));
        this->exitButton.setSize(sf::Vector2f(200.f, 50.f));

        window->clear();
        window->draw(background);
        window->draw(playButton);
        window->draw(exitButton);
        window->draw(textPlay);
        window->draw(textQuit);
        window->display();
    }
	return 0;
}
