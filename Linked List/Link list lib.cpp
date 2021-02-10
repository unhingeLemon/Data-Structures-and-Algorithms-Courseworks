#include <iostream>
#include <list> // Include the list header
using namespace std; // Required by some compilers
int main()
{
	list<int> myList;
	list<int>::iterator iter;
	// Add values to the list
	for (int x = 0; x < 100; x += 10)
		myList.push_back(x);
	// Display the values
	for (iter = myList.begin(); iter != myList.end(); iter++)
		cout << *iter << " ";
		cout << endl;
	// Now reverse the order of the elements
	myList.reverse();
	// Display the values again
	for (iter = myList.begin(); iter != myList.end(); iter++)
		cout << *iter << " ";
		cout << endl;
}

