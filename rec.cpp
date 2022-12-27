#include<iostream>
using namespace std;
class rec
{
public:
void	print()
	{
		cout<<A();
	}
string A()
{
	return "hello "+b();
}
string b()
{
	return "my "+c();
}
string c()
{
	return "friend ";
}
};
int main(){
	rec G;
	G.print();
}
