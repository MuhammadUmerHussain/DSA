#include<iostream>

using namespace std;

class abc{
	
	static int i;
	
	public:
		 abc(){
			i++;
		}
	
	static int getstatic()
	{
		return i;
		}	
		
};

int abc::i=0;

int main()
{
	abc f;
	abc d;
	cout<<"i="<<d.getstatic();
	
	return 1;
}
