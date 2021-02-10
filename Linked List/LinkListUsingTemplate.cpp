#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template <class T>
class LinkedList
{
private:
	struct ListNode
	{
		T value;
		struct ListNode *next;
	};
	ListNode *head;	// List head pointer
public:
	LinkedList(void)	// Constructor
	{
		head = NULL;
	}
	~LinkedList(); // Destructor
	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList();
};

template <class T>
void LinkedList<T>::appendNode(T num) {
	ListNode *newNode, *nodePtr;

	// Allocate a new node & store num
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
		head = newNode;
	else	// Otherwise, insert newNode at end
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

template <class T>
void LinkedList<T>::displayList(){
	ListNode *nodePtr;

	nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

template <class T>
void LinkedList<T>::insertNode(T num) {
	ListNode *newNode, *nodePtr, *previousNode;

	// Allocate a new node & store Num
	newNode = new ListNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert newNode at end
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;
		// Skip all nodes whose value member is less
		// than num.
		while (nodePtr != NULL && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Insert the node after the one pointed to
		// by previousNode and before the one pointed to
		// by nodePtr.
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}
}

template <class T>
void LinkedList<T>::deleteNode(T num){

	ListNode *nodePtr, *previousNode;
	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;
		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// Link the previous node to the node after
		// nodePtr, then delete nodePtr.
		previousNode->next = nodePtr->next;
		delete nodePtr;
	}
}

template <class T>
LinkedList<T>::~LinkedList(){
	ListNode *nodePtr, *nextNode;

	nodePtr = head;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

#endif // To terminate #ifndef



int main(){
	LinkedList<string> list;

	// Build the list
	list.appendNode("asdas");
//	list.appendNode(4);
//	list.appendNode(6);
//	cout << "Here are the initial values:\n";
	list.displayList();
//	cout << endl;
//	cout << "Now inserting the value 5.\n";
//	list.insertNode(5);
//	cout << "Here are the nodes now.\n";
//	list.displayList();
//	cout << endl;
//
//	cout << "Now deleting the last node.\n";
//	list.deleteNode(6);
//	cout << "Here are the nodes left.\n";
//	list.displayList();
//	system("pause");
}


 

