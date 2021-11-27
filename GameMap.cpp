#include "GameMap.h"
#include <iostream>

void GameMap::removeInteractiveItem(int x, int y)
{
	std::list<MapElement*>::iterator it = interactiveBlocks.begin();
	for (; it != interactiveBlocks.end(); ++it)
	{
		MapElement* el = *it;
		if (el->getX() == x && el->getY() == y) {
			interactiveBlocks.remove(el);
			return;
		}
 	}

}



void GameMap::addBomb(Bomb* bomb)
{
	elements[bomb->getX()][bomb->getY()] = bomb;
	this->bombs.push_back(bomb);
}

void GameMap::addPlayer(Player& player)
{
	players.push_back(&player);
}

void GameMap::clearPlayers()
{
	players.clear();
}

void GameMap::gameCycle()
{

	{
		std::vector<Player*>::iterator it = players.begin();
		
		for (; it != players.end(); ++it) {
			Player* player = *it;

			sf::Vector2f nextMove = calculatePlayerMovement(player);
			sf::Vector2f playerSize = player->getSize();
			sf::Vector2f playerPosition = player->getPosition();

			if (nextMove.x > 0) {
				player->setDirection(Direction::RIGHT);
				double valueX = ((playerPosition.x + playerSize.x / 2) / (mapWidthElements * singleElementHeight) * mapWidthElements);
				double valueY = ((playerPosition.y + playerSize.y / 2) / (mapHeightElements * singleElementHeight) * mapHeightElements);

				


				int xN = (int)std::round(valueX + 0.4f);
				int yN = (int)std::round(valueY - 0.3f);

				if (xN < mapWidthElements && xN >= 0 && yN >= 0 && yN < mapHeightElements && elements[xN][yN] == NULL) {
					player->setPosition(sf::Vector2f(playerPosition.x, yN * singleElementHeight + 5.f));
				}
			}
			else if (nextMove.x < 0) {
				player->setDirection(Direction::LEFT);

				double valueX = ((playerPosition.x + playerSize.x / 2) / (mapWidthElements * singleElementHeight) * mapWidthElements);
				double valueY = ((playerPosition.y + playerSize.y / 2) / (mapHeightElements * singleElementHeight) * mapHeightElements);

				int xN = (int)std::round(valueX + 0.4f);
				int yN = (int)std::round(valueY - 0.3f);

				if (xN < mapWidthElements && xN >= 0 && yN >= 0 && yN < mapHeightElements && elements[xN][yN] == NULL) {
					player->setPosition(sf::Vector2f(playerPosition.x, yN * singleElementHeight + 5.f));
				}
			}
			else if (nextMove.y > 0) {
				player->setDirection(Direction::DOWN);

				double valueX = ((playerPosition.x + playerSize.x / 2) / (mapWidthElements * singleElementHeight) * mapWidthElements);
				double valueY = ((playerPosition.y + playerSize.y / 2) / (mapHeightElements * singleElementHeight) * mapHeightElements);




				int xN = (int)std::round(valueX - 0.3f);
				int yN = (int)std::round(valueY + 0.4f);

				if (xN < mapWidthElements && xN >= 0 && yN >= 0 && yN < mapHeightElements && elements[xN][yN] == NULL) {
					player->setPosition(sf::Vector2f(xN * singleElementWidth + 5.f, playerPosition.y));
				}
			}
			else if (nextMove.y < 0) {
				player->setDirection(Direction::TOP);


				double valueX = ((playerPosition.x + playerSize.x / 2) / (mapWidthElements * singleElementHeight) * mapWidthElements);
				double valueY = ((playerPosition.y + playerSize.y / 2) / (mapHeightElements * singleElementHeight) * mapHeightElements);




				int xN = (int)std::round(valueX - 0.3f);
				int yN = (int)std::round(valueY + 0.4f);

				if (xN < mapWidthElements && xN >= 0 && yN >= 0 && yN < mapHeightElements && elements[xN][yN] == NULL) {
					player->setPosition(sf::Vector2f(xN * singleElementWidth + 5.f, playerPosition.y));
				}
			}

			player->moveBy(nextMove);

			if (player->isCanPlaceBomb()) {
	
				sf::Vector2f position = player->getPosition();

				int playerX = std::round(position.x / (mapWidthElements * singleElementHeight) * mapWidthElements);
				int playerY = std::round(position.y / (mapHeightElements * singleElementHeight) * mapHeightElements);

				Bomb* bomb = new Bomb();

				Direction playerDirection = player->getDirection();

				if (playerDirection == Direction::RIGHT && (playerX + 1) <= mapWidthElements) {
					bomb->setX(playerX + 1);
					bomb->setY(playerY);
				}
				else if (playerDirection == Direction::LEFT && (playerX - 1) >= 0) {
					bomb->setX(playerX - 1);
					bomb->setY(playerY);
				}
				else if (playerDirection == Direction::TOP && (playerY - 1) >= 0) {
					bomb->setX(playerX);
					bomb->setY(playerY - 1);
				}
				else if (playerDirection == Direction::DOWN && (playerY + 1) <= mapHeightElements) {
					bomb->setX(playerX);
					bomb->setY(playerY + 1);
				}

				addBomb(bomb);
			}
		}

	}


	std::vector<Bomb*>::iterator it = bombs.begin();

	for (it = bombs.begin(); it != bombs.end(); it++) {

		Bomb* bo = *it;
		if (bo->isReadyToExplode()) {

			
			DeathMapElement *center = new DeathMapElement();

			deathMapElements.push_back(center);

			center->setX(bo->getX());
			center->setY(bo->getY());

			elements[bo->getX()][bo->getY()] = center;

			int xBasic = bo->getX();
			int yBasic = bo->getY();
			int power = bo->getPower();

			for (int x = xBasic + 1, i = 0; i < power && x < mapWidthElements; ++x, ++i) {
				MapElement* buff = elements[x][yBasic];
				if (buff != NULL)
				{
					if (std::string(typeid(*buff).name()) == std::string(typeid(Chest).name()))
					{
						Apple* apple = new Apple(((Chest*)buff)->getPower());

						apple->setX(buff->getX());
						apple->setY(buff->getY());

						elements[x][yBasic] = apple;
						interactiveBlocks.remove(buff);
						delete buff;
					}
					break;
				}

				DeathMapElement *element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(x);
				element->setY(yBasic);

				elements[element->getX()][element->getY()] = element;
			}

			for (int y = yBasic + 1, i = 0; i < power && y < mapHeightElements; ++y, ++i) {

				MapElement* buff = elements[xBasic][y];
				if (buff != NULL)
				{
					if (std::string(typeid(*buff).name()) == std::string(typeid(Chest).name()))
					{

						Apple* apple = new Apple(((Chest*)buff)->getPower());

						apple->setX(buff->getX());
						apple->setY(buff->getY());

						elements[xBasic][y] = apple;
						interactiveBlocks.remove(buff);
						delete buff;
					}
					break;
				}

				DeathMapElement* element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(xBasic);
				element->setY(y);

				elements[element->getX()][element->getY()] = element;
			}

			for (int x = xBasic - 1, i = 0; i < power && x >= 0; --x, ++i) {

				MapElement* buff = elements[x][yBasic];
				if (buff != NULL)
				{
					if (std::string(typeid(*buff).name()) == std::string(typeid(Chest).name()))
					{
						Apple* apple = new Apple(((Chest*)buff)->getPower());

						apple->setX(buff->getX());
						apple->setY(buff->getY());

						elements[x][yBasic] = apple;
						interactiveBlocks.remove(buff);

						delete buff;
					}
					break;
				}


				DeathMapElement* element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(x);
				element->setY(yBasic);

				elements[element->getX()][element->getY()] = element;
			}

			for (int y = yBasic - 1, i = 0; i < power && y >= 0; --y, ++i) {

				MapElement* buff = elements[xBasic][y];

				if (buff != NULL)
				{
					if (std::string(typeid(*buff).name()) == std::string(typeid(Chest).name()))
					{
						Apple* apple = new Apple(((Chest*)buff)->getPower());

						apple->setX(buff->getX());
						apple->setY(buff->getY());

						interactiveBlocks.push_back(apple);
						interactiveBlocks.remove(buff);

						elements[xBasic][y] = apple;;

						delete buff;
					}
					break;
				}

				DeathMapElement* element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(xBasic);
				element->setY(y);

				elements[element->getX()][element->getY()] = element;
			}
	
			bombs.erase(it);

			delete bo;
			break;
		}
	}

	std::vector<DeathMapElement*>::iterator itd = deathMapElements.begin();
		
	
	for (itd = deathMapElements.begin(); itd != deathMapElements.end(); itd++) {

		DeathMapElement* bo = *itd;
		if (bo->isCanDisappear()) {

			elements[bo->getX()][bo->getY()] = NULL;

			deathMapElements.erase(itd);

			delete bo;
			break;
		}
	}

}

