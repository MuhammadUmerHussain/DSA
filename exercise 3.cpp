#include<iostream>
using namespace std;
class A;
void print(A a);
class A{
	int x;
	public:
		A()
		{
			x=1;
		}
		get() const
		{
			A a;
			print(a);
		}
		get_c()
		{
			x=x+4;
			cout<<"C";
		}
};
void print(A a)
{
	cout<<"A";
	a.get_c();
}
int main()
{
A a1;
a1.get();
return 0;	
}
