#include<iostream>

using namespace std;

class office{
	
	string regions;
	string head;
	double expenditure;
	double sales;
	double profit;
	
	public:
	
	office(){
		profit=0;
		sales=0;
		expenditure=0;
	}
	
	office(string new_region,string new_head)
	{
		regions=new_region;
		head=new_head;
		profit=0;
		sales=0;
		expenditure=0;
	}
	
	void set_region(string new_region)
	{
		regions=new_region;
	}
	
	void set_head(string new_head)
	{
		head=new_head;
	 } 
	 
	void set_expenditure(double new_expenditure)
	{
		expenditure=new_expenditure;
	 } 
	 
	void  set_sales(double new_sales)
	{
		sales=new_sales;
	}
	
	void cal_profit()
	{
	profit=sales-expenditure;	
	}
	
	string get_region()
	{
		return regions;
	}
	
	string get_head()
	{
		return head;
	}
	
	double get_expenditure()
	{
		return expenditure;
	}
	
	double get_sales()
	{
		return sales;
	}
	
	double get_profit()
	{
		return profit;
	}
	
	void input_sales()
	{
		cout<<"Enter Sales:"<<endl;
		cin>>sales;
	}
	
	void input_expenditure()
	{
		cout<<"Enter Expenditure:"<<endl;
		cin>>expenditure;
	}
	void print_profit()
	{
		cout<<"Your Expenditure Is:"<<get_expenditure()<<endl;
		if(profit<=0)
		{
			cout<<"NO PROFIT THIS TIME"<<endl;
			
		}
		else
		cout<<"Your Profit Is:"<<profit<<endl;
		
		cout<<"Your Sales Is:"<<get_sales()<<endl;
		
		
	}
	
};


int main()
{
	office Universe7("Karachi","Umer");
	
	Universe7.input_sales();
	Universe7.input_expenditure();
	Universe7.cal_profit();
	Universe7.print_profit();
	return 0;
}

