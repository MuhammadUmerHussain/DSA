#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream edit;
	edit.open("Umer.txt",ios::out);
	
	edit<<"Umer!";
	
	edit.close();
	
	string str;
	ifstream editH;
	editH.open("Umer.txt",ios::in);
	
	
	editH>>str;
	cout<<str;
	
	edit.close();
	
}
