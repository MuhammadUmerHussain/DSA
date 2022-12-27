#include<iostream>
using namespace std;


void rec(int arr[],int i,int j,int n)
{
	static int temp=arr[i];
	if(i==n)
	{
		for(int k=0;k<n;k++)
		{
		cout<<arr[k]<<" ";}
		return;
	}
	else if(j<0)
	{
		j=i-1;
		rec(arr,i+1,j,n);
	}
	else
	{
		if(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
			rec(arr,i,j,n);
		}
		j--;
		rec(arr,i,j,n);
	}
}
int main()
{
	int arr[]={5,4,10,1,6,2};
	rec(arr,1,0,6);
}
