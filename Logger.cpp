#define __STDC_WANT_LIB_EXT1__ 1
#define _XOPEN_SOURCE
#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"
#include <fstream>

/**
 * .
 * \brief Ustawia plik wyjsciowy
 * \param path Sciezka
 */
void Logger::setPath(std::string path)
{
	Logger::filePath = path;
}
std::string Logger::filePath = "";

/**
 * .
 * \brief Zapisuje wiadomosc
 * \param data Tresc wiadomosci
 */
void Logger::log(std::string data)
{
	std::ofstream outfile;

	time_t t = time(NULL);

	outfile.open(Logger::filePath, std::ios_base::app);

	outfile << data << " | " << asctime(localtime(&t));

	outfile.close();
}
