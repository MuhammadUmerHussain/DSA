#include<iostream>
using namespace std;


class A{
	public:
	int a;
	
	public:
		void name()
		{
			cout<<"Umer"<<endl;
			
		}
		A()
		{
		}
		A(int r)
		
		{
			a=r;
			
		}
};

class b: public virtual A{
	public:
	int b1;
	public:
		b()
		{
		}
		b(int r,int z):A(r),b1(z)
		{
			
		}
		void name()
		{
			cout<<"X"<<endl;
			
		}
};

class c:virtual public A{
	public:
	int z;
	public:
		c()
		{
			
		}
		c(int r,int t):A(r),z(t)
		{
		}
		
		void name()
		{
			cout<<"z"<<endl;
			
		}
};
class d:public b,public c
{
	public:
	int b2;
	
		friend class r;
		d()
		{
			
		}
		d(int r,int t, int z,int b3):b(r,z),b2(b3),c(r,t),A(r)
		{
		}
		void name()
		{
			cout<<a<<b1<<b2<<endl;
			
		}
};
class r{
	
	
	public:
	
		void display(d a)
		{
		a.name();
	}
};

int main()
{

	d f(5,4,5,52);
	r a;
	a.display(f);
}
