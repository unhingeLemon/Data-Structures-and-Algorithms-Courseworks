#include <iostream>
using namespace std;


class DynIntStack {
	private:
		struct stackNode{
			int value;
			stackNode *next;
		};
		stackNode *top;
	public:
		DynIntStack()
		{ top = NULL; }
		void push(int num);
		void pop(int &num);
		bool isEmpty();
};

//************************************************
// Member function push pushes the argument onto *
// the stack. *
//************************************************
void DynIntStack::push(int num){
	stackNode *newNode;
	// Allocate a new node & store Num
	newNode = new stackNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty()){
		top = newNode;
		newNode->next = NULL;
	} else{ // Otherwise, insert NewNode before top
		newNode->next = top;
		top = newNode;
	}
}
//****************************************************
// Member function pop pops the value at the top *
// of the stack off, and copies it into the variable *
// passed as an argument. *
//****************************************************

void DynIntStack::pop(int &num){
	stackNode *temp;
	if (isEmpty()){
		cout << "The stack is empty.\n";
	}else{ // pop value off top of stack
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}
//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise. *
//****************************************************
bool DynIntStack::isEmpty(){
	bool status;
	if (!top)
		status = true;
	else
		status = false;
	return status;
}

int main(){
	DynIntStack stack;
	int catchVar;
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 15\n";
	stack.push(15);
	cout << "Popping...\n";
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	cout << "\nAttempting to pop again... ";
	stack.pop(catchVar);
}


