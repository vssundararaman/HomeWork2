#include "Executive.h"
#include  "FileManagement.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <fstream>

using namespace std;

int main() {

	//input path
	cout << " Enter input directory: \n";
	string inputPath;
	cin >> inputPath;

	filesystem::path inPath = inputPath;
	bool validInput = FileManagement::checkDir(inPath);
	if (!validInput) {
		cout << " Invalid inputdirectory";
		return 0;
	}


	cout << " Enter intermediate directory: \n";
	//Intermediate Path
	string interMediatePath;
	cin >> interMediatePath;
	filesystem::path interPath = interMediatePath;

	if (!FileManagement::checkDir(interPath)) {
		cout << " Invalid Path";
		return 0;
	}

	cout << " Enter output directory: \n";
	string outputPath;
	cin >> outputPath;
	filesystem::path outPath = outputPath;
	bool validOutput = FileManagement::checkDir(outPath);
	if (!validOutput) {
		cout << " Invalid outputdirectory";
		return 0;
	}
	
	cout << "Creating output files in intermediate and output folder... \n";
	interPath /= "output.txt";
	ofstream intOf(interPath);
	FileManagement::setIntermediatePath(interPath);


	outPath /= "output.txt";
	ofstream outOf(outPath);
	FileManagement::setOutputPath(outPath);

	cout << "Starting to parse files in input directory... \n";

	FileManagement::iterateFiles(inPath);

	cout << "Reducing values...\n";

	FileManagement::pushReduce(interPath);

	cout << "  Process completed successfully...";
	return 0;
}
