#include<iostream>

using namespace std;

class polynomial{
	 int *exp;
	 int *co;
	static int size;
	
	public:
		polynomial()
		{
			exp= new int[5];
			co=new int[5];
		}
		polynomial(int s)
		{	
			size=s;
			exp=new int[size];
			co=new int[size];
			for(int i=0;i<size;i++)
			{
				co[i]=0;
				exp[i]=1;
						}			
		}
	void setco(int arr[])
	{
		for(int i=0;i<size;i++)
		{
			co[i]=arr[i];
		}
	}
	void setex(int arr[])
	{
		for(int i=0;i<size;i++)
		{
			exp[i]=arr[i];
		}
	}
	void print()
	{
		for(int i=0;i<size;i++)
		{
			if(i!=size-1)
			
			cout<<co[i]<<"^"<<exp[i]<<"+";
			else
			cout<<co[i]<<"^"<<exp[i];
		}
	}
	polynomial operator +(polynomial &obj)
	{
		polynomial x(2);
		for(int i=0;i<size;i++)
		{
			x.co[i]=co[i]+obj.co[i];
			x.exp[i]=exp[i]+obj.exp[i];
			
			
		}
		return x;
	}
	bool operator ==(polynomial p)
	{
		int count=0;
		for(int i=0;i<size;i++)
		{
			if(co[i]==p.co[i] && exp[i]==p.exp[i])
			{
				count++;
			}
			
		}
		if(size==count)
		{
			return true;
		}
		else false;
		}
	friend ostream &operator <<(ostream &output,polynomial &obj )	
	{
		for(int i=0;i<size;i++)
		{
		output<<"\nCoeffient"<<obj.co[i]<<" Exponent"<<obj.exp[i]<<endl;}
		return output;
		}
	~polynomial()
	{
		delete[] exp,co;
			}		
};
int polynomial::size=5;
int main()
{
	polynomial p(2),p2(2),p3(2),p4(2);
	int exp[2]={1,2};
	int co[2]={1,2};
	p.setco(co);
	p.setex(exp);
	p2.setco(co);
	p2.setex(exp);
	p3=p+p2;
	p3.print();
	
	if(p2==p)
	{
		cout<<"\nTrue";
	}
	else
	{
		cout<<"\nNot True";
	}
	cout<<p4;	
	
}
