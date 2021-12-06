#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class AnimatedObject
{
protected:
	int intervalFPS = 6;
	int countFPS = 0;
	int imgIndex = 0;
	bool isStop = false;
	std::vector<sf::Image> framesFront;
	std::vector<sf::Image> framesLeft;
	std::vector<sf::Image> framesRight;
	std::vector<sf::Image> framesBack;



public:
	void setFramesFront(sf::Image arr[], int length);
	void setFramesBack(sf::Image arr[], int length);
	void setFramesLeft(sf::Image arr[], int length);
	void setFramesRight(sf::Image arr[], int length);

	void setIntervalFPS(int fps);
	int getIntervalFPS();
	void setIsStop(bool isStop);
	bool getIsStop();
	virtual void animate() = 0;
};

