#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rows;
int cols;
void issafe(char **arr,int i,int j,string word);
string SPACE(string a)//check spaces as my function of string was not working taken help from greek for greek
{
	a.erase(remove(a.begin(),a.end(),' '),a.end());
	return a;
}
void input()
{
	cin>>rows;
	cin>>cols;
	char **maze=new char*[rows];
	for(int i=0;i<rows;i++)
	{
		maze[i]=new char[cols];
	}
	
	for(int i=0;i<rows;i++)
	{
	for(int j=0;j<cols;j++)
		{
		cin>>maze[i][j];}}
//	for(int i=0;i<rows;i++)
//	{
//	for(int j=0;j<cols;j++)
//		{
//		cout<<maze[i][j]<<" ";}
//		cout<<endl;}
	string word;
	cin>>word;
	//getline(cin,word);
	
	word=SPACE(word);
	//cout<<word;
	
	
	for(int i=0;i<rows;i++)
	for(int j=0;j<cols;j++)
	{
		if(maze[i][j]==word[0])
		{
			issafe(maze,i,j,word);
		}
		}	
		
		
}

bool checkdown(char **arr,int i,int j,string word,int z)
{
	//cout<<i<<" "<<z<<"***"<<word.length()<<endl;
	if(i>rows)
	{
		return false;
	}
	if(z>=word.length())
	{
		//cout<<word.length()<<endl;
		return true;
	}
	
	
	//cout<<i<<" "<<endl;
		if(arr[i][j]==word[z]|| arr[i][j]=='+')
		{
			//cout<<arr[i][j]<<" "<<word[z]<<endl;
			if(checkdown(arr,i+1,j,word,z+1))
			{
				return true;
			}
		}
		
	
	return false;
}
bool checkup(char **arr,int i,int j,string word,int z)
{
	if(i<0)
	{
		return false;
	}
	if(z>=word.length())
	{
		
		return true;
	}
	
	
	{
		if(arr[i][j]==word[z]|| arr[i][j]=='+')
		{
			if(checkup(arr,i-1,j,word,z+1))
			{
				return true;
			}
		}
		
	}
	return false;
}
bool checkright(char **arr,int i,int j,string word,int z)
{
	if(j>cols)
	{
		return false;
	}
	if(z>=word.length())
	{
		return true;
	}
	
	
	{
		if(arr[i][j]==word[z]|| arr[i][j]=='+')
		{
			if(checkright(arr,i,j+1,word,z+1))
			{
				return true;
			}
		}
		
	}
	return false;
}

bool checkleft(char **arr,int i,int j,string word,int z)
{
	if(j<0)
	{
		return false;
	}
	if(z>=word.length())
	{
		return true;
	}
	
	
	{
		if(arr[i][j]==word[z]|| arr[i][j]=='+')
		{
			if(checkleft(arr,i,j-1,word,z+1))
			{
				return true;
			}
		}
		
	}
	//cout<<"*";
	return false;
}
void issafe(char **arr,int i,int j,string word)
{
	//cout<<i<<" "<<j<<" "<<endl;
	if(checkdown(arr,i,j,word,0))
	{
		cout<<"Down"<<endl;
	}
	if(checkup(arr,i,j,word,0))
	{
		cout<<"UP"<<endl;
	}
	if(checkright(arr,i,j,word,0))
	{
		cout<<"Right"<<endl;
	}
	if(checkleft(arr,i,j,word,0))
	{
		cout<<"left"<<endl;
	}
}

int main()
{
	input();
	
}
