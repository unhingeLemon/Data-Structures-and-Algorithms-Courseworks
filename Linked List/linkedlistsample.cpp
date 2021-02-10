#include <iostream>
using namespace std;

class FloatList{
	private:
	// Declare a structure for the list
	struct ListNode{
		float value;
		struct ListNode *next;
	};
	ListNode *head; // List head pointer
	public:
		FloatList() // Constructor
		{ head = NULL; }
		~FloatList(); // Destructor
		void appendNode(float num);
		void insertNode(float num);
		void deleteNode(float num);
		void displayList();
};

void FloatList::appendNode(float num){
	ListNode *newNode, *nodePtr;
	// Allocate a new node & store num
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
		head = newNode;
	else{ // Otherwise, insert newNode at end 
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;
			// Insert newNode as the last node
		nodePtr->next = newNode;
	} 
	//cout << "Input has been APPENDED!" << endl;
}

void FloatList::displayList(void){
	ListNode *nodePtr;
	if (head==NULL)
		cout << "The List is empty!" << endl;
	else {
		nodePtr = head;
		while (nodePtr){
			cout << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}	
	}
} 

void FloatList::insertNode(float num){
	ListNode *newNode, *nodePtr, *previousNode;
	// Allocate a new node & store Num
	newNode = new ListNode;
	newNode->value = num;
	// If there are no nodes in the list
	// make newNode the first node
	if (!head){
		head = newNode;
		newNode->next = NULL;
	}
	else{ // Otherwise, insert newNode.
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;
		// Skip all nodes whose value member is less
		// than num.
		while (nodePtr != NULL && nodePtr->value < num){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			// If the new mode is to be the 1st in the list,
			// insert it before all other nodes.
	
		}
		if (previousNode == NULL){
		head = newNode;
		newNode->next = nodePtr;
		}else{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	//	cout << "Input has been INSERTED!" << endl;
	}

}

void FloatList::deleteNode(float num){
	ListNode *nodePtr, *previousNode;
	int found = 0;
	// If the list is empty, do nothing.
	if (!head){
		//cout << �The list is empty!� << endl;
		return; 
	}
	// Determine if the first node is the one.
	if (head->value == num){
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		found = 1;
	}else{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;
		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != NULL && nodePtr->value != num){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// Link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr !=NULL){
			previousNode->next = nodePtr->next;
			delete nodePtr;
			//cout << �Input has been DELETED!� << endl;
			found = 1;
		}
	}
	//if (found==0) 
	//	cout << �Input not in the list!� << endl;
}

FloatList::~FloatList(){
	ListNode *nodePtr, *nextNode;
	nodePtr = head;
	while (nodePtr != NULL){
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

}


int main(void) {
	FloatList list;
	list.appendNode(2.5);
	list.appendNode(4.9);
	list.appendNode(7.9);
	list.appendNode(9.9);
	list.appendNode(12.6);
	// Insert a node in the middle
	// of the list.
	list.insertNode(10.5);
	// Dispay the list
	list.displayList();
	system("pause");
	list.deleteNode(7.9);
	list.displayList();
	system("pause");
	return 1;
}


