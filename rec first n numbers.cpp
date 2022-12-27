#include<iostream>

using namespace std;


int rec(int n)
{
	int res;
	if(n==1)
	{
	
		return 1;
	}
	else
	{
		res=rec(n-1);
		return n+res;
	}
}

int main()
{
	cout<<rec(3);
}
