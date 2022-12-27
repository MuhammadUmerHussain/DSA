#include<iostream>
using namespace std;
class person{
	int age;
	protected:
		string name;
	public:
		person()
		{
			
		}
		person(string n,int a)
		{
			name = n;
			age = a;
		}
		void setName(string n)
		{
			name = n;
		}
		void setAge(int a)
		{
			age = a;
		}
		string getName() const
		{
			return name;
		}
		int getAge() const
		{
			return age;
		}
			
};
class Employee{
	unsigned int id;
	protected:
		double salary;
	public:
		Employee()
		{
			
		}
		Employee(int i,double s)
		{
			id = i;
			salary = s;
		}
		void setid(int i)
		{
			id = i;
		}
		void setSalary(double s)
		{
			salary = s;
		}
		int getId() const
		{
			return id;
		}
		double getSalary() const
		{
			return salary;
		}
		
};
class Manager: public person,public Employee
{
	string type;
	public:
		Manager()
		{
			
		}
		Manager(string n,int a,int i,double s,string t): person(n,a),Employee(i,s)
		{
			type = t;
		}
		void setType(string t)
		{
			type = t;
		}
	
		string getType() const
		{
			return type;
		}
	
		
		
		
};
class ITmanager: public Manager
{
	int NoPerson;
	public:
		ITmanager()
		{
			
		}
		ITmanager(string n,int a,int i,double s,string t,int no): Manager(n,a,i,s,t)
		{
			NoPerson = no;
		}
		void display()
		{
			cout<<"Name :"<<getName();
			cout<<"\nAge :"<<getAge();
			cout<<"\nId :"<<getId();
			cout<<"\nSalary :"<<getSalary();
			cout<<"\nType :"<<getType();
			cout<<"\nNo of Person :"<<NoPerson;
		}
};

int main()
{
	ITmanager m("umer",23,1234,100000,"asstM",12);
	m.display();
	return 0;
}
