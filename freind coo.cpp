#include<iostream>

using namespace std;



class frien{
	
	int x;
	int y;
	
	public:
		
	friend void setvalues(frien &obj);
	
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};
 void setvalues(frien &obj)
{
	obj.x=8;
	obj.y=8;
}

int main()
{
	frien on;
	setvalues(on);
	cout<<"Values of x:"<<on.getx()<<endl;
	cout<<"Values of y:"<<on.gety()<<endl;
}