GameMap::GameMap(int mapWidthElements, int mapHeightElements)
{
	this->elements = new MapElement ** [mapWidthElements];

	this->mapWidthElements = mapWidthElements;
	this->mapHeightElements = mapHeightElements;

	for (int i = 0; i < mapWidthElements; ++i) {
		elements[i] = new MapElement * [mapHeightElements];
		std::memset(elements[i], NULL, sizeof(MapElement*)*mapHeightElements);
	}
}

void GameMap::setElement(int x, int y, MapElement *element)
{
	element->setX(x);
	element->setY(y);

	if (element->isInteractive()) 
		this->interactiveBlocks.push_back(element);
	

	delete elements[x][y];
	elements[x][y] = element;
}

void GameMap::clearElement(int x, int y)
{
	delete elements[x][y];
	elements[x][y] = NULL;

	this->removeInteractiveItem(x, y);
}

double GameMap::getSingleElementWidth()
{
	return singleElementWidth;
}

double GameMap::getSingleElementHeight()
{
	return singleElementHeight;
}

MapElement* GameMap::getElement(int x, int y)
{
	return elements[x][y];
}

void GameMap::drawMap(sf::RenderWindow* window)
{
	sf::Vector2u sizeWindow = window->getSize();
	singleElementWidth = (double)sizeWindow.x / mapWidthElements,
	singleElementHeight = (double)sizeWindow.y / mapHeightElements;

	

	for(int x = 0; x < mapWidthElements; ++x)
		for (int y = 0; y < mapHeightElements; ++y)
		{
			MapElement* element = getElement(x, y);

			if (element == NULL)
				continue;

			sf::RectangleShape &shape = element->getToDraw();

			shape.setSize(sf::Vector2f(singleElementWidth, singleElementHeight));
			shape.setPosition(sf::Vector2f(singleElementWidth*x, singleElementHeight*y));

			window->draw(shape);
		}
}

