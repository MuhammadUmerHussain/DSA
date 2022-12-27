#include<iostream>
#include<fstream>       
#include<stdlib.h>
#include <bits/stdc++.h>    //library for using rand()function
#include<time.h>
using namespace std;

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
}
  void insertion_sort(int arr[],int n)
  {
  	
  	cout<<"SORTING FUNCTION OF "<<n<<" SIZE :"<<endl<<endl;
  	int i, j;
	for (i = 1; i < n; i++){
		int key = arr[i];
		for (j = i; j > 0 && arr[j-1] > key; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = key;
	}
	print(arr,n);
  	
  }
  void checkfile(string x,int arr[],int n)
  {
  	int i=0;
  	ifstream file(x);
  	if(!file)
            {
            	cout<<"ERROR!";
            	return ;
			}
  	while(file>>arr[i])
  	{
  	//cout<<arr[i]<<endl;
	  i++;	
	}
	insertion_sort( arr, n);
	file.close();
	
	
  }
int main()
{
            ofstream file;   //replacement of cout
            file.open("FILE 1.txt");      //THIS IS FILE 1
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	
	srand(time(0));    //for using numbers without duplicates
	
	
	for(int i=0;i<50;i++)           //size 50
	{
		file<<rand()<<endl;   
		
	}
	file.close();
	
	file.open("FILE 2.txt");   //THIS IS FILE 2
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	for(int i=0;i<100;i++)    //size 100
	{
		file<<rand()<<endl;   
		
	}
	file.close();
	
	
	file.open("FILE 3.txt"); //THIS IS FILE 3
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	for(int i=0;i<200;i++)     //size 200
	{
		file<<rand()<<endl;   
		
	}
	file.close();
	
	file.open("FILE 4.txt");
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	for(int i=0;i<300;i++)     //size 300
	{
		file<<rand()<<endl;   
		
	}
	file.close();
	
	file.open("FILE 5.txt");   //THIS IS FILE 5
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	for(int i=0;i<400;i++)   //size 400
	{
		file<<rand()<<endl;   
		
	}
	file.close();
	
	file.open("FILE 6.txt");  //THIS IS FILE 6
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	for(int i=0;i<500;i++)   //size 500
	{
		file<<rand()<<endl;   
		
	}
	file.close();
	
	file.open("FILE 7.txt");   //THIS IS FILE 7
            if(!file)
            {
            	cout<<"ERROR!";
            	return 1;
			}
	for(int i=0;i<1000;i++)     // size 1000
	{
		file<<rand()<<endl;   
		
	}
	
	int arr[50], arr1[100] ,arr2[200],arr3[300],arr4[400],arr5[500],arr6[1000]     ;
	checkfile("FILE 1.txt",arr,50);
	
	checkfile("FILE 2.txt",arr1,100);
	checkfile("FILE 3.txt",arr2,200);
	checkfile("FILE 4.txt",arr3,300);
	checkfile("FILE 5.txt",arr4,400);
	checkfile("FILE 6.txt",arr5,500);
	time_t start ,end;
	time(&start);
	
	ios_base::sync_with_stdio(false);
	checkfile("FILE 7.txt",arr6,1000);
	time(&end);
	
	double time2=double(end-start);
	cout << "Time taken by program is : " << fixed
         << time2 << setprecision(5);
    cout << " sec " << endl;
	file.close();
	
}
