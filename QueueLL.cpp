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
		
	void enqueue(int d){
		Node* temp = new Node(d);
		
		// if empty queue, then front and 
		// rear both point to new node
		if (isEmpty()){
			front = rear = temp;
		}
		else{
			rear->next = temp;
			rear = temp;
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
			cout << t->data << endl;
			t = t->next;
		}
	}
};

int main(){
	QueueLL q;
	cout << "Enqueue 10, 20, and 30 to the Queue."<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout << "Peek: "<<q.peek() << endl;
	cout << "Dequeue: "<<q.dequeue() << endl;
	cout << "isEmpty: "<<q.isEmpty() << endl;
	q.display();
	return 0;
}
