#include<iostream>

using namespace std;

class bank{
	
	string name;
	string address;
	string type;
	int id;
	static int accountno;
	double balance;
	int numbertrans;
	
	public:
		bank(string x,string y,string z,double a,int b):name(x),address(y),type(z),balance(a),numbertrans(b)
		{
			id=accountno++;
			
		}
		
		void output()
		{
			cout<<"BA"<<id;
		}
		
	
};

int bank::accountno=1000;

int main()
{
	bank b("Umer","468 h","gg",13212,2);
	b.output();
}
