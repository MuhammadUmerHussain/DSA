#include<iostream>

using namespace std;


class a{
	
	public:
	void fun1()
	{
		cout<<"f1";
	}
};

class b:virtual public  a
{
	public:
	virtual void fun1()
	{
		cout<<"f2";
	}
};

class b2:virtual public a
{
	public:
	void fun1()
	{
		cout<<"f3";
	}
};
class c1:public b,public b2
{
	public:
	void fun()
	{
		cout<<"f4";
	}
};


int main()
{
	c1 obj;
 obj.fun1();
}
