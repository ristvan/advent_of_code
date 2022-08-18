#include "version.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Version: " << aoc_VERSION_MAJOR << "." << aoc_VERSION_MINOR << "." << aoc_VERSION_PATCH << endl;
    return 0;
}
