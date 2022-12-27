#include<iostream>

using namespace std;

class Person
{
	int age;
	
	protected:
		string name;
		
	public:
		
		Person()
		{
		}
		Person(int x,string y)
		{
			age=x;
			name=y;
		}
		
		void setage(int x)
		{
			age=x;
		}
		void setname(string x)
		{
			name=x;
		}
		
		int getage()
		{
			return age ;
		}
		string  getname()
		{
			return name ;
		}
			
};

class Employee{
	
	int empid;
	protected:
	int	salary;
	public:
		
		Employee()
		{
			
		}
		Employee(int t,int c):empid(t),salary(c)
		{
		}
		
	void  setemid(int x)
		{
			empid=x;
		}
		
		int getempid()
		{
			return empid ;
		}
	void setsalary(int x)
		{
			salary=x;
		}
		int getsalary()
		{
			return salary;
		}		
};

class Manager:public Person,public Employee
{
	private:
		string type;
	public:
		
		Manager()
		{
		}
		Manager(int x,string y,int t,int c,string u):Person(x,y),Employee(t,c),type(u)
		{
		}
		void settype(string x)
		{
			type=x;
		}
		string gettype()
		{
			return type;
		}
};
class ITManager:public Manager
{
	private:
	int noOfPersons;
	public:
		ITManager()
		{
		}
		ITManager(int x,string y,int t,int c,string u,int z):Manager(x,y,t,c,u),noOfPersons(z)
		{
		}
		void setperson(int x)
		{
			noOfPersons=x;
		}
		int getperson()
		{
			return noOfPersons ;
		}
	void Display()
	{
		cout<<"Name:"<<getname()<<endl;
		cout<<"age:"<<getage()<<endl;
		cout<<"Id:"<<getempid()<<endl;
		cout<<"Salary:"<<getsalary()<<endl;
		cout<<"Type:"<<gettype()<<endl;
		cout<<"No Of Person:"<<getperson()<<endl;
	}
	
};

int main()
{
	Manager *o=new ITManager(22,"Umer",0346,10000000,"Head",5);
	
	o->Display();
}
