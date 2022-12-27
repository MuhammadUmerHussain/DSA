#include<iostream>
using namespace std;


void insert(int arr[],int n)
{
	int temp;
	int j;
	for(int i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int arr[]={4,5,10,1,6,2};
	insert(arr,6);
}
