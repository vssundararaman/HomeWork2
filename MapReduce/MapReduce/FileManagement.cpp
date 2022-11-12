#include "FileManagement.h"
#include "Map.h"
#include "Reduce.h"
#include "ReduceDll.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;
filesystem::path interPath;
filesystem::path outerPath;
vector<pair<string, int>> inter_count;
vector<pair<string, int>> outer_count;

void FileManagement::readFile(const std::filesystem::path& filename)
{

    string line;
    fstream file;
    file.open(filename);

    while (!file.eof()) {
       getline(file, line);
       Map::mapFile(filename.string(), line);
    }

}

bool FileManagement::checkDir(std::filesystem::path& p)
{
    if (!filesystem::exists(p)) {
        cout <<  "The file directory does not exit. Try again.\n ";
        return false;
    }
    else
      return true;


    
}

void FileManagement::setIntermediatePath(std::filesystem::path& p)
{
    interPath = p;

}

void FileManagement::intermediateWrite(std::string key, int value)
{
    inter_count.push_back(make_pair(key, value));
}

void FileManagement::setOutputPath(filesystem::path& p)
{
    outerPath = p;
}

// iterates through files in input directory
void FileManagement::iterateFiles(std::filesystem::path& p)
{
    if (filesystem::is_empty(p)) {
        cout << " No files in the directory";
    }
    else {

        //Read files from the path
        for (auto const& dir_entry : filesystem::directory_iterator(p)) {

            cout << dir_entry.path() << '\n';
            readFile(dir_entry.path());
        }
    }

}

void FileManagement::pushReduce(std::filesystem::path& p)
{
    string temp;
    vector<string> count;

    fstream file;
    file.open(p);

    //Parses file
    while (!file.eof()) {

        string noCount;
        getline(file, temp);

     //   noCount = temp.substr(0, temp.find(", 1"));
       
        //Calling the Dll from Client
        noCount = reduceAndCount(temp);
        count.push_back(noCount);
    }

    // pushes results to reduce
    int sum = 1;
    for (int i = 0; i < count.size() - 1; i++) {

        if (count[i] == count[i + 1]) {
            sum++;
        }
        else {
            Reduce::reduce(count[i], sum);
            sum = 1;
        }

    }

}

void FileManagement::outputWrite(std::string key, int value)
{
    outer_count.push_back(make_pair(key, value));
}

// function that creates and writes to a file in given directory, will call from reduce class
void FileManagement::writeInterFile()
{

    fstream output;
    output.open(interPath);
    sort(inter_count.begin(), inter_count.end());

    for (auto const& pair : inter_count) {
        output << pair.first << ", " << pair.second << "\n";
    }
}

void FileManagement::writeOutputFile()
{
    fstream output;
    output.open(outerPath);

    for (auto const& pair : outer_count) {
        output << pair.first << ", " << pair.second << "\n";
    }
}
