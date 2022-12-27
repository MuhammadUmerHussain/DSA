#include<iostream>

using namespace std;
class b{
	char *buffer;
	int size;
	public:
		b()
		{
			
		}
		b(int s)
		{
			buffer=new char[s];
		}
		
		b(const b&rhs)
		{
			size=rhs.size;
			buffer=new char[size];
			for(int i=0;i<size;i++)
			{
				buffer[i]==rhs.buffer[i];
			}
			
			
		}
};
int main()
{
	
}
