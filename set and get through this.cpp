#include<iostream>

using namespace std;


class abc{
	
	int num;
	char ch;
	
	public:
		
		int getnum()
		{
			return num;
		}
		
		char getch()
		{
			return ch;
		}
		
		void setter(int num)
		{
			this->num=num;
		}
		void setch(char ch)
		{
			this->ch=ch;
		}
		
		void print()
		{
			cout<<"Num Is :"<<num<<" Character Is :"<<ch;
		}
};


int main()
{
	abc a;
	a.setch('a');
	a.setter(5);
	
	a.print();}
