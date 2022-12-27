#include<iostream>
#include<cstring>



using namespace std;



class A{
	char *x;
	char *y;
	
	public:
	A()
	{
//			for(i=0;i<n;i++)
//			{
//			
//			x[i]=new char
//			y[i]=new char;
		}
		
		A(char v[],char t[])
		{
			int i;
			x=new char[strlen(v)];
			y=new char[strlen(t)];
			//x=v;
			//y=t;
		for(i=0;i<strlen(v);i++)
			{
				*(x+i)=v[i];
				
			}
			for(i=0;i<strlen(t);i++)
			{
				*(y+i)=t[i];
			}
		}
		
		string geta()
		{
			return x;
		}
		string getb()
		{
			return y;
		}
		
		
		void print()
		{
			cout<<geta()<<endl;
			cout<<getb()<<endl;
		}
	
		
		
};
int main()
{
	A umer("UMAR_HUSSAINN\","FAIZAN_KHANN");
	umer.print();
}
