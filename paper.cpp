#include<iostream>

using namespace std;
int jobA=0;


class moderator{
	
	static int k;
	int id;
	
	public:
		//static int jobA;
		moderator()
		{
			id=k++;
		}
		void message()
		{
			cout<<"Vacancy Closed!"<<endl;
			
		}
		void jobapllication()
		{
			cout<<"Job Application"<<jobA<<endl;
		}
		
		//moderator(candidate a)
		//{
//			if(a.type=='c')
//			{
//				
//			}
//			
		//}
	
};



class candidate{
	
	string name;
	double cnic;
	int exp;
	string dob;
	double salary;
	static int j;
	int id;
	char type;
	
	public:
		double getcnic()
		{
			return cnic;
		}
		string getname()
		{
			return name;
		}
		char gettype()
		{
			return type;
		}
		int getexp()
		{
			return exp;
		}
		candidate()
		{
			id=j++;
		}
		
		string get()
		{
			
		}
		friend class moderator;
};

class Employee{
	static int i;
	
	
	protected:
		
	string message="Vacany Closed";
	static int job;
	int id;
	string name;
	double cnic;
	int exp;
	string dob;
	
	double salary;
	
	char type;
	protected:
		bool r;
	public:
		
		virtual void postv()=0;

	Employee()
	{
		id=i++;
		
	}
	static int  getjob()
	{
		return job;
		
	}
	int getid()
	{
		return id;
	}
	

};
int Employee :: job=0;
class educational:public Employee{
	
	int campus;
	
	public:
		educational()
		{
			jobA++;
		}
		friend class moderator;
		
		void postv()
		{
			int i;
			cout<<"teaching years and ability to cope with pressure 0 for no\1 for yes"<<endl;
			cin>>i;
			if(i==0)
			{
				r=false;
			}
			else if(i==1)
			{
				r=true;
				
			}
			
			
		}
		void recieve(candidate a,moderator B)
		{
			
		name=a.getname();
		cnic=a.getcnic();
		exp=a.getexp();
		type=a.gettype();
		select(B);
		
			
		}
		void select(moderator m)
		{
			if(exp>=5)
			{
				m.message();
				
			}
		}
	
		
	
};

class p:public Employee{
	
	double budget;
	
	public:
		friend class moderator;
		
		p()
		{
			jobA++;
		}
	void postv()
		{
			void ask();
		}
		void ask()
		{
			int i;
			cout<<"good analytical skills"<<endl;
			cin>>i;
			if(i==0)
			{
				r=false;
			}
			else if(i==1)
			{
				r=true;
			}
		}
};

class bank:public Employee{
	
	int branches;
	
	public:
		friend class moderator;
		
		
		bank()
		{
			jobA++;
		}
		void ask()
		{
			int i;
			cout<<"good analytical skills"<<endl;
			cin>>i;
			if(i==0)
			{
				r=false;
			}
			else if(i==1)
			{
				r=true;
			}
		}
		
	
};
class Construction:public Employee{
	
	int projects;
	public:
		
		friend class moderator;
		
		Construction()
		{
			jobA++;
		}
			void ask()
		{
			int i;
			cout<<"good analytical skills"<<endl;
			cin>>i;
			if(i==0)
			{
				r=false;
			}
			else if(i==1)
			{
				r=true;
			}
		}
	
};



//class

int candidate::j=9000;
int Employee::i=2003;
int moderator::k=8000;
int main()
{
	
	p a;
	
	moderator m;
	//m.jobapllication(a);
	
//	Employee e[5]
//	
//	for(int i=0;i<5;i++)
//	{
//		cout<<e[i].getr()<<endl;
//	}
	
}
