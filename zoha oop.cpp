#include<iostream>
using namespace std;
class account{
	protected:
		double account_balance;
		public:
			account()
			{
				account_balance=0;
			}
			account(double a)
			{
				if(a>=0)
				{
					account_balance=a;
				}
				else{
					account_balance=0;
					cout<<"BALANCE INALID!!"<<endl;
				}
			}
			void set_balance(double a)
			{
				if(account_balance>=0)
			{
					account_balance=a;
				}
				else{
					cout<<"BALANCE INVALID!!"<<endl;
				}
			}
			double get_balance()//
			{
				return account_balance;
			}
			
			void credit()   //THIS FUNCTION WILL ADD AMOUNT IN THE CURRENT BALANCE.
			{
					double amount1;
				cout<<"ENTER AMOUNT YOU WANT TO DEPOSIT:"<<endl;
				cin>>amount1;
			
				account_balance=amount1+account_balance;
				cout<<"AMOUNT AFTER DEPOSIT:"<<account_balance<<endl;
			}
			void debit()//THIS FUNCTION WILL WITHDRAW AMOUNT FROM THE CURRENT BALANCE.
			{
				double amount2;
				cout<<"ENTER AMOUNT YOU WANT TO WITHDRAW:"<<endl;
				cin>>amount2;
				if(amount2<account_balance)
				{
					account_balance=account_balance-amount2;
				
				 cout<<"AMOUNT AFTER DEPOSIT IS:"<<account_balance<<endl;
		    		cout<<account_function();
				}
				else
				{
					cout<<"DEBIT AMOUNT EXCEEDS ACCOUNT BALANCE"<<endl;
				}
				
			}
			bool account_function()
			{
				return true;
			}
};
class saving_account:public account{
	double intrest_rate;
	//setter
	public:
		saving_account()
		{
			
			
		}
		
		void set_intrest(double r)
		{
			intrest_rate=r;
		}
		double get_intrest()
		{
			return intrest_rate;
		}
		//constructor
		saving_account(double x,double y):account(x)
		{
			intrest_rate=y;
		}
	double calculate_intrest()
	{ 
	double amount;
	amount=account::get_balance()*intrest_rate;
	return amount;
	}
};
class checking_account:public account{
	double fee_charged;
	public:
		checking_account()
		{
			fee_charged=0;
		}
		checking_account(double x,double y):account(x)
		{
			fee_charged=y;
		}
		void set_fee(double x)
		{
			fee_charged=x;
		}
		double get_fee()
		{
			return fee_charged;
		}
		void credit()   
			{
					double amount1;
				cout<<"ENTER AMOUNT YOU WANT TO DEPOSIT:"<<endl;
				cin>>amount1;
			
				account_balance=amount1+fee_charged;
				cout<<"AMOUNT AFTER DEPOSIT:"<<account_balance<<endl;
			}
			void debit()
			{
				double amount2;
				cout<<"ENTER AMOUNT YOU WANT TO WITHDRAW:"<<endl;
				cin>>amount2;
				if(amount2<account_balance)
				{
					account_balance=account_balance-fee_charged;
				
				 cout<<"AMOUNT AFTER DEPOSIT IS:"<<account_balance<<endl;
		    		cout<<account_function();
				}
				else
				{
					cout<<"DEBIT AMOUNT EXCEEDS ACCOUNT BALANCE"<<endl;
				}}
};
int main()
{
	account obj;
	obj.set_balance(25000);
	obj.credit();
	obj.debit();
	saving_account obj1;
	obj1.set_intrest(200);
	obj1.calculate_intrest();
	checking_account obj3;
	obj3.set_fee(100);
	obj.credit();
	obj.debit();
}
