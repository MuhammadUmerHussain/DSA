#include<iostream>
using namespace std;
void rec(char arr[],int i,int j,int n,int min)
{
	if(i==n)
	{
		for(i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		return;
	}
	else if(i==j)
	{
		
		j=n-1;
		min=arr[i+1];
		
		rec(arr,i+1,j,n,min);
	}
	else{
		if(min>arr[j])
		{
			int temp;
			temp=arr[i];
			min=arr[j];
			arr[i]=min;
			arr[j]=temp;
			
			
			
		}

		
		rec(arr,i,j-1,n,min);
	}
	
}

int main()
{
	char arr[]={'s','o','f','t','w','a','r','e'};

	rec(arr,0,7,8,'w');
}
