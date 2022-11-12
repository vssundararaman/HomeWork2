#pragma once
#ifdef MAPREDUCEDLL_EXPORTS
#define MAPREDUCEDLL_API  __declspec(dllexport)
#else
#define MAPREDUCEDLL_API  __declspec(dllimport)
#endif
#include <iostream>

using namespace std;


extern "C" MAPREDUCEDLL_API string processLine(string value);