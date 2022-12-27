#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	int priority;
	Node* next;
	
	Node(){
		data = 0;
		priority = 0;
		next = NULL;
	}
	Node(int d, int p){
		data = d;
		priority = p;
		next = NULL;
	}
};

// Queue using Linked List
class QueueLL{
	Node* front, *rear;
	
	public:
	QueueLL(){
		front = rear = NULL;
	}
	
	bool isEmpty(){
		return (rear == NULL);
	}
	
	void enqueue(int d, int p){
		Node* new_node = new Node(d, p);
		
		// if empty queue, then front and 
		// rear both point to new node
		if (isEmpty()){
			front = rear = new_node;
		}
		else{
			// front has lower priority then make new node front
			if (front->priority < p){
				new_node->next = front;
				front = new_node;
			}
			else{
				Node* temp = front;
				// traverse list to find position of d based on p.
				while (temp->next != NULL && temp->next->priority >= p){
					temp = temp->next;
				}
				new_node->next = temp->next;
				temp->next = new_node;
			}
		}
	}
	
	int peek(){
		if (isEmpty()){
			return INT_MIN;
		}
		return front->data;
	}
	
	int dequeue(){
		if (isEmpty()){
			return INT_MIN;
		}
		
		// hold front node in temp to delete later
		// make next node as front
		Node * temp = front;
		front = front->next;
		
		// if the only element of queue was 
		// dequeued then the queue becomes empty
		if (front == NULL){
			rear = NULL;
		}
		
		delete temp;
	}
	
	// Count?
	
	void display(){
		if (isEmpty())
			return;
		
		cout << "\displaying stack elements:" << endl;
		Node* t = front;
		while(t != NULL){
			cout << t->data << " " << t->priority << endl;
			t = t->next;
		}
	}
};

int main(){
	QueueLL q;
	cout << "Enqueue 10, 20, and 30 to the Queue."<<endl;
	q.enqueue(10, 1);
	q.enqueue(20, 2);
	q.enqueue(30, 3);
	q.enqueue(40, 3);
	q.enqueue(50, 0);
	q.display();
	cout << "Peek: "<<q.peek() << endl;
	cout << "Dequeue: "<<q.dequeue() << endl;
	cout << "isEmpty: "<<q.isEmpty() << endl;
	q.display();
	return 0;
}
