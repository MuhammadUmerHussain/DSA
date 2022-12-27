#include<iostream>

using namespace std;
class shape {
	
	float length;
	float breath;
	float area;
	public:
		
		shape()
		{
			
		}
		shape(float a,float b):length(a),breath(b)
		{
			
		}
		
		void Area()
		{
			area=length*breath;
		}
		
		float getArea()
		{
			return area;
		}
		
		shape operator +(shape s)
		{
			shape temp;
			
			temp.area=area+s.area;
			
//			temp.length=length+s.length;
//			temp.breath=breath+s.breath;
// not use because question requirement is to add both areas not their lengths
			
			return temp;
		}
	
};

int main()
{
	shape s1(5,6);
	s1.Area();
	shape s2(5,6);
	s2.Area();
	
	shape s3;
	s3=s1+s2;
	
	cout<<"Area Of S3 is adding of both objects area:"<<s3.getArea();
}
