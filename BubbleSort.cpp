#include<iostream>
using namespace std;
void print (int ,int ,int );
void sort(int i,int j,int s,int arr[])
{
	
	int temp;
	if(i==s && j==s){
		return;	
	}
	else if(j==s)
	{
		return sort(i+1,0,s,arr);
	}
	else if(arr[i]<arr[j])
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
				
		
		}
		
	
	sort(i,j+1,s,arr);	
}




int main()
{
	int arr[3]={7,4,6};
	for(int i=0;i<3;i++)
		cout<<arr[i]<<" ";
	
	cout << endl;
	sort(0,0,3,arr);
	for(int i=1;i<4;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}
