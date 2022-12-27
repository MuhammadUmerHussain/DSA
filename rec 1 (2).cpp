#include<iostream>
using namespace std;
int recur(int n,int s,int range)
{
if(range==0)
{
	return 1;
}
else {
	range--;
	n++;
	s=s+n;
	cout<<s<<" ";
	return recur(n,s,range);
	
}
}

int main()
{
	int n=1;
	int s=1;
	int range=7;
	recur(n,s,range);
}

