#include<iostream>

using namespace std;
class dummy{
	int leg;
	int hand;
	int *p;
	public:
		dummy()
		{
			p=new int;
		}
	void setpoi(int z)
	{
		*p=z;
		}	
	void setleg(int leg)
	{
		this->leg=leg;
		
	}
	void sethand(int hand)
	{
		this->hand=hand;
		
	}
	void printval()
	{
		cout<<"Value of hand: "<<hand<<" Value Of Leg:"<<leg<<" pointer:"<<*p<<endl;
	}
	
	dummy( dummy &a)
	{
		leg=a.leg;
		hand=a.hand;
		p= new int;
		*p=*(a.p);
	}
	
	~dummy()
	{
		delete p;
	}
	
};


int main()
{
	dummy a;
	a.setleg(5);
	a.sethand(9);
	a.setpoi(9);
	dummy b=a;
	a.printval();
	b.printval();
}
