#include<iostream>
using namespace std;

int main()
{
	int arr[]={1,5,10,4,7,30};
	int max=arr[0];
	int min=arr[0];
	int temp2;
	for(int i=0;i<6;i++)
	{	
		if(i%2==0)
		{
			
			for(int j=i;j<6;j++)
			{
				
				if(max<arr[j])
				{
					max=arr[j];
					temp2=j;
					
				}
			}
			//cout<<max<<" "<<temp2<<endl;
			int temp=arr[i];
			arr[i]=max;
			arr[temp2]=arr[i];
			max=INT_MIN;
		}
		else if(i%2!=0)
		{
			for(int j=i;j<6;j++)
			{
				if(min>arr[j])
				{
					min=arr[j];
					temp2=j;
				}
			}
			
			int temp=arr[i];
			arr[i]=min;
			arr[temp2]=temp;
			min=INT_MAX;
		}
	}
	
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
}
