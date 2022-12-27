#include<iostream>
using namespace std;
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

int main()
{
		int rate;
		double cnic1;
		ofstream rate1("ratebuyer.txt",ios::app);
	
		cout<<"Enter Rating :[1-5]";
	
		cin>>rate;
		cout<<"Enter Cnic:";
		cin>>cnic1;
		
		//while(1)
		{
		
		
		if(rate<=5)
		{
		
		rate1<<cnic1<<"\t"<<rate<<"\n";
		//break;
		}
		else 
		{
			cout<<"Enter Again!";
			cin>>rate;
		}
		rate1.close();}
		
		int cnic2;
		cout<<"Enter Cnic :";
		cin>>cnic2;
	int temprate;
	int tempcnic;
	int sum=0;
	int counter=0;
	float avg;
	ifstream rate2("ratebuyer.txt",ios::in);
	while(rate2>>tempcnic>>temprate)
	{
		
		if(tempcnic==cnic2)
		{
		cout<<tempcnic<<"\n";
		counter++;
		sum-=-temprate;}
	}
	avg=sum/counter;
	cout<<"Rating Of You Is"<<avg;
	
	rate2.close();
		}

