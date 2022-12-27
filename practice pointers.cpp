#include<iostream>
using namespace std;

int main()
{
	int a=5;
	int b=9;
	int *p;
	int ar[5]={1,2,3,4,5};
	int VAR;
	VAR=0;

	for(p=ar;p<ar+5;p++)
	{
		VAR=VAR+*p;
	}
	int *mem;
	for(int i=0;i<=5;i++)
	{
		mem=new int[i];
		*(mem+i)=i;
		cout<<*(mem+i)<<endl;
	}
}