sf::Vector2f GameMap::calculatePlayerMovement(Player* player)
{
	std::list<MapElement*>::iterator it = this->interactiveBlocks.begin();
	sf::Vector2f mover = player->getCalculateMove();

	
	for (; it != interactiveBlocks.end(); ++it) {
		MapElement* el = *it;

		sf::FloatRect recta = el->getFloatRect();

		if (player->isIntersect(recta) && std::string(typeid(*el).name()) == std::string(typeid(Apple).name()))
		{
			Apple* ap = (Apple*)el;

			elements[el->getX()][el->getY()] = NULL;

			int power = player->getPower() + ap->getPower();

			if (power > player->getMaxPower())
				power = player->getMaxPower();

			player->setPower(power);

			interactiveBlocks.erase(it);

			delete el;

			break;
		}

		if (mover.x > 0.f && !player->isCanMoveRight(recta))
			mover.x = -0.1f;

		if (mover.x < 0.f && !player->isCanMoveLeft(recta))
			mover.x = 0.1f;

		if (mover.y < 0.f && !player->isCanMoveUp(recta))
			mover.y = 0.1f;

		if (mover.y > 0.f && !player->isCanMoveDown(recta))
			mover.y = -0.1f;

	}

	return mover;
}

GameMap GameMap::loadMapFromFile(std::string path)
{
	std::ifstream file(path);

	int width, height;

	std::string buff;
	std::stringstream stream;


	if (!std::getline(file, buff))
		throw "Invalid File!";


	stream << buff;


	stream >> width;


	stream.str(std::string());
	stream.clear();

	if (!std::getline(file, buff))
		throw "Invalid File!";


	stream << buff;

	stream >> height;

	stream.str("");

	std::cout << width << ' ' << height;

	GameMap map(width, height);


	for (int y = 0, x; y < height; ++y)
	{
		if (!std::getline(file, buff))
			throw "Invalid File!";

		for (x = 0; x < width; ++x) {

			switch (buff[x])
			{
			case '_':
				std::cout << "TAK ";
			default:
				break;
			}

		}
		std::cout << '\n';
	}

	return map;
}



