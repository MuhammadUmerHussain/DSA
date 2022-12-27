#include<iostream>
using namespace std;

class abc{
	
	public:
		
		void print1(int x);	
		void print()
		{
			cout<<"This Is Inside Of Class:"<<endl;
		}
		
		
};

void abc::print1(int x)
{
	cout<<"This Is outside Of Class:"<<endl;
}

int main()
{
	abc t;
	
	t.print();
	t.print1(101);
}



