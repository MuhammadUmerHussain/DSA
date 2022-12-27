#include<iostream>
#include<string.h>
using namespace std;

class Animal{
	
	float weight;
	
	public:
		string name;
		Animal(){}
		Animal(string x,float z):name(x),weight(z)
		{
			
		}
		void setname(string x)
		{
			name=x;
		}
		void setweight(float z)
		{
			weight=z;
		}
		
		string getname()
		{
			return name;
			
		}
		float geetweight()
		{
			return weight;
		}
		
		void walking()
		{
			cout<<"I am Walking"<<endl;
		}
		void print()
		{
		
		cout<<getname();}
};

int main()
{
	Animal *t;
	t=new Animal[3];
	t[0]=Animal("Cat",100);
	t[1]=Animal("Horse",100);
	t->print();
	(t+2)->setname("Dog");
	(t+2)->setweight(50.1);
	(t+2)->print();
	Animal k;
	for(int i=0;i<3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(strcmp(t[i-1].name[j-1],t[i].name[j])>0)
			{
				strcpy(k,t[j-1]);
				strcpy(t[j-1],t[j]);
				strcpy(t[j],k);
			}
		}
	}
}
