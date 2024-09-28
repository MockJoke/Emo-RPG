#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printAscii(string fileName)
{
    string line = "";
    ifstream file;
    file.open(fileName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    file.close();
}