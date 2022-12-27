#include<iostream>
#include<bits/stdc++.h>

int row;
int col;
int no_of_words;
using namespace std;
bool ISSAFE(string word,string arr[],int i,int j);
string checkspace(string str)
{
	str.erase(remove(str.begin(),str.end(),' '),str.end());
	return str;
}
void input()
{
	cin>>col;
	cin>>row;
	
	char **maze=new char*[row];
	for(int i=0;i<row;i++)
	{
		maze[i]=new char[col];
	}
	
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>maze[i][j];
		}
	}
	
	cin>>no_of_words;
	string arr_words[no_of_words];
	
	for(int i=0;i<no_of_words;i++)
	{
		getline(cin,arr_words[i]);
		arr_words[i]=checkspace(arr_words[i]);
	}
	
	
}

void checksWORD(string arr[],string words)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(arr[i][j]==words[0] || arr[i][j]=='+')
			{
				ISSAFE(words,arr,i,j);
			}
		}
	}
}

bool checkup(string word,char **arr,int i,int j,int z)
{
	if(z==word.length())
	{
		return true;
	}
	if(arr[i][j]==word[z] || arr[i][j]=='+')
	{
		if(checkup(word,arr,i-1,j,z+1))
		return true;
		return false;
		
	}
	
	if(arr[i][j]=='*')
	{
		for(int start=i;start<word.length();start++ )
		{
			if(arr[i-1][j]==word[start])
			{
				if(checkup(word,arr,i-1,j,start))
				{
					return true;
				}
			}
		}
	}
	
	
}


bool ISSAFE(string word,char **arr,int i,int j)
{
	if(checkup(word,arr,i,j,0))
	{
		cout<<i<<" "<<j<<" "<<'U'<<endl;
		return true;
	}
}
int main(){
	input();
	return 0;
}
