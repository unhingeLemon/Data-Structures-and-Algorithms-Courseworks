#include <iostream>
using namespace std;


class DynIntQueue{
	private:
		struct QueueNode{
		  int value;
		  QueueNode *next;
		};

		QueueNode *front;
		QueueNode *rear;
		int numItems;
     
    public:
		DynIntQueue();
		~DynIntQueue();
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty();
		void clear();
};



//************************
// Constructor *
//************************
DynIntQueue::DynIntQueue(void){
	front = NULL;
	rear = NULL;
	numItems = 0;
}


//*************************
// Destructor *
//*************************
DynIntQueue::~DynIntQueue(){
	clear();
}



//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void DynIntQueue::enqueue(int num){
	QueueNode *newNode;
	newNode = new QueueNode;
	newNode->value = num;
	newNode->next = NULL;
	if (isEmpty()){
		front = newNode;
		rear = newNode;
	}
	else{
		rear->next = newNode;
		rear = newNode;
	}
	numItems++;
}


//**********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//**********************************************
void DynIntQueue::dequeue(int &num){
	QueueNode *temp;
	if (isEmpty())
		cout << "The queue is empty.\n";
	else{
		num = front->value;
		temp = front->next;
		delete front;
		front = temp;
		numItems--;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool DynIntQueue::isEmpty(){
	bool status;
	if (numItems)
		status = false;
	else
		status = true;
	return status;
}



//********************************************
// Function clear dequeues all the elements *
// in the queue. *
//********************************************
void DynIntQueue::clear(){
	int value; // Dummy variable for dequeue
	while(!isEmpty())
		dequeue(value);
}

int main(){
	DynIntQueue iQueue;
	cout << "Enqueuing 5 items...\n";
	// Enqueue 5 items.
	for (int x = 0; x < 5; x++)
		iQueue.enqueue(x);
	// Deqeue and retrieve all items in the queue
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty()){
		int value;
		iQueue.dequeue(value);
		cout << value << endl;
	}
}





