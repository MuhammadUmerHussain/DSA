#include<iostream>
using namespace std;
class user{
	int age;
	string name;
	public:
		void set_name(string x)
		{
			name=x;
		}
		string get_name()
		{
			return name;
		}
		void set_age(int x)
		{
			age=x;
		}
		int get_age()
		{
			return age;
		}
		void input()
		{
			string n;
			int a;
			cout<<"ENTER NAME:";
			cin>>n;
			set_name(n);
			cout<<"ENTER AGE:";
			cin>>a;
			set_age(a);
			
		}
};
int main()
{
	user obj;
	obj.input();
	
	cout<<"MY NAME IS "<<obj.get_name()<<" AND MY AGE IS"<<obj.get_age();
}
