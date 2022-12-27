#include<iostream>

using namespace std;

class bankaccount{
	
	protected:
	 int accountno;
	double balance;
	static int number;
	
	public:
		
		bankaccount()
		{
			accountno=number++;
		}
		bankaccount(double y):balance(y)
		{
			accountno=number++;
		}
	void setaccountno(int x)
	{
		accountno=x;
		}	
	
	int getaccountno()
	{
		return accountno;
		}	
	double getbalance()
	{
		return balance;
		}	
	
	void deposit(int x)
	{
		balance=balance+x;
		}	
	void withdraw(int x)
	{
		balance=balance-x;
		}	
	void print()
	{
		cout<<"Balance:"<<getbalance();
		cout<<"Account Number: BA"<<getaccountno();
		}	
};

int bankaccount::number=11101;

class checkingAccount:public bankaccount
{
	 float intrest;
	 int minbalance;
	 float servicecharge;
	
	public:
		checkingAccount()
		{
			accountno=number++;
		}
		checkingAccount(double x,float y,int z,float a):bankaccount(x),intrest(y),minbalance(z),servicecharge(a)
		{
			accountno=number++;
			
			}
		void setminbalance(int x)
		{
			minbalance=x;
		}
		void setservicecharge(float x)
		{
			servicecharge=x;
		}
		void setintrest(float x)
		{
			intrest=x;
		}
		int getminbalance()
		{
			return minbalance;
		}
		float getservicecharge()
		{
			return servicecharge;
		}
		float getintrest()
		{
			return intrest;
		}
		
		void check()
		{
			if(balance<minbalance)
			{
			cout<<"Balance is less than minbalance:"<<endl;
			
			servicecharge=servicecharge+balance;
			
			}
		}
		void withdraw(int x)
		{
			balance=balance-x;
		}
		void calculate()
		{
			
		}
		
		void printinfor()
		{
			
		cout<<"Minimum Balance:"<<getminbalance()<<endl;
		cout<<"Intrest Rate:"<<getintrest()<<endl;
		cout<<"Service Charge:"<<getservicecharge()<<endl;
		}
		void Alldetail()
		{
		cout<<"Balance:"<<getbalance()<<endl;
		cout<<"Account Number: BA"<<getaccountno()<<endl;
		cout<<"Minimum Balance:"<<getminbalance()<<endl;
		cout<<"Intrest Rate:"<<getintrest()<<endl;
		cout<<"Service Charge:"<<getservicecharge()<<endl;
		
		}
		
};

int main()
{
	checkingAccount a[2];
	a[0]=checkingAccount(100000,2.5,100,239.9);
	a[1]=checkingAccount(1000022,2.333,199,23.2);
	
	for(int i=0;i<2;i++)
	{
		a[i].Alldetail();
	}
}
