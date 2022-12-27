#include<iostream>
#define SIZE 9
using namespace std;

void gamerow(int **arr,int i,int j)//calculating rows SUM
{
	static int sum=0;
	if(i==SIZE)//TILL SIZE
	{
		return;
	}
	else if(j==SIZE-1)
	{

		arr[i][j]=45-sum;
		//cout<<arr[i][j-1]<<endl;
	
		//cout<<sum<<endl;
		
	
		sum=0;
		
		gamerow(arr,i+1,0);
	}
	
	else{
		
		//cout<<arr[i][j]<<" ";
		sum=sum+arr[i][j];
		//cout<<sum<<endl;
		gamerow(arr,i,j+1);
	}
	
}
void gamecol(int **arr,int j,int i)//Caculating Sum Of Columns
{
	static int sum2=0;
	
	if(j==SIZE-1)
	{
		return;
	}
	else if(i==SIZE-1)
	{
		arr[i][j]=45-sum2;
		sum2=0;
		gamecol(arr,j+1,0);
	}
	else
	{
		sum2=sum2+arr[i][j];
		gamecol(arr,j,i+1);
		
	}
}

void input(int **arr)

{
	for(int i=0;i<SIZE-1;i++)
	{
		for(int j=0;j<SIZE-1;j++)
		{
		cin>>arr[i][j];}
	}
	
}
void print(int **arr)
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
		cout<<arr[i][j]<<" ";}
		cout<<endl;
	}
	
	
}

int main()
{
	int **arr=new int*[SIZE];
	for(int i=0;i<SIZE;i++)
	{
		arr[i]=new int[SIZE];
	}
	input(arr);
	gamecol(arr,0,0);
	gamerow(arr,0,0);
	print(arr);
}
