#include<iostream>
#include<string.h>

using namespace std;

#define k 3

void Print(int a[][k], int m, int n)
{
	cout << "*  ";
	
	cout << endl;
	
	if (m >= 1)
	{
		if (n >= 1)
			return Print(a, m, n);	
	}
	
	
	
}

int main ()
{
	int m = 2, n = 3;
	int a[m][n] = {(0,1,3), (4, 5, 7)};
	
	Print(a, m, n);
}
