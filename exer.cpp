#include <iostream>
#include <ifstream>
#include <string>

using namespace std;

ifstream file("file.txt");
if (file.is_open())
{
	string line;
	while (getline(file, line))
    {
    	// note that the newline character is not included
        // in the getline() function
    	cout << line << endl;
    }
}
