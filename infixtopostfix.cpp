#include<iostream>
using namespace std;
#include<stack>
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
	stack<char> stack;
	
	string res;
	
	for(int i=0;i<s.length();i++)
	{
		
	if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z') )
	{
		
		res+=s[i];
	
	}
	else if(s[i]=='(')
	{
	stack.push(s[i]);
		
	}
	
	
	
	}

}
int main()
{
	string s;
	cin>>s;
	infixtopostfix(s);
	
}