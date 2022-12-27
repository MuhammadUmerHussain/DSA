#include<iostream>

using namespace std;


int rec(int n)
{
	int sum=0;
	if(n<=0)
	{
		return 0;
	}
	else
	{
		sum=rec(n/10);
		return (n%10)+sum;
	}
}

int main()
{
	cout<<rec(127);
}
