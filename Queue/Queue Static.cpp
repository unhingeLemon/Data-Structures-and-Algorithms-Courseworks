#include <iostream>
using namespace std;
class IntQueue{
	private:
		int *queueArray;
		int queueSize;
		int front;
		int rear;
		int numItems;
	public:
		IntQueue(int);
		~IntQueue();
		void enqueue(int);
		void dequeue(int &);
		bool isEmpty();
		bool isFull();
		void clear();
};

//*************************
// Constructor *
//*************************
IntQueue::IntQueue(int s){
	queueArray = new int[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
}

//*************************
// Destructor *
//*************************
IntQueue::~IntQueue(){
	delete [] queueArray;
}



//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void IntQueue::enqueue(int num){
	if (isFull())
		cout << "The queue is full.\n";
	else{
		// Calculate the new rear position
		rear = (rear + 1) % queueSize;
		// Insert new item
		queueArray[rear] = num;
		// Update item count
		numItems++;
	}
}


//*********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies t into num. *
//*********************************************
void IntQueue::dequeue(int &num){
	if (isEmpty())
		cout << "The queue is empty.\n";
	else{
		// Move front
		front = (front + 1) % queueSize;
		// Retrieve the front item
		num = queueArray[front];
		// Update item count
		numItems--;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool IntQueue::isEmpty(){
	bool status;
	if (numItems)
		status = false;
	else
		status = true;
	return status;
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise. *
//********************************************
bool IntQueue::isFull(){
	bool status;
	if (numItems < queueSize)
		status = false;
	else
		status = true;
	return status;
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0. *
//*******************************************
void IntQueue::clear(){
	front = queueSize - 1;
	rear = queueSize - 1;
	numItems = 0;
}

int main(){
	IntQueue iQueue(5);
	cout << "Enqueuing 5 items...\n";
	// Enqueue 5 items.
	for (int x = 0; x < 5; x++)
		iQueue.enqueue(x);
	// Attempt to enqueue a 6th item.
	cout << "Now attempting to enqueue again...\n";
	iQueue.enqueue(5);
	
	// Deqeue and retrieve all items in the queue
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty()){
		int value;
		iQueue.dequeue(value);
		cout << value << endl;
	}
}






