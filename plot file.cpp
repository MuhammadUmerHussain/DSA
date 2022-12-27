
#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	int plot;
	int area;
	string location;
	
	int end;
	
	ofstream fout;
	fout.open("plot.txt",ios::app);
	
	do{
		cout<<"PlotNumber:"<<end;
		cin>>plot;
		cout<<"Area"<<endl;
		cin>>area;
		cout<<"Location:"<<endl;
		cin>>location;
		fout<<plot<<"\t"<<area<<"\t"<<location<<"\n";
		cout<<"end?"<<endl;
		cin>>end;
		
		
	}while(end!=1)
	
;}
