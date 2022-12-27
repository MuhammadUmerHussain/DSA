#include<iostream>

using namespace std;

class employee{
	
	string name;
	int id;
	
	public:
	
	employee()
	{
		
	}
	employee(string x,int y)
	{
		name=x;
		id=y;
	}
	string getName()
	{
		return name;
	}
	int getID()
	{
		return id;
	}
	
};

class Scientist:protected employee
{
	
	string Stitle;
	string publication;
	public:
		Scientist()
		{
			
		}
		
		Scientist(string x,int y,string t,string c):employee(x,y),Stitle(t),publication(c)
		{
			
		}
		string getpublication()
		{
			return publication;
		}
		string getStitle()
		{
			return Stitle;
		}
		int gettID()
		{
		return getID();
		}
		string gettName()
		{
			return getName();
		}
	
};

class Manager:protected employee
{
	string Mtitle;
	int club_dues;
	
	public:
		Manager()
		{
			
		}
		
		Manager(string x,int y,string t,int c):employee(x,y),Mtitle(t),club_dues(c)
		{
			
		}
		
		int getdues()
		{
			return club_dues;
		}
		string getMtitle()
		{
			return Mtitle;
		}
		int gettID()
		{
		return getID();
		}
		string gettName()
		{
			return getName();
		}
	
	
	
};
class Labour:protected employee
{
	string title;
	
	public:
		Labour()
		{
			
		}
		
		Labour(string x,int y,string t):employee(x,y),title(t)
		{
			
		}
		
		
		string gettitle()
		{
			return title;
		}
		int gettID()
		{
		return getID();
		}
		string gettName()
		{
			return getName();
		}
		void print()
		{
			cout<<gettName()<<endl;
			cout<<gettID()<<endl;
			cout<<gettitle()<<endl;
		}
	
	
};
int main()
{
	Labour l("Umer",1001,"Labour");
	l.print();
}
