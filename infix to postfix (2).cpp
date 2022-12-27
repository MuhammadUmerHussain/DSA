#include<iostream>
#include<stack>
using namespace std;

#define MAX 5000
class Stack{
	int top;
	char arr[MAX];
	
	
	public:
	Stack(){
		top = -1;
	}
	
	bool push(char c){
		if(top >= MAX-1)
			return false;
		
		top++;
		
		arr[top] = c;
		
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
		char c = arr[top];
		top--;
		return c;
	}
	
	int getTop(){
		return top;
	}
	
	
	void display(){
		if (isEmpty())
			return;
		
		cout << "elements:" << endl;
		for (int i = 0; i <= top; i++)
			cout << arr[i] << endl;
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
