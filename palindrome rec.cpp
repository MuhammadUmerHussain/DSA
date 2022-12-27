#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool rec(string a)
{
	if(a.length()==1 || a.length()==0)
	{
		return true;
		
	}
	
	
		if(a.at(0)==a.at(a.length()-1))
		{
			cout<<a.substr(1,a.length()-1)<<endl;
			
			return rec(a.substr(1,a.length()-1));
			
		}
		else
		{
			cout<<a.at(a.length())<<endl;
		}
	
	
	
}
int main()
{
	string a="racecar";
	//cout<<strlen(a);
	cout<<rec("racecar");
	
	
}
