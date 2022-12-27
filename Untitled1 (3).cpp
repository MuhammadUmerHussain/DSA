#include<iostream>
using namespace std;

int main()
{
	string arr;
	
	
	
	cout<<"Enter A string:\n";
	cin>>arr;
	
	
	
	for(int i=0;i<50;i++)
	{
		if(arr > 0 && arr<27)
		{
			if(arr[i]==1)
			{
				cout<<"a";
			}
			else if(arr[i]==2)
			{
				cout<<"b";
			}
		}
	}
}
