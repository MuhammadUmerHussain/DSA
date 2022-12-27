#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string rec(string a)
{
	if(a=="")
	{
		return "";
	}
	
	else
	{
		return rec(a.substr(1))+a.at(0);
	}
}
int main()
{
	string a="hello";
	cout<<rec(a)<<endl;
	cout<<a;
	
	
}
