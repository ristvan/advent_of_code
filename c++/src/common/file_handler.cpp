#include "file_handler.hpp"
#include <fstream>
#include <string>
#include <vector>


using namespace std;


vector<string> read_file(string filename)
{
    ifstream inputFile;
    inputFile.open(filename);
    vector<string> lines;
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
    }
    return lines;
}
