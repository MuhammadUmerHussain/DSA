#include<iostream>
#include<bits/stdc++.h>
//Instrucution 

//I have make seperate function of each beacause if we want to check down then we should go dowwn always not up
//Dyanmic memory Aloocation has been used
// Making all rows and cols global so that not every time we have to give parameter
//ISSafe is a fuction which se checking wheter to go up or doen etc
//Input for taking input
//Removing sapce is studied from greek for greek as it was not wroking without this


int row;//making row global
int col;//making column global
int no_of_words;//taking no of words 
using namespace std;
bool ISSAFE(string word,char **arr,int i,int j);
void checksWORD(char **arr,string words);
string checkspace(string str)//check spaces as my function of string was not working taken help from greek for greek
{
	str.erase(remove(str.begin(),str.end(),' '),str.end());
	return str;
}
void input()//making input function
{
	cin>>col;
	cin>>row;
	
	char **maze=new char*[row];//dynamic memory allocation
	for(int i=0;i<row+1;i++)
	{
		maze[i]=new char[col];//dynamic for columns
	}
	
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>maze[i][j];
		}
	}
	
	/*for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}*/
	
	cin>>no_of_words;//failed for making dyanmics for string
	//string arr_words;
	string arr_words[no_of_words+1];
	
	for(int i=0;i<no_of_words+1;i++)
	{
		getline(cin,arr_words[i]);
		arr_words[i]=checkspace(arr_words[i]);
		
	}
	
	
	for(int i=1;i<no_of_words+1;i++){
		checksWORD(maze,arr_words[i]);//giving word by word 
	}
}

void checksWORD(char **arr,string words)//words are recived 
{
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			
			if(arr[i][j]==words[0] || arr[i][j]=='+')
			{
				ISSAFE(words,arr,i,j);//checking words up down left right
			}
		}
	}
}

bool checkup(string word,char **arr,int i,int j,int z)
{
	//cout << "*" << arr[i][j] << ' ' << word[z] << endl;
	if(i<=0){
		return false;
	}
	if(z==word.length())
	{
		return true;
	}
	
	if(arr[i][j]=='*')
	{
		for(int start=z;start<word.length();start++ )
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
	if(arr[i][j]==word[z] || arr[i][j]=='+')
	{
		//cout << endl << arr[i][j] << ' ' << word[z] << endl;
		if(checkup(word,arr,i-1,j,z+1))
			return true;
	}
	return false;
	}
bool checkDown(string word,char **arr,int i,int j,int z)
{
	if(z>=word.length())
	{
		return true;
	}
	
	
	if(arr[i][j]=='*')
	{
		for(int start=z;start<word.length();start++ )
		{
			if(arr[i+1][j]==word[start])
			{
				if(checkDown(word,arr,i+1,j,start))
				{
					return true;
				}
			}
		}
		
	}
	if(arr[i][j]==word[z] || arr[i][j]=='+')
	{
		if(checkDown(word,arr,i+1,j,z+1))
		return true;
		
	}	
	return false;
	
	
}
bool checkRight(string word,char **arr,int i,int j,int z)
{
	if(z>=word.length())
	{
		return true;
	}
	
	if(arr[i][j]=='*')
	{
		for(int start=z;start<word.length();start++ )
		{
			if(arr[i][j+1]==word[start])
			{
				if(checkRight(word,arr,i,j+1,start))
				{
					return true;
				}
			}
		}
	}
	
	if(arr[i][j]==word[z] || arr[i][j]=='+')
	{
		if(checkRight(word,arr,i,j+1,z+1))
		return true;
	}	
	return false;
	
}

bool checkLeft(string word,char **arr,int i,int j,int z)
{
	if(z>=word.length())
	{
		return true;
	}
	
	if(arr[i][j]=='*')
	{
		for(int start=z;start<word.length();start++ )
		{
			if(arr[i][j-1]==word[start])
			{
				if(checkLeft(word,arr,i,j-1,start))
				{
					return true;
				}
			}
		}
	}	
	
	if(arr[i][j]==word[z] || arr[i][j]=='+')
	{
		if(checkLeft(word,arr,i,j-1,z+1))
		return true;
	}
		return false;
	
}
bool ISSAFE(string word,char **arr,int i,int j)
{
	if(checkup(word,arr,i,j,0))
	{
		cout<<i<<" "<<j<<" "<<'U'<<endl;
	}
	if(checkDown(word,arr,i,j,0))
	{
		cout<<i<<" "<<j<<'D'<<endl;
		//return true;
	}
	if(checkLeft(word,arr,i,j,0))
	{
		cout<<i<<" "<<j<<'L'<<endl;
		//return true;
	}
	if(checkRight(word,arr,i,j,0))
	{
		cout<<i<<" "<<j<<'R'<<endl;
		//return true;
	}
	else
	return false;
}
int main(){
	input();
	return 0;
}
