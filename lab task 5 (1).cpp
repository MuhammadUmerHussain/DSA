#include<iostream>
using namespace std;

int main()
{
	float **arr=new float *[5];
	int col[5]={5,4,3,3,5};
	string names[5]={"Ali","Hiba","Asma","Zain","Faisal"};
	
	for(int i=0;i<5;i++)
	arr[i]=new float[col[i]];
	arr[0][0]=3.66;
	arr[0][1]=3.33;
	arr[0][2]=4.0;
	arr[0][3]=3.0;
	arr[0][4]=2.66;
	arr[1][0]=3.33;
	arr[1][1]=3.0;
	arr[1][2]=3.66;
	arr[1][3]=3.0;
	arr[2][0]=4.0;
	arr[2][1]=3.66;
	arr[2][2]=2.66;
	arr[3][0]=2.66;
	arr[3][1]=2.33;
	arr[3][2]=4.0;
	arr[4][0]=3.33;
	arr[4][1]=3.66;
	arr[4][2]=4.0;
	arr[4][3]=3.0;
	arr[4][4]=3.33;
	
	float cgpa[5];
	float sum=0;
	for(int i=0;i<5;i++)
	{
	for(int j=0;j<col[i];j++)
	{
		sum=(sum+(arr[i][j]*3));
		
	}
	//cout<<sum<<endl;
	cgpa[i]=sum/(col[i]*3);
	sum=0;
	cout<<names[i]<<" "<<cgpa[i]<<endl;
	
}
}
