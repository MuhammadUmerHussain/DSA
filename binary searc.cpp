#include<iostream>
using namespace std;


int binary(int arr[],int start,int end,int key)
{
	
	if(end>=start)
	{
		
	int mid=start+(end-start)/2;
	
		if(arr[mid]==key)
		{
			
			return mid;
		}
	
		else if(key>arr[mid])
		{
			
			return binary(arr,mid+1,end,key);
		}
		else
		{
			return binary(arr,start,mid-1,key);
		}}
	
}

int main()
{
	int arr[]={1,5,6,8,7,10};
	int search_number=10;
	int sizeofarray=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"AT INDEX: "<<binary(arr,0,sizeofarray,search_number);
}

