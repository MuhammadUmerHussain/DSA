#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int row=3;
	int col=3;
	int count=0;
	int arr[row][col]={{1,0,0},
						{0,1,0},
						{0,0,1}};
	for(int i=0;i<row;i++)
	{
		for(int j=0;i<col;j++)
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
	if(count==row)
	{
		cout<<"Identity"<<endl;
	}
	else
	{
		cout<<"not";
	}
}
