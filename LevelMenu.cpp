#include "LevelMenu.h"

MenuStates LevelMenu::run()
{
    auto lastFrame = getCurrentTime();
    int fpsInterval = 1000 / 60;

    background.setPosition(0, 0);
    //background.setFillColor(sf::Color::Green);

    if (!this->texture.loadFromFile("images/bg.jpg"))
    {
        throw "Error ladowania tekstury tla!";
    }

    this->background.setTexture(&this->texture);

    Button level1(sf::Vector2f(200.f, 50.f), "Level 1");
    level1.setPosition(sf::Vector2f(250.f, 200.f));

    Button level2(sf::Vector2f(200.f, 50.f), "Level 2");
    level2.setPosition(sf::Vector2f(250.f, 300.f));

    Button level3(sf::Vector2f(200.f, 50.f), "Level 2");
    level3.setPosition(sf::Vector2f(250.f, 400.f));

    Button back(sf::Vector2f(200.f, 50.f), "Level 2");
    back.setPosition(sf::Vector2f(250.f, 500.f));

    while (window->isOpen())
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (isMouseIn(level1))
                return MenuStates::LEVEL1;
            else if (isMouseIn(level2))
                return MenuStates::LEVEL2;
            else if (isMouseIn(level3))
                return MenuStates::LEVEL3;
            else if (isMouseIn(back))
                return MenuStates::BACK;
        }

        auto currentFrame = getCurrentTime();

        if ((currentFrame - lastFrame) < fpsInterval)
            continue;

        lastFrame = getCurrentTime();

        this->background.setSize(

            sf::Vector2f(
                static_cast<float>(window->getSize().x),
                static_cast<float>(window->getSize().y)
            )

        );




        window->clear();
        window->draw(background);
        level1.draw(window);
        level2.draw(window);
        level3.draw(window);
        back.draw(window);
        window->display();
    }
    return MenuStates::BACK;
}
