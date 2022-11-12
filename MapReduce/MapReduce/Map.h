#pragma once
#ifndef MAP_H
#define MAP_H
#include <string>
#include <map>

class Map
{
public:
	static void mapExport(std::string key, int value);
	static void mapFile(std::string filename, std::string input);
};



#endif