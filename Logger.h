#pragma once
#include <iostream>

class Logger
{
private:
	static std::string filePath;

public:
	static void setPath(std::string path);
	static void log(std::string data);
};

