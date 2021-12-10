#include "GameMenu.h"

/**
 * .
 * \brief Konstruktor menu gry
 * \param window
 */
GameMenu::GameMenu(sf::RenderWindow* window)
{
	this->window = window;
}

/**
 * .
 * \brief Sprawdza czy myszka jest w danym obszarze
 * \param shape Ksztalt
 * \return 
 */
bool GameMenu::isMouseIn(Button& shape)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
 
    sf::Vector2f position = shape.getPosition(), size = shape.getSize();

   
    return (mousePosition.x >= position.x && mousePosition.y >= position.y && mousePosition.x <= (position.x + size.x) && mousePosition.y <= (position.y + size.y));
}

/**
 * .
 * \brief Pobiera aktualny czas
 * \return Zwraca aktualny czas
 */
auto GameMenu::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/**
 * .
 * \brief Uruchamia menu gry 
 * \return 
 */
MenuStates GameMenu::run()
{
    auto lastFrame = getCurrentTime();
    int fpsInterval = 1000 / 60;

    background.setPosition(0, 0);
    //background.setFillColor(sf::Color::Green);

    if (!this->texture.loadFromFile("images/bg.jpg"))
    {
        Logger::log("Nie mozna zaladowac tla");
        throw "Error ladowania tekstury tla!";
    }


    this->background.setTexture(&this->texture);

    Button button1(sf::Vector2f(200.f, 50.f), "Play");
    button1.setPosition(sf::Vector2f(250.f, 200.f));

    Button button2(sf::Vector2f(200.f, 50.f), "Quit");
    button2.setPosition(sf::Vector2f(250.f, 300.f));

    LevelMenu menu(window);

    while (window->isOpen())
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (isMouseIn(button1)) {
                MenuStates state = menu.run();
                if (state != MenuStates::BACK)
                    return state;
            }
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
