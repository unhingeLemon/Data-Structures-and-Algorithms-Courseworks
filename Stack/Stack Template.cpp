#include <iostream>
#include <cstdlib>
using namespace std;

// Define the default capacity of the stack
#define SIZE 10

template <class T>
class Stack {
	private:
		T *stackArray;
		int stackSize;
		int top;
	public:
		Stack(int size);
		void push(T);
		T pop();
		T topElement();
//		int size();
		
		bool isFull();
		bool isEmpty();
};



//*******************
// Constructor *
//*******************

template <class T>
Stack<T>::Stack(int size) {
	stackArray = new T[size];
	stackSize = size;
	top = -1;
}

//*************************************************
// Member function push pushes the argument onto *
// the stack. *
//*************************************************
template <class T>
void Stack<T>::push(T t) {
	if (isFull()) {
		cout << "The stack is full.\n";
	}else{
		top++;
		stackArray[top] = t;
	}
}

//****************************************************
// Member function pop pops the value at the top *
// of the stack off, and copies it into the variable *
// passed as an argument. *
//****************************************************
template <class T>
T Stack<T>::pop(){
	if (isEmpty()){
		cout << "The stack is empty.\n";
	} 
    // decrease stack size by 1 and (optionally) return the popped element
	return stackArray[top--];

	
}

// To return the top element of the stack
template <class T>
T Stack<T>::topElement(){
	if(!isEmpty()){
		return stackArray[top];	
	} 
}

//// To return the size of the stack
//template <class T>
//int Stack<T>::size(){
//	return top++;
//}


//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise. *
//***************************************************
template <class T>
bool Stack<T>::isFull() {
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
template <class T>
bool Stack<T>::isEmpty() {
	bool status;
	if (top == -1)
		status = true;
	else
		status = false;
	return status;
}

int main()
{
int sizeOfStack = 4;
  // just change the string to any data type you want
  Stack<string> stack(sizeOfStack);
  cout << "Pushing Mark\n";
	stack.push("Mark");
  cout << "Pushing Angelo\n";
	stack.push("Angelo");
  cout << "Pushing B.\n";
  stack.push("B");
  cout << "Pushing Capili\n";
  stack.push("Capili");
	cout << "Popping: " << stack.pop() << endl;
  cout << "Popping: " << stack.pop() << endl;
  cout << "Popping: " << stack.pop() << endl;
  cout << "The top element is: " << stack.topElement() << endl;
}
