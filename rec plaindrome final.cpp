#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//int main()
//{
//    string str = "geeksforgeeks";
// 
//    // Reverse str[begin..end]
//    reverse(str.begin(), str.end());
// 
//    cout << str;
//    return 0;
//}
//#include<cstring>
//using namespace std;
//
void rec(string a,string temp,int n)
{
	static int count=0;
	static int i=0;
	if(i==n)
	{
		cout<<"Palindrome"<<endl;
		return;
	}
	else
	{
		if(a[i]==temp[i])
		{
			count++;
			i=i+1;
			rec(a,temp,n);
		}
		
		else{
			cout<<"NOt"<<endl;
		}
		
	}
	
	
}

int main()
{
	string a="umer";
	int n=a.length();
	
	string temp=a;
	reverse(a.begin(),a.end());
	rec(a,temp,n);
}
