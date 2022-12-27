#include<iostream>

using namespace std;

int main()
{
	int arr[5]={1,2,3,4,5};
	int aar[5];
	int max=arr[0];
	int min=arr[0];
	for(int i=0;i<5;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
		}
		if(min>arr[i])
		{
			min=arr[i];
		}
	}
	aar[0]=max;
	aar[1]=min;
	for(int i=0;i<2;i++)
	{
		cout<<aar[i]<<" ";
	}
	
}
