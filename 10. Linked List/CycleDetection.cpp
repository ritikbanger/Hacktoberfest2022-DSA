#include <bits/stdc++.h>
using namespace std;

class Node {

	public:
	int key;
	struct Node* next;

	Node(int data){

		key = data;
		next = NULL;
	}
};

// Function to Print Entire LinkedList
void printList(Node* head)
{
	while (head != NULL) {

		cout << head -> key << " ";
		head = head -> next;
	}
	cout << endl;
}

// Optimal approach to detect a Cycle in a LinkedList
bool detectLoop(Node* head)
{

	Node *fast_ptr = head;
	Node *slow_ptr = head;

	fast_ptr = fast_ptr -> next -> next;
 	slow_ptr = slow_ptr -> next;

	while(fast_ptr -> next != NULL && fast_ptr != NULL){

		if(fast_ptr == slow_ptr) break;

		fast_ptr = fast_ptr -> next -> next;
		slow_ptr = slow_ptr -> next;
	}

	return fast_ptr==slow_ptr;
}

int main()
{
	// Creating a Linked List 
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	// Creating a Loop in our LinkedList
	head->next->next->next->next->next = head->next->next;

	// Calling Function to detect presence of Loop
	bool found = detectLoop(head);

	if (found) 
		cout << "Loop Found";
	else 
		cout << "No Loop Found";

	return 0;
}
