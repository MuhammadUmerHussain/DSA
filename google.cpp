#include<iostream>
using namespace std;

void ASSCI(int r,int c)
{
	int **arr;
	arr=new int*[r];
	for(int i=0;i<r;i++)
	{
		arr[i]=new int [c];
	}
	for(int i=0;i<r;i++)
	{
		
		for(int j=0;j<c;j++)
		{
		arr[i][j]=0;
		}
	}
	
	for(int i=0;i<2;i++)
	{
	for(int j=0;j<c;j++)
	{
		if((i==0 && j==0) || (i==0 && j==1) ||(i==1 && j==0) ||(i==1 && j==1) )
		{
			cout<<".";
			continue;
		}
		if(i%2!=0)
		{
			if(j%2==0)
			{
				cout<<"|";
			}
			if(j%2!=0)
			{
				cout<<".";
			}
		
		}
		if(i%2==0)
		{
			if(j%2==0)
			{
				cout<<"+";
			}
			if(j%2!=0)
			{
				cout<<"-";
			}
		}
	}
	cout<<endl;
	}
	
	for(int i=0;i<r-2;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i%2==0)
			{
				if(j%2==0)
				{
					cout<<"+";
				}
				if(j%2!=0)
				{
					cout<<"-";
				}
			}
			if(i%2!=0)
			{
				if(j%2==0)
				{
					cout<<"|";
				}
				if(j%2!=0)
				{
					cout<<".";
				}
			}
		}
		cout<<endl;
	}
//	for(int i=0;i<r;i++)
//	{
//		for(int j=0;j<c;j++)
//		{
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
}

int main()
{
	int a;
	cin>>a;
	if(a<1 || a>81)
		{
			cout<<"wrong input";
			exit(1);
		}
	int r=0 ,c=0;
	int *arrr=new int[a]; 
	int *arrc=new int[a];
	for(int i=0;i<a;i++)
	{
		
		cin>>r;
		if(r<2 || r>10)
		{
			cout<<"wrong input";
			exit(1);
		}
		r=(2*r)+1;
		arrr[i]=r;
		cin>>c;
		if(c<2 || c>10)
		{
			cout<<"wrong input";
			exit(1);
		}
		c=(c*2)+1;
		arrc[i]=c;
		
	}
	for(int i=0;i<a;i++)
	{
		ASSCI(arrr[i],arrc[i]);
		
	}
	
	
	
	
	
	
	
	
	
}
