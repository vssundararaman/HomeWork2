#pragma once
#ifndef REDUCE_H
#define REDUCE_H
#include <iostream>
#include <vector>
#include <iterator>



using namespace std;

class Reduce {
public:
	static void exportAll(std::string key, int result);
	static void reduce(std::string key, int iterator);
		
};

#endif