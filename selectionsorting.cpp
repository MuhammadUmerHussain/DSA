#include<iostream>

using namespace std;

void rec(int arr[],int i,int j,int n,int min)
{

	if(i==n)
	{
		for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
		return;
	}
	
	else if(j==n)
	{
		//cout<<min<<endl;
		//cout<<min<<endl;
		if(min!=i)
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[min];
			//cout<<arr[i]<<endl;
			arr[min]=temp;
			//cout<<arr[min]<<endl;
		}
		rec(arr,i+1,i+2,n,i+1);
	}
	else
	{
		//cout<<min<<endl;
		//cout<< i << " "<< j<<endl;
		if(arr[j]<arr[min])
		{
			
			min=j;
			
			
			
		}
		
		
		rec(arr,i,j+1,n,min);
		
	}
}


int main()
{
	int min=0;
	int arr[]={7,4,10,8,3,1};
	rec(arr,0,1,6,min);
}
