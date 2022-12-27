#include<iostream>

using namespace std;

template<class t,class u>

class abc
{
	t a;
	u b;
	
	public:
	sum()
	{
		cout<<(a+b);
	}
	abc(t ab,u zz)
	{
		a=ab;
		b=zz;
	}

};
int main()
{
	abc <int,char> obj(1,'a');
	//abc<string,string> obj2("Umer","Hussain");
	obj.sum();
	//obj2.sum();
}
