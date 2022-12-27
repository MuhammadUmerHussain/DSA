#include <iostream>
using namespace std;

#define MAX 50

class Stack{
	int top;
	int arr[MAX];
	// size?
	
	public:
	Stack(){
		top = -1;
	}
	
	bool push(int d){
		// if stack is full
		if(top >= MAX-1)
			return false;
		
		top++;
		arr[top] = d;
		return true;
	}
	
	bool isEmpty(){
		return (top < 0);
	}
	
	int peek(){
		if (isEmpty()){
			return INT_MIN;
		}
		return arr[top];
	}
	
	int pop(){
		if (isEmpty()){
			return INT_MIN;
		}
		int d = arr[top];
		top--;
		return d;
	}
	
	int getTop(){
		return top;
	}
	
	// isFull?
	
	void display(){
		if (isEmpty())
			return;
		
		cout << "\n displaying stack elements:" << endl;
		for (int a = 0; a <= top; a++)
			cout << arr[a] << endl;
	}
};
int main()
{
	Stack s;
	Stack p;
	s.push(1);
	s.push(2);
	s.push(4);
	s.push(9);
	s.push(99);
	int max=s.peek();
	
	while(!s.isEmpty())
	{
		
		if(max<s.peek())
		{
			max=s.peek();
		}
		p.push(s.peek());
		s.pop();
	}
	while(!p.isEmpty())
	{
		
		if(p.peek()!=max)
		{
			s.push(p.peek());
			
		}
		p.pop();
	}
	//p.display();
	s.display();
	
}
