#include<iostream>
using namespace std;

void print(int arr[],int start,int end);
int MAX_SUB_ARRAY(int arr[],int n)
{
	int ans=0;
	int max=arr[0];
	int start;
	int sum=arr[0];
	int k=0;
	int end=0;
	int start2=0;
	for(int i=1;i<n;i++)
	{
		if(sum+arr[i]>0)
		{
			
			sum=sum+arr[i];
			
		}
		else
		{
			
			
			sum=0;
			start=i+1;
			
		}
		
		if(ans<sum)
		{
			ans=sum;
			end=i;
		}
		if(0>arr[i])
		{
			
			if(max<arr[i])
				{
					k=i;
				max=arr[i];
			}
		}
		
	}
	if(ans<=0)
	{
		cout<<arr[k]<<endl;
		return max;
	}
	else{
		print(arr,start,end);
	}
	
	return ans;
}
void input()
{
	int n;
	int *arr;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++)
	{
		
		cin>>arr[i];
	}
	//system("CLS");
	cout<<endl<<MAX_SUB_ARRAY(arr,n);
	
	
}
void print(int arr[],int start,int end)
{
	for(int i=start;i<=end;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	
	input();
	
}
