#include<iostream>
#include<fstream>
#include<istream>
#include<ostream>
#include<cstring>
using namespace std;

char chara[26];//saving it globally
void makecharacter()//saving in array
{
	int i=0;
	
	char  alpha='A';
	for(i=0;i<26;i++)
	{
		chara[i]=alpha;
		alpha++;
//		if(alpha==91)
//		{
//			break;
//		}
	}
}
int join(char a,char b)//making a two digit number
{
	int x;
	x=(a-'0')*10+(b-'0');
	return x;
}

int main()
{
	string array;
	
	int i=0;
	int check;
	
	makecharacter();
	
	ifstream input("Input.txt",ios::in);
	ofstream output("K200346.txt",ios::out);
	
	while(getline(input,array))//reading line by line
	{
		
		for(int i=0;i<array.length();i++){
		
		if(array[i]>='1' && array[i]<='9')//if number are two digit then this condition would apply
		{
			if(array[i+1]>='1'&& array[i+1]<='9')
			{
				check=join(array[i],array[i+1]);//here making e.g "1" and "2" to "12"
				if(check>26)//according to question printing z
				{
					cout<<chara[25];
					output<<chara[25];
				}
				else{ //else printing character by there order
				
				cout<<chara[check-1];
				output<<chara[check-1];}
	
				i++;
			} 
			else 
			{	check=array[i]-'0';//single digit printing
				if(check<0)//according to question if it is less than 0 then print Z
				{
					cout<<chara[25];
					output<<chara[25];
				}
				else
				{ //single digit character
				cout<<chara[check-1];
				output<<chara[check-1];}
			}
		}
		
	
	}
		
	}
	input.close();
	output.close();
}
