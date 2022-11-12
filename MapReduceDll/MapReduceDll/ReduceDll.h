#pragma once
#ifdef REDUCEDLL_EXPORTS
#define REDUCEDLL_API  __declspec(dllexport)
#else
#define REDUCEDLL_API  __declspec(dllimport)
#endif
#include <iostream>

using namespace std;

extern "C" REDUCEDLL_API string reduceAndCount(string line);