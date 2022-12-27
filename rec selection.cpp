#include<iostream>
using namespace std;
void rec(int arr[],int i,int j,int n)
{
	if(i==n)
	{
		return;
	}
	else if(i==j)
	{
		cout<<arr[i]<<" ";
		j=n-1;
		
		rec(arr,i+1,j,n);
	}
	else{
		if(arr[i]>arr[j])
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		//cout<<j<<" "<< i<<endl;
		
		rec(arr,i,j-1,n);
	}
	
}

int main()
{
	int arr[]={5,4,2};
	rec(arr,0,2,3);
}
