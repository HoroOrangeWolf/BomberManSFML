#include "GameMenu.h"

GameMenu::GameMenu(sf::RenderWindow* window)
{
	this->window = window;
}

bool GameMenu::isMouseIn(Button& shape)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
 
    sf::Vector2f position = shape.getPosition(), size = shape.getSize();

   
    return (mousePosition.x >= position.x && mousePosition.y >= position.y && mousePosition.x <= (position.x + size.x) && mousePosition.y <= (position.y + size.y));
}

auto GameMenu::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

MenuStates GameMenu::run()
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

    Button button1(sf::Vector2f(200.f, 50.f), "Play");
    button1.setPosition(sf::Vector2f(250.f, 200.f));

    Button button2(sf::Vector2f(200.f, 50.f), "Quit");
    button2.setPosition(sf::Vector2f(250.f, 300.f));


    while (window->isOpen())
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (isMouseIn(button1))
                return MenuStates::PLAY;
            else if (isMouseIn(button2))
                return MenuStates::EXIT;
                
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
        button1.draw(window);
        button2.draw(window);
        window->display();
    }
	return MenuStates::EXIT;
}
