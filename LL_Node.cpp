#include <iostream>
using namespace std;

class Node
{
	public: 
		int data;
		Node* next;
		
		Node () 
		{
			data = 0;
			next = NULL;
		}
		Node (int d, Node* n)
		{
			data = d;
			next = n;
		}
};

void printList(Node* n){
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main(){
	Node* head = new Node(6, NULL);
	Node* second = new Node();
	Node* third = new Node();
	
	head->next = second;
	
	second->data = 8;
	second->next = third;
	
	third->data = 10;
	third->next = NULL;
	
	cout << "head: " << head << endl;
	cout << "head->next:  " << head->next << " = second: " << second << endl;
	
	cout << "head->next->data: " << head->next->data << endl; // data of second node.
	
	printList(head);
}
