#include<iostream>

using namespace std;

int rows=5;
int cols=5;
int posr;
int posc;
static int count=0;
bool ISSAFE(char arr[][5],int i,int j)
{
	//cout<<i<<"   "<<j<<endl;
	//cout<<arr[i][j]<<endl;
	if(j<cols && i<rows &&arr[i][j]=='T')
	{
		
		return true;
	}
	return false;
}
//bool checktre(char arr[][5],int i,int j)
//{
//	if(i>=rows || j>=cols|| i<0 || j<0)
//	{
//		//cout<<count<<endl;
//		count=0;
//	}
//	//cout<<i<<"    "<<j<<"U "<<endl;
//	if(ISSAFE(arr,i,j))
//	{	arr[i][j]='*';
//	//cout<<posr<<"  "<<posc<<endl;
//		count++;
//		checktre(arr,i+1,j);
//		}
//	i=posr;
//	if(j==0)
//	{
//		j=poc+1;
//	}
//	j=posc+j;
//	if(ISSAFE(arr,i,j))
//	{	arr[i][j]='*';
//		count++;
//		checktre(arr,i,j+1);
//	}
//		i=posr;
//		j=posc-1;
//		if(ISSAFE(arr,i,j))
//		{
//			arr[i][j]='*';
//			checktre(arr,i,j-1);
//		}
//		i=posr;
//		j=posc;
//		if(ISSAFE(arr,i,j)) 
//		{
//			arr[i][j]='*';
//			checktre(arr,i-1,j);
//		}
//		i=posr-1;
//		j=posc-1;
//		if(ISSAFE(arr,i,j))
//		{
//			arr[i][j]='*';
//		checktre(arr,i-1,j-1);
//		}
//		i=posr+1;
//		j=posc+1;
//		if(ISSAFE(arr,i,j))
//		{
//			arr[i][j]='*';
//			checktre(arr,i+1,j+1);
//		}
//}

void checktree(char arr[][5],int i,int j,int n)
{
	if(i<0|| j<0 ||j>=n||i>=n||arr[i][j]!='T')
	{
		cout<<"   "<<count<< "    "<<i <<"   " <<j<<"out"<<endl;
		return;
	}
	cout<<i<<" "<<j<<endl;
	count++;
	arr[i][j]='*';
	
	checktree(arr,i+1,j,n);
	checktree(arr,i-1,j,n);
	checktree(arr,i,j+1,n);
	checktree(arr,i,j-1,n);
}
void input()
{
	int max=0;
	char **arr=new char*[rows];
	for(int i=0;i<rows;i++)
	{
		
		arr[i]=new char[cols];
	}
	 char arr2[5][5]={	   {'T','T','T','W','W'},
		   				   {'T','W','W','T','T'},
						   {'T','W','W','T','T'},
					       {'T','W','T','T','T'},
					       {'W','W','T','T','T'}
					       };
	for(int i=0;i<rows;i++)
	{for(int j=0;j<cols;j++)
	{
		if(arr2[i][j]=='T')
		{
		count=0;
		checktree(arr2,i,j,5);
		if(max<count)
		{
			max=count;
		}}
		
	}
	cout<<endl;
						   }
	cout<<count<<endl;					   
	for(int i=0;i<rows;i++)
	{for(int j=0;j<cols;j++)
	{
		
		cout<<arr2[i][j]<<" ";
		
	}
	cout<<endl;
						   }				       					   				       
					 
}

int main()
{
	input();
	
}
