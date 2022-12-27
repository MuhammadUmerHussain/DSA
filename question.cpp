#include<iostream>

class Applicant{
	
	string name;
	int age;
	
	public:
		
		Applicant()
		{
		}
		
		Applicant(int x,string y):age(x),name(y)
		{
		}
		
		string getname()
		{
			return name;
		}
		int getage()
		{
			return age;
		}
		void setname(string x)
		{
			name=x;
		}
		void setage(int x)
		{
			age=x;
		}
		
		
		
	
};


int main()
{
	
}
