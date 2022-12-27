#include <iostream>
using namespace std;

class Node
{
	public: 
		int data;
		Node* next;
		Node* prev;
		
		Node () 
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}
		Node (int d, Node* n, Node* p)
		{
			data = d;
			next = n;
			prev = p;
		}
};

class DoublyLinkedList{
	Node* head;
	Node* tail;
	int size;
	
	public:
		// Default constructor
	    DoublyLinkedList() { head = NULL; tail = NULL; }
	  
	    // Function to print the linked list.
	    void printList(){
	    	Node* temp = head;
		    while (temp != NULL) {
		        cout << temp->data << " ";
		        temp = temp->next;
		    }
		    cout << "\n";
		}
		
		// Insert at the end
		void push_back(int data){
			
			// make new node and set its data and set its next as NULL
	  		Node* new_node = new Node(data, NULL, NULL);
	  		
	  		// If the Linked List is empty,
		    // then make the new node as head
		    if (head == NULL)
		    {
		        head = new_node;
		        tail = new_node;
		        return; 
		    }
	  		
	  		tail->next = new_node;
	  		new_node->prev= tail;
	  		tail = new_node;
	  		
	  		size++;
		}
		
		// Insert after a given node
		void insertAfter(Node* given_node, int data) {
			// Return if given given_node is NULL
		    if (given_node == NULL) 
		    { 
		        cout << "the given previous node cannot be NULL"; 
		        return; 
		    }
			// make new node and set its data
	  		Node* new_node = new Node(data, NULL, NULL);
	  		
	  		// assign next node as next of new node
	  		new_node->next = given_node->next;
	  		
	  		// assign next of given node as new node
	  		given_node->next = new_node;
	  		
	  		/*
			  ### Different from SLL ###
			*/
	  		new_node->prev = given_node;
	  		new_node->next->prev = new_node;
	  		
	  		if (given_node == tail){
	  			tail = new_node;
			}
	  		
	  		size++;
		}
		
		// Insert before a given node - huge advantage over SLL
		void insertBefore(Node* given_node, int data) {
			// Return if given given_node is NULL
		    if (given_node == NULL) 
		    {
		        cout << "the given previous node cannot be NULL"; 
		        return;
		    }
			// make new node and set its data
	  		Node* new_node = new Node(data, NULL, NULL);
	  		
	  		// next of new node becomes given node
	  		new_node->next = given_node;
	  		
	  		// prev of new node becomes given node's prev
	  		new_node->prev = given_node->prev;
	  		
	  		// next of prev node of given node becomes new node
			given_node->prev->next = new_node;
			
			// new node becomes previous of given node
	  		given_node->prev = new_node;
	  		
	  		size++;
		}
		
		// Delete from head
		// Delete from tail
		// delete node with a value (first occurence)
		
		// Delete List - same as SLL
		deleteList(){
			if (head != NULL){
				Node *temp;		// to iterate
				Node *curr = head;
				
				while(curr != NULL){
					temp = curr; // hold temp to delete later on
					curr = curr->next;
					delete temp;
				}
			}
		}
		
		// Copy constructor
		DoublyLinkedList(const DoublyLinkedList& obj){
			head = NULL;
			tail = NULL;
			Node *temp_node = obj.head;	// to iterate through obj's list
			Node *last_node = NULL, *n = NULL;
			
			while(temp_node!=NULL){
				n = new Node(temp_node->data, NULL, NULL);
				
				if (head == NULL){
					head = n;
				}
				else{
					n->prev = last_node;	// Diff
					last_node->next = n;
				}
				last_node = n;
				temp_node = temp_node->next;
			}
			tail = last_node;	// Diff
		}
		
		// Assignment operator - same as SLL
		DoublyLinkedList& operator=(const DoublyLinkedList& obj){
			if (this != &obj){
				deleteList();
				Node *temp_node = obj.head;	// to iterate through obj's list
				Node *last_node = NULL, *n = NULL;
				
				while(temp_node!=NULL){
					n = new Node(temp_node->data, NULL, NULL);
					
					if (head == NULL){
						head = n;
					}
					else{
						n->prev = last_node;
						last_node->next = n;
					}
					last_node = n;
					temp_node = temp_node->next;
				}
				tail = last_node;
			}
			return *this;
		}
		
		// Destructor -  same as SLL
		~DoublyLinkedList(){
			deleteList();
		}
		
		// Search value in list - same as SLL
		bool isInList(int val){
			Node* temp = head;
			while(temp != NULL){
				if (temp->data == val){
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
		
		// reverse Linked List - same or different???
		void reverseList() {
		    Node* current = head;
		    Node* next = NULL;
		    Node* prev = NULL;
		    
		    while (current != NULL) {
		    	
		    	// Set tail // Diff
		    	if (current->prev == NULL){
		    		tail = current;
				}
				
		    	// keep head pointing to current
		    	head = current;
		    	
		    	// save next before reversing link 
				// otherwise next node cannot be accessed
		    	next = current->next;
		    	
		    	// reverse link
		    	current->next = prev;
		    	current->prev = next;	// Diff
		    	
		    	// move previous and current to their respective next nodes
		    	prev = current;
		    	current = next;		        
		    }
		}
};

int main(){
	DoublyLinkedList dll;
//	cout << "\nPush front 2 4 6\n";
//	dll.push_front(2);
//	dll.push_front(4);
//	dll.push_front(6);
//	dll.printList();
	
	cout << "\nPush back 8 10 12\n";
	dll.push_back(8);
	dll.push_back(10);
	dll.push_back(12);
	dll.printList();
	
//	cout << "\nDelete 10\n";
//	dll.deleteNode(10);
//	dll.printList();
//	
//	cout << "\nDelete from head\n";
//	dll.deleteFromHead();
//	dll.printList();
//	
//	cout << "\nDelete from tail\n";
//	dll.deleteFromTail();
//	dll.printList();
	
	cout << "\nFind 2 in list\n";
	cout << dll.isInList(2);
	
	cout << "\nreverseList\n";
	dll.reverseList();
	dll.printList();
	
	cout << "\nCopy constructor\n";
	DoublyLinkedList dll2(dll);
	dll2.printList();
}
