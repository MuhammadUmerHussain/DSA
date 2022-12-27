#include<iostream>
using namespace std;
#include<istream>
#include <fstream> 
#include <istream> 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include<conio.h>
#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>

int main()
{
	int temprate;
	ifstream rate2 ("ratebuyer.txt",ios::app);
	cout<<"flag";
	while(rate2>>temprate)
	{
		cout<<temprate;
	}
}
