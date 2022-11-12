#include "pch.h"
#include "MapReduceDll.h"
#include <utility>
#include <limits>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

string processLine(string value)
{
	//removes punctation, whilespace and captialization
	locale loc;
	string tokenWord = value;

	//removes captalization from line
	transform(tokenWord.begin(), tokenWord.end(), tokenWord.begin(), ::tolower);

	//removes punctation from line
	auto it = std::remove_if(tokenWord.begin(), tokenWord.end(), [](char const& c) {
		return std::ispunct(c);
		});
	tokenWord.erase(it, tokenWord.end());

	stringstream spaceWord(tokenWord);


    return spaceWord.str();
}
