
#include<iostream>
using namespace std;
int rec(int n,int s,int range)
{
	if(range==0)
	{
		return 1;
	}
	else{
		cout<<s<<" ";
		range--;
		s=n+s;
		n++;
		
		return rec(n,s,range);
	}
	
}

int main()
{
	int n=1;
	int s=1;
	int range=7;
	rec(n,s,range);
	
}
