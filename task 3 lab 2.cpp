#include<iostream>
using namespace std;

int main()
{
	int *max;
	int a=0;
	int b=9;
	int *min;
	int arr[20];
	max=new int[10];
	min=new int[10];
	for(int i=0;i<10;i++)
	{
		cout<<"Input "<<i+1<<endl;
		cin>>max[i];
	//max[i]=i;
	}
	int temp;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		if(max[i]>max[j])
		{
			temp=max[i];
			max[i]=max[j];
			max[j]=temp;
		}
	}
		for(int i=0;i<10;i++)
	{

		//cout<<max[i]<<" ";
	}


	
	for(int i=0;i<10;i++)
	{
		if(i%2==0)
		{
			arr[i]=max[a];
			a++;
		}
		else{
			arr[i]=max[b];
			b--;
		}
		cout<<arr[i]<<" ";
	}
	
	
}
