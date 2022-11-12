#include "Map.h"
#include "FileManagement.h"
#include "MapReduceDll.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

void Map::mapExport(std::string key, int value)
{
	FileManagement::intermediateWrite(key, value);
}

void Map::mapFile(std::string filename, std::string input)
{
	//Calling the Dll function
	string processedWord = processLine(input);

	stringstream spaceWord(processedWord);
	string temp;

	// identifies whitespace and pushes word into intermediate map file
	while (spaceWord >> temp)
	{
		mapExport(temp, 1);
	}

	FileManagement::writeInterFile();

}
