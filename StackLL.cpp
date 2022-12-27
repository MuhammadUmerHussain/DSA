#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(){
		data = 0;
		next = NULL;
	}
	Node(int d){
		data = d;
		next = NULL;
	}
};

class Stack{
	Node* root;
	
	public:
		Stack(){
			root = NULL;
		}
		
		void push(int d){
			Node* n = new Node(d);
			n->next = root;
			root = n;
		}
		
		bool isEmpty(){
			return !root;
		}
		
		int peek(){
			if(isEmpty())
				return INT_MIN;
				
			return root->data;
		}
		
		int pop(){
			if(isEmpty())
				return INT_MIN;
			
			Node* temp = root;
			int d = temp->data;
			root = root->next;
			// use it when Node class's destructor 
			// doesn't delete next pointer.
			delete temp;	
			return d;
		}
		
		void display(){
			if(isEmpty())
				return;
			
			cout << "\displaying stack elements:" << endl;
			Node* t = root;
			while(t != NULL){
				cout << t->data << endl;
				t = t->next;
			}
		}
		
		// delete Stack?
};

int main(){
	Stack s;
	cout << "Add 10, 20, and 30 to the Stack."<<endl;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	cout << "Peek: "<<s.peek() << endl;
	cout << "Pop: "<<s.pop() << endl;
	cout << "Pop: "<<s.pop() << endl;
	s.display();
	cout << "Pop: "<<s.pop() << endl;
	cout << "isEmpty: "<<s.isEmpty() << endl;
	
	return 0;
}
