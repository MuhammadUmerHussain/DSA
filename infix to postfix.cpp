#include<iostream>
#include<stack>
using namespace std;

#define MAX 5000
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
int pre(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='/'|| c=='*')
	{
		return 2;
	}
	else if(c=='+'|| c=='-')
	{
		return 1;
	}
	else 
	{
		return -1;
	}
}

string infixtopostfix(string s)
{
     Stack st;
	
	string res;
	
	for(int i=0;i<s.length();i++)
	
	{
		
		
	if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z') )
	{
		
		
		res+=s[i];
	
	}
	else if(s[i]=='(')
	{
	//	cout<<"*";
	st.push(s[i]);
	}
	else if(s[i]==')')
	{
		
		
		
		while(!st.isEmpty()&& st.peek()!='(')
		{
			res=res+st.peek();
			
			st.pop();
		}
		if(!st.isEmpty())
		{
		st.pop();}
		
//		cout<<res<<endl;
		
		
	}
	else 
	{
		while((!st.isEmpty())&& (pre(st.peek())>pre(s[i])))
		{
			res=res+st.peek();
			st.pop();
		}
		st.push(s[i]);
	}
	
	
	
	
	}
	while(!st.isEmpty())
	{
		res=res+st.peek();
		st.pop();
	}
	return res;
	

}
int main()
{
	string s;
	cin>>s;
	cout<<infixtopostfix(s);
	
}
