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
			
			}
			else if (nextMove.x < 0)
				player->setDirection(Direction::LEFT);
			else if (nextMove.y > 0) {
				player->setDirection(Direction::DOWN);
				std::cout << ((playerPosition.x + playerSize.x / 2) / (mapWidthElements * singleElementHeight) * mapWidthElements) << '\n';
			}
			else if (nextMove.y < 0) {
				player->setDirection(Direction::TOP);
				std::cout << ((playerPosition.x + playerSize.x / 2) / (mapWidthElements * singleElementHeight) * mapWidthElements) << '\n';
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
				if (elements[x][yBasic] != NULL)
					break;

				DeathMapElement *element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(x);
				element->setY(yBasic);

				elements[element->getX()][element->getY()] = element;
			}

			for (int y = yBasic + 1, i = 0; i < power && y < mapHeightElements; ++y, ++i) {
				if (elements[xBasic][y] != NULL)
					break;
				DeathMapElement* element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(xBasic);
				element->setY(y);

				elements[element->getX()][element->getY()] = element;
			}

			for (int x = xBasic - 1, i = 0; i < power && x >= 0; --x, ++i) {
				if (elements[x][yBasic] != NULL)
					break;
				DeathMapElement* element = new DeathMapElement();
				deathMapElements.push_back(element);

				element->setX(x);
				element->setY(yBasic);

				elements[element->getX()][element->getY()] = element;
			}

			for (int y = yBasic - 1, i = 0; i < power && y >= 0; --y, ++i) {
				if (elements[xBasic][y] != NULL)
					break;
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



