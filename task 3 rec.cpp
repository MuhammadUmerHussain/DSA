#include<iostream>
using namespace std;
int rec(int arr[],int size,int i,int j)
{
	if(i==size)
	{
		return 0 ;
	}
	else if(j==size)
	{
		
	
		i++;
		
		j=0;
		
		return rec(arr,size,i,j);
	}
	else if(j<size)
	{
		//cout<<" *" <<" ";
		if(arr[i]<arr[j])
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		
		
		j++;
		return rec(arr,size,i,j);
	}
	
	
}
int main()
{
	int arr[]={12,11,13,5,6,7};
	rec(arr,6,0,0);
	for(int i=0;i<6;i++)
	cout<<arr[i]<<" ";
		
	
}
