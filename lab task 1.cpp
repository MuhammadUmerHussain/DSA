#include<iostream>
using namespace std;

int main()
{
	int count=0;
	int arr[3][3]={1,0,0,0,1,0,0,0,1};
	for(int i=0;i<3;i++)
	{
		for(int j=0;i<3;j++)
		{
			if(i==j)
			{
				if(arr[i][j]==1)
				{
				count++;	
				}
				
			}
		}
	}
	if(count==3)
	{
		cout<<"Identity"<<endl;
	}
	return 0;
}
