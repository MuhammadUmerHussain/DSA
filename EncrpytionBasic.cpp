#include <iostream>
using namespace std;

int main()
{
	char ch[100];
	int i,j,counter=0;
	char vowel[5]={'a','e','i','o','u'};
	cout << "Please enter a string:\n";
	cin >> ch;
	
	for(i=0;i<100&&ch[i]!='\0';i++)
	{
		for(j=0;j<5;j++)
		{
		
	if(ch[i] == vowel[j])
	{
		ch[i] = ch[i]+3;
		break;
	}
	else
	{
		ch[i]= ch[i]-2;
		break;
	}
	}}
	
	
	cout << "String is :"<<ch;
}
