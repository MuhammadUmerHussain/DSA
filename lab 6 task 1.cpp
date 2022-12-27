#include<iostream>

using namespace std;

class Person
{
	
	
	protected:
		string name;
		int age;
		static int count;
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
int Person::count=0;


class Employee{
	
	
	protected:
	int	salary;
	int empid;
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
		
	public:
		string type;
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
		void Display()
		{
			cout<<"Name		1:"<<getname()<<endl;
		}
};
class ITManager:public Manager
{
	private:
	int noOfPersons;
	public:
		ITManager()
		{
			count++;
		}
		ITManager(int x,string y,int t,int c,string u,int z):Manager(x,y,t,c,u),noOfPersons(z)
		{
			count++;
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
		cout<<"Counter:"<<count<<endl;
	}
	ITManager(const ITManager &obj)
	{
		name=obj.name;
		age=obj.age;
		empid=obj.empid;
		salary=obj.salary;
		type=obj.type;
		noOfPersons=obj.noOfPersons;
		count++;
	}
	
};

int main()
{
	ITManager o(22,"Umer",0346,10000000,"Head",5);
	Manager *o1=&o;
	o1->Display();
	//ITManager *optr=&o1;
	//ITManager &oref=o;
	//..oref.Display();
	//optr ->Display();
	//o.Display();
}
