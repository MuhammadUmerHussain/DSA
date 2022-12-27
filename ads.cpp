#include<iostream>
#include<string.h>
using namespace std;
class Account
{
    protected:
             string id;
             double balance;
    public:
    	Account()
    	{
		}
    Account(string a, double b)
    {
        id=a;
        cout<<a<<endl;
        balance=b;
        cout<<balance<<endl;
    }
     public:          
    virtual void booleanwithdraw(double amount)=0;
    virtual void deposit(double amount)=0; 
    void display();
      
};
class SavingsAccount : public Account
{
      public:
      void deposit(double amount)
      {
          int damt1;
          cout<<"\n Enter Deposit Amount = ";
          cin>>damt1;
          balance+=damt1;
      }
      public:
        void booleanwithdraw(double amount)
        {
             int wamt1;
             cout<<"\n Enter Withdraw Amount = ";
             cin>>wamt1;
            if(amount > 2)
            {
                cout<<"TRUE";
            }
			else if (amount < 10)
            {
                cout<<"FALSE";
            }
        balance-=wamt1;
        }
        void display()  
        {
        cout<<"\n id no"<<id;
        cout<<"\n Balance : "<<balance; 
            
        }
};
int main()
{
        int acc_no;
        char name[100], acc_type[100];
        float balance;
        cout<<"\n Enter Details: \n";
        cout<<"-----------------------";
        cout<<"\n Accout No. ";
        cin>>acc_no;
        cout<<"\n Name : ";
        cin>>name;
        cout<<"\n Account Type : ";
        cin>>acc_type;
        cout<<"\n Balance : ";
        cin>>balance;
  
        SavingsAccount obj;
        obj.deposit(100); 
        obj.booleanwithdraw(100);
        obj.display();
       
}
