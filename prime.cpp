#include <iostream>

using namespace std;


int prime(int n, int i =1);

int main() {
	int num;
	cout << "Enter a positive number:";
	cin >> num;
	if(prime(num)==2)
		cout << "prime" << endl;
	else
		cout << "not prime" << endl;
	system("pause");
}

int prime(int n, int i){
	if(i==n)
		return 1;
	else if(n%i == 0)
		return (1 + prime(n,i+1));
	
}


