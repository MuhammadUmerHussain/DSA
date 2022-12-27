#include<iostream>
using namespace std;

void print(int arr[],int start,int end);
int MAX_SUB_ARRAY(int arr[],int n)
{
	int ans=0;
	int sum=0;
	int start;
	int end=0;
	int start2=0;
	for(int i=0;i<n;i++)
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
		
	}
	print(arr,start,end);
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
	cout<<MAX_SUB_ARRAY(arr,n);
	
	
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