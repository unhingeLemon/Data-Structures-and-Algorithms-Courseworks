#include <iostream>

using namespace std;

class FloatList{
	private:
	// Declare a structure for the list
	struct ListNode{
	
		struct data {
			float value;
			char c;
		};
		struct ListNode *next;
	};
	ListNode *head; // List head pointer
	public:
		FloatList() // Constructor
		{ head = NULL; }
//		~FloatList(); // Destructor
		void appendNode(struct data);
//		void insertNode(float num);
//		void deleteNode(float num);
		void displayList();
};

void FloatList::displayList(void){
	ListNode *nodePtr;
	if (head==NULL)
		cout << "The List is empty!" << endl;
	else {
		nodePtr = head;
		while (nodePtr){
			cout << nodePtr->data.value << nodePtr->data.c << endl;
			nodePtr = nodePtr->next;
		}	
	}
} 

void FloatList::appendNode(struct data){
	ListNode *newNode, *nodePtr;
	// Allocate a new node & store num
	newNode = new ListNode;
	newNode->data.value = value;
	newNode->data.c = c;
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


int main() {
	FloatList list;
	
	list.appendNode({
		value = 23;
		c = 'c';
	});
	list.displayList();

}
