#include <iostream>
using namespace std;

class IntStack {
	private:
		int *stackArray;
		int stackSize;
		int top;
	public:
		IntStack(int size);
		void push(int num);
		void pop(int &num);
		bool isFull();
		bool isEmpty();
};



//*******************
// Constructor *
//*******************


IntStack::IntStack(int size) {
	stackArray = new int[size];
	stackSize = size;
	top = -1;
}

//*************************************************
// Member function push pushes the argument onto *
// the stack. *
//*************************************************
void IntStack::push(int num) {
	if (isFull()) {
		cout << "The stack is full.\n";
	}else{
		top++;
		stackArray[top] = num;
	}
}

//****************************************************
// Member function pop pops the value at the top *
// of the stack off, and copies it into the variable *
// passed as an argument. *
//****************************************************
void IntStack::pop(int &num){
	if (isEmpty()){
		cout << "The stack is empty.\n";
	}else{
		num = stackArray[top];
		top--;
	}
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise. *
//***************************************************
bool IntStack::isFull() {
	bool status;
	if (top == stackSize - 1)
		status = true;
	else
		status = false;
	return status;
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise. *
//****************************************************
bool IntStack::isEmpty() {
	bool status;
	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}

int main(){
	IntStack stack(5);
	int catchVar;
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 15\n";
	stack.push(15);
	cout << "Pushing 20\n";
	stack.push(20);
	cout << "Pushing 25\n";
	stack.push(25);
	
	cout << "Popping...\n";
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
}
