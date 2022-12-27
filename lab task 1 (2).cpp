#include<iostream>

using namespace std;


class lab{
	
	float a;
	
	public:
		lab()
		{
			
		}
		
		lab(float x):a(x)
		{
		}
		
		void setA(float a)
		{
			this->a=a;
		}
		float getA()
		{
			return a;
		}
		
		
		
	lab operator--()
	{
		lab temp;
		
		temp.a=a*4;
		
		return temp;
		}	
	lab operator--(int)
	{
		lab temp;
		
		temp.a=a/4;
		
		return temp;
	}
	
};

int main()
{
	lab t(5);
	lab t2;
	lab t3;
	t2=--t;// pre increment * 4 as requirement
	t3=t--;
	
	cout<<"Value of t2(pre decrement) is:"<<t2.getA();
	cout<<"\nValue of t3(post decrement) is:"<<t3.getA();
}
