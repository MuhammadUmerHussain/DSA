#include<iostream>

using namespace std;

class Minimum{
	int par1;
	int par2;
	int par3;
	
	public:
		Minimum()
		{
		}
		Minimum(int x,int y,int z)
		{
			par1=x;
			par2=y;
			par3=z;
		}
		void setvalues(int x,int y,int z)
		{
			par1=x;
			par2=y;
			par3=z;
			
		}
		void setvalues(int x,int y)
		{
			par1=x;
			par2=y;
			
			
		}
		int getPar1()
		{
			return par1;
		
		}
		int getPar2()
		{
			return par2;
		}
		int getPar3()
		{
			return par3;
		}
		int min(int a,int b)
		{
			setvalues(a,b);
			if(par1>par2)
				return par2;
			else
				return par1;
		}
		int min(int a,int b ,int c) 
		{
			setvalues(a,b,c);
			if(par1<par2 && par1<par3)
				return par1;
			else if(par2<par1 && par2<par3)
				return par2;
			else if(par3<par1 && par3<par2)
				return par3;}
};

int main()
{
	Minimum m1,m2;
	
	cout<<"Minimum Of M1:"<<m1.min(1,2,3)<<endl;
	cout<<"Minimum Of M2:"<<m2.min(5,6);
	
}
