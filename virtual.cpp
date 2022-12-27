#include<iostream>

using namespace std;

class living{
	
	public:
	void breathe()
		{
			cout<<"I am Breathing as a living thing:"<<endl;
		}
};

class Animal:public virtual living{
	
	public:
		void crawl()
		{
			cout<<"I am Breathing as a Animals"<<endl;
		}
};

class Reptile:public virtual  living{
	public:
		void walk()
		{
			cout<<"I am Crawling"<<endl;
		}
};

class snake:public Animal,public Reptile
{
	public:
		void type()
		{
			crawl();
		}
};

int main()

{
	snake Snake;
	Snake.breath();
}
