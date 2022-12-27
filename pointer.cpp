#include<iostream>
#include<cstring>

using namespace std;


class Convert{
	char *x;
	char *y;
	
	public:
		Convert()
		{
		}
		Convert(char V[],char S[])
		{
			x=new char[4];
			y=new char[strlen(S)];
			
			for(int i=0;i<strlen(V);i++)
			{
				*(x+i)=V[i];
			}
			for(int i=0;i<strlen(S);i++)
			{
				*(y+i)=S[i];
			}
		}
		void seta(char s[])
		{
			x=new char[strlen(s)];
			
			for(int i=0;i<strlen(s);i++)
			{
				*(x+i)=s[i];
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
	Convert umer("umerhussain","faizan");
	//umer.seta("Hello");
	umer.print();
}

