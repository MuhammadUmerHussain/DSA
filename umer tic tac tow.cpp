#include<iostream>
using namespace std;
int tic[3][3];
void set_to_zero()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			tic[3][3]=0;
		}
	}
}

bool checkdifference(int tic[3][3])
{
	int count1=0;
	int count2=0;
  	for(int i=0;i<3;i++)
  	{
  		for(int j=0;j<3;j++)
  		{
  			if(tic[i][j]==1)
  			{
  				count1++;
			  }
			else if(tic[i][j]==2)
			{
				count2++;
			}
  			
		  }
	  }
	  int check=count1-count2;
	  if(check==1 || check==0)
	  {
	  	return true;
	  }
	  else
	  {
	  	return false;
	   } 
}
bool rows()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
		if(tic[i][j]==1 &&tic[i][j+1]==1 && tic[i][2]==0)
		{
		cout<<"one wins!";
		return true;	
		}
		else if(tic[i][j]==2&& tic[i][j+1]==2 && tic[i][2]==0)
		{
			cout<<"two wins!";
		}
		
				
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
			if(tic[i][j]==1 && tic[i][j+1]==0 && tic[i][j+2]==1 )
			{
				cout<<"one wins!"<<endl;
			}
			}
			
		}
		
	}
}
void print(int tic[3][3])
{
	if(checkdifference(tic))
	{
		cout<<"true";
	}
	else 
	{
		cout<<"false";
	}
	rows();
	
}
int main()
{

	for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin >> tic[i][j];
            }
        
		}
	print(tic);	
}
