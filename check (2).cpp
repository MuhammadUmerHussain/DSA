#include<iostream>
using namespace std;

int main()
{
	bool Cd;
  	bool dVd;
  	string type;
		cout<<"Enter Your Disk Type:"<<endl;
		cin>>type;
		if(type=="Cd"|| type=="CD")
		  	{
		  		Cd=true;
			  }
			else if(type=="DVD"|| type=="dvd")
			{
				dVd=true;
			  }
			else 
			{
				cout<<"Your Disk Type Is Invalid Try To Input New Disk!"<<endl;
				throw(type);
				}    
	
	
}
