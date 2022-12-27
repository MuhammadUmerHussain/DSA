#include<iostream>

using namespace std;
class complex{
	
	float real;
	float img;
	
	public:
		complex()
		{
		}
		complex(float x,float y)
		{
			real=x;
			img=y;
			
		}
		float getreal()
		{
			return real;
		}
		float getimg()
		{
			return img;
		}
		void setreal(float x)
		{
			real=x;
		}
		void setimg(float y)
		{
			img=y;
		}
		void addcomplex(complex &obj)
		{
			float f;
			float z;
			
			f=real+obj.real;
			z=img+obj.img;
			
			cout<<"Real Part:"<<f;
			cout<<"\nImg Part:"<<z;
			cout<<"\n"<<f<<"+"<<z<<"i";
			
		}
		complex operator +(complex obj)
		{
			complex c3;
			c3.real=real+obj.real;
			c3.img=img+obj.img;
			
			return c3;
		}
		
		complex operator +(int x)
		{
			complex c3;
			c3.real=real+x;
			c3.img=img;
			return c3;
		}
	friend	ostream &operator<<(ostream &output, complex const &obj)
		{
			output<<"Real:"<<obj.real<<"Img:"<<obj.img<<endl;
			return output;
		}
//friend 	istream &operator>>(istream &input,complex const &obj)
//		{
//			input>>obj.co;
//			input>>obj.exp;
//			cout<<"Hello";
//		}
		
		 complex operator++(int)
		{
			complex c3;
			
			c3.real=real++;
			c3.img=img++;
			return c3;
		}
		
};

int main()
{
	complex c1(2.5,3.5),c2(4.5,5.5),c3,c4;
	c1.addcomplex(c2);
	c3=c1+c2;
	cout<<"Real Number Is:"<<c3.getreal()<<endl;
	cout<<"Img Number Is:"<<c3.getimg()<<endl;
	c4=c1+2;
	//cout<<"Real Number Is:"<<c4.getreal();
	
	cout<<c4;
	
	
}
