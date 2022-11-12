#include "pch.h"
#include "ReduceDll.h"
using namespace std;

string reduceAndCount(string line)
{
    return line.substr(0, line.find(", 1"));
}
