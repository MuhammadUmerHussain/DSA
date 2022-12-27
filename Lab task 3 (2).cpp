#include<iostream>

using namespace std;

class printClass;
class perimeter
{
	float length;
	float breath;
	
	float peri;
	
	public:
	perimeter()
	{
		
	}
	perimeter(float a,float b):length(a),breath(b)
	{
		
	}
	
	void perimetercal()
	{
		peri= 2*(length+breath);
	}
	
	friend class printClass;
};

class printClass
{
	
	public:
	void print(perimeter &p)	
	{
	cout<<"Perimeter Of Object is:"<<p.peri;
	}
	
};

int main()
{
	perimeter O(5,6);
	O.perimetercal();
	printClass p;
	
	p.print(O);
	
	
	
}
