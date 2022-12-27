#include<iostream>

using namespace std;

class Rectangle{
	int length;
	int breath;
	int area;
	
	public:
		Rectangle()
		{
			length=0;
			breath=0;
			
		}
		Rectangle(int a,int b)
		{
			length=a;
			breath=b;
			
		}
		
		void setDimension(int a)
		{
			length=a;
			breath=a;
		}
		
		void setDimension(int a,int b)
		{
			length=a;
			breath=b;
		}
		
		int getLength()
		{
			return length;
		}
		int getArea()
		{
			return area;
		}
		int getBreath()
		{
			return breath;
		}
		
		void calculatearea(int a,int b)
		{
			setDimension(a,b);
			area=a*b;
			printvalue();
			
		}
		void calculatearea(int a)
		{
			setDimension(a);
			area=a*a;
			printvalue();
			
		}
		void printvalue()
		{
			cout<<"Breath is:"<<breath<<endl;
			cout<<"Length is:"<<length<<endl;
			cout<<"Area is:"<<area<<endl;
		}
		
};


int main()
{
	Rectangle r1,r2,r3,r4;
	r1.setDimension(5);//function overloading	
	
	r2.setDimension(5,10);//function overloading
	r3.calculatearea(5,10);//function overloading
	r4.calculatearea(20);//functionoverloading
}
