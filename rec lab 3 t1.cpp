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
	cout<<s<<" ";
	s=s+n;
	
	return recur(n,s,range);
	
}
}
void rec()
{
	int n=1;
	int s=1;
	int range=7;
	recur(n,s,range);
	
}

int main()
{
rec();	
}


