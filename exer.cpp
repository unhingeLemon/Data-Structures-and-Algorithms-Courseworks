#include <iostream>
#include <queue>
using namespace std;
int main()
{
int x;
queue<int> iQueue;
cout << "I will now enqueue items...\n";
for (x = 2; x < 50; x += 2)
{
cout << "Pushing " << x << endl;
iQueue.push(x);
}
cout << "I will now dequeue items...\n";
for (x = 2; x < 50; x += 2)
{
cout << "Popping " << iQueue.front() << endl;
iQueue.pop();
}
}



















//int prime(int n, int i =1);
//
//int main() {
//	int num;
//	cout << "Enter a positive number:";
//	cin >> num;
//	if(prime(num)==2)
//		cout << "prime" << endl;
//	else
//		cout << "not prime" << endl;
//	system("pause");
//}

//int prime(int n, int i){
//	if(i==n)
//		return i;
//	else if(n%i == 0)
//		return (1 + prime(n,i+1));
//	
//}
//

