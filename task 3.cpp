#include<iostream>

using namespace std;

float premium();
float regular();
int unit();
int main()
{
	char r;
	cout<<"  ABC Telephone Company"<<endl;
	
	unit();
	
	cout<<"Enter R for Regular:"<<endl;
	cin>>r;
	
	
}

int unit()
{
	char select;
	
	float temp;
	cout<<"Press P For Premimum OR Press R For Regular Customer"<<endl;
	cin>>select;
	
	
	if(select=='r'|| select=='R')
	{
	 temp=regular();
	 cout<<"Your Bill Is = $"<<temp<<endl;
	}
	
	
}

float regular()
{
	int units;
	float extra;
	float rates;
	cout<<"Enter Number Of Units"<<endl;
	cin>>units;
	
	if(units>50)
	{	
		
		extra=units-50;
		rates=(0.2*extra)+10;
		return rates;
		
	}
	else if(units<50)
	{
		rates=10;
		return rates;
	}
}

float premium()
{
	int SHH,SMM;
	int EHH,EMM;
	
	
	float extra;
	float rates;
	cout<<"Enter Time Of Call HH:MM"<<endl;
	cin>>SHH;
	cout<<"Enter Ending Time Of Call"<<endl;
	cin>>EHH;
	
	
	
}
