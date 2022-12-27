
#include<iostream>

using namespace std;

template<class t,int size>
class abc
{
	t arr[size];
	
	public:
	abc(t arr2[],int a)
	{
		if(size==a)
		{
		for(int i=0;i<a;i++)
		arr[i]=arr2[i];
		}
	}
	
	
	t sum()
	
	{
		int sum=0;
	for(int i=0;i<size;i++)
	
	{
		sum=sum+arr[i];
	}
	return sum;
	}
	
};

int main()
{
	int arr[2]={1,2};
	abc<int,2> obj(arr,2);
	cout<<"Sum="<<obj.sum()<<endl;
	
}
