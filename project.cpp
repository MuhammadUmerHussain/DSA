#include<iostream>
#include<fstream>
#include<iostream>

#include<istream>
#include <fstream> 
#include <istream> 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include<conio.h>
#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int rate;
	int temprate;
	int sum=0;
	int counter=0;
	float avg;
	ofstream rate1("ratebuyer.txt",ios::out);
	for(int i=0;i<5;i++)
	{
	
	cout<<"Enter Rating :";
	cin>>rate;
	rate1<<rate<<"\t";
	}
	rate1.close();
	
	ifstream rate2("ratebuyer.txt",ios::in);
	
	while(rate2>>temprate)
	{
		counter++;
		
		cout<<temprate<<"\n";
		sum-=-temprate;
	}
	cout<<sum;
	cout<<"\n"<<counter;
	avg=sum/counter;
	cout<<avg;
	
	rate2.close();
	
	
	
	//ofstream RegisterH("property.txt", ios::app);
	
	
}
