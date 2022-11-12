#include "Reduce.h"
#include "FileManagement.h"
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>


using namespace std;

void Reduce::exportAll(std::string key, int result)
{
	//Writing the output to the output directory
	FileManagement::outputWrite(key, result);

}

void Reduce::reduce(std::string key, int iterator)
{
	int sum = iterator;
	
	exportAll(key, iterator);

	FileManagement::writeOutputFile();
}
