#include <iostream>
using namespace std;

#define MAX 50

// Stack using Array
class Stack{
	int top;
	char arr[MAX];
	// size?
	
	public:
	Stack(){
		top = -1;
	}
	
	bool push(char d){
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
	
	char peek(){
		if (isEmpty()){
			return 'o';
		}
		return arr[top];
	}
	
	char pop(){
		if (isEmpty()){
			return 'o';
		}
		char d = arr[top];
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
		
		cout << "displaying stack elements:" << endl;
		for (int a = 0; a <= top; a++)
			cout << arr[a] << endl;
	}
};
void checkbrackets()
{
	char temp;
    string x;
    Stack s;
    cin>>x;

    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='('||x[i]=='['||x[i]=='{')
        {
            s.push(x[i]);
            
            
        }
        else if(x[i]==')'|| x[i]=='}'|| x[i]==']')
        {
        	if(!s.isEmpty())
            temp=s.pop();
            else if(s.isEmpty())
            {
			cout<<"No Match Found Break"<<endl;
			exit(1);
			}
			if(x[i]==')'&& temp=='(')
			{
				continue;
			}
			else if(x[i]=='}'&& temp=='{')
			{
				continue;
			}
			else if(x[i]==']'&& temp=='[')
			{
				continue;
			}
			else
			{
				cout<<"irregular brackets"<<endl;
				exit(1);
			}
			
        }
    }
    
    if(s.isEmpty())
    {
    	
        cout<<"Matching"<<endl;
    }
    else if(!s.isEmpty())
    {
    	cout<<"No Match Found "<<endl;
	}

	
}
int main()
{
	checkbrackets();
	}
