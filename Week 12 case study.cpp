#include<iostream>
using namespace std;
class interface{
	
	public:
		virtual double salary()=0;
	
};
class Employee:public interface{
	
	string name;
	
	
	public:
		Employee()
		{
			
		}
		Employee(string y)
		{
			name=y;
		}
		
};

class hourly:public Employee{
	float noofhours;
	float hourlyrate;
	float overtime;
	public:
		hourly()
		{
			
		}
		hourly(string x,float a,float b,float c):Employee(x),noofhours(a),hourlyrate(b),overtime(c)
		{
			
		}
		
		double salary()
		{
			float temp;
			if(noofhours>40)
			{
				temp=noofhours-40;
				noofhours=40;
				return(noofhours*hourlyrate)+(temp*overtime);
			}
			else 
			return (noofhours*hourlyrate);
		}
	
};

class Weekly:public Employee{
	
	double weeklysalary;
	public:
	
	Weekly()
	{
		
		}
	Weekly(double x,string y):Employee(y),weeklysalary(x)		
		{
			
		}
	double salary()
	{
		return weeklysalary;
		}	
};
class Commission:public Employee{
	
	protected:
	float comissionrate;
	double grosSale;
	
	public:
		Commission()
		{
			
		}
		Commission(string x,double y,float z):Employee(x),grosSale(y),comissionrate(z)
		{
		
		}
	double salary()
	{
		return (comissionrate/100)*(grosSale);
		}	
		
};
class basecomission:public Commission{
	double base;
	
	public:
		basecomission()
		{
			
		}
		basecomission(string x,double y,float z,double perc):Commission(x,y,z),base(perc)
		{
			
		}
		
		double salary()
		{
			return ((Commission::salary())+base);
		}
	
};
int main()
{
	basecomission b("Umer",35000,2,25000);
	
	cout<<"Salary Of employee :"<<b.salary();
	hourly b1("Hamza",500,5,6);
	cout<<"\nHourly Rate Calculation:"<<b1.salary();
	return 0;
}
