#include<iostream>

using namespace std;


 void rec(int n)
{
	static int count=0;
	if(n<=0)
	{
		cout<<count;
		return ;
	}
	else
	{
		count++;
		rec(n/10);
	}
	
}

int main()
{
	rec(50);
	
}
