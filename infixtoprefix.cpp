#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

#define MAX 100
class Stack{
	int top;
	char arr[MAX];
	int size;
	
	public:
	Stack(){
		top = -1;
		size=0;
	}
	
	bool push(char d){

		if(top >= MAX-1)
			return false;
		
		top++;
		
		arr[top] = d;
		size++;
		
		return true;
	}
	
	
	bool isEmpty(){
		cout<<"Stack is empty!";
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
		size--;
		return d;
	}
	
	int getTop(){
		return top;
	}
	
	bool isfull()
	{
		if(MAX-1==size)
		{
			cout<<"stack is full!"<<endl;
			return true;
		} 
		return false;
	}
	
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
	
	reverse(s.begin(),s.end());
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==')')
		{
			s[i]='(';
		}
		else if(s[i]=='(')
		{
			s[i]=')';
		}
	}
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
	reverse(res.begin(),res.end());
	return res;
	

}
int main()
{
	string s;
	cin>>s;
	cout<<infixtopostfix(s);
	
	Stack s;
	
//	for(int i=0;i<MAX;i++)
//	{
//		s.push('a');
//		cout<<i<<endl;
//	}
//	s.display();
//	
}
