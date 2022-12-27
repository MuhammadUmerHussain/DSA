#include<iostream>
#include<fstream>       
#include<stdlib.h>    //library for using rand()function
#include<time.h>
using namespace std;

void merge_sortSort(int arr[],int a,int n,int n2);
void print(int arr[],int n)
{
	//cout<<"*";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
  void insertion_sort(int arr[],int n)   //insertion sorting
  {
  	
  	
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
  
  //quick sort algorithms
  
  int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
    int j;
 
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
//random number as pivot
int Partition_R(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    swap(arr[random], arr[high]);
 
    return Partition(arr, low, high);
}
 
void QuickSort_R(int arr[], int low, int high)
{
    if(high > low)
    {
        int k = Partition_R(arr, low, high);
        
        QuickSort_R(arr, low, k - 1);
        QuickSort_R(arr, k + 1, high);
    }
}
 //middle number as pivot
int Partition_M(int arr[], int low, int high)
{
    int random = (low + high)/2;
 
    swap(arr[random], arr[high]);
 
    return Partition(arr, low, high);
}

void QuickSort_M(int arr[], int low, int high)
{
    if(high > low)
    {
        int k = Partition_M(arr, low, high);
        
        QuickSort_M(arr, low, k - 1);
        QuickSort_M(arr, k + 1, high);
    }
}
//median as pivot
int Median(int low, int mid, int high)
{
	int arr[3] = {low, mid, high};
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = i + 1; j < 3; j++)
		{
			if(arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
	
	return arr[1];
} 
int Partition_Median(int arr[], int low, int high)
{
    int mid = (low + high)/2;
	int median = Median(low, mid, high);
	
    swap(arr[median], arr[high]);
 
    return Partition(arr, low, high);
}

void QuickSort_Median(int arr[], int low, int high)
{
    if(high > low)
    {
        int k = Partition_M(arr, low, high);
        
        QuickSort_M(arr, low, k - 1);
        QuickSort_M(arr, k + 1, high);
    }
}
  
  
  void checkfile(string x,int arr[],int n)
  {
  	int choice;
  	int i=0;
  	ifstream file(x);
  	if(!file)
            {
            	cout<<"ERROR!";
            	return ;
			}
  	while(file>>arr[i])
  	{
	  i++;	
	}
	   cout<<"CHOOSE ANY SORTING ALGORITHM:"<<endl;
	   cout<<"PRESS 1 FOR INSERION SORT."<<endl;
	   cout<<"PRESS 2 FOR MERGE SORT."<<endl;
	   cout<<"PRESS 3 FOR QUICK SORT (middle number as pivot)"<<endl;
	   cout<<"PRESS 4 FOR QUICK SORT (random number as pivot)"<<endl;
	   cout<<"PRESS 5 FOR QUICK SORT(median as a pivot)"<<endl;
		cin>>choice;
	switch(choice)
	{
		case 01:
			{
			cout << "Insertion Sort: " << endl;
	         insertion_sort( arr, n);
	         break;
			}
		case 02:
		{
			cout<<endl;
			cout<<"MERGE SORT:"<<endl;
			int a=0;
			merge_sortSort(arr,0,n,n);
			print(arr,n);
			
			break;
			}	
		case 03:
		{
		
			cout<<endl;
				cout << "Quick Sort - Middle: " << endl;
				cout<<endl;
	           QuickSort_M(arr, 0, n - 1);
	           print(arr, n);
	           break;
		}	
		case 04:
			{
				
				cout<<endl;
			cout << "Quick Sort - Random: " << endl;
	        QuickSort_R(arr, 0, n - 1);
	        print(arr, n);
			break;	
			}
			case 05:
				{
					cout<<endl;
					cout<<"Quick Sort -Median:"<<endl;
					QuickSort_Median(arr, 0, n - 1);
	             print(arr, n);
	             break;
				}
	}
	file.close();
	}
  
  void swap(int *arr1,int *arr2)
{
	int temp=*arr1;
	
	*arr1=*arr2;
	
	*arr2=temp;
}
	void merge_sort(int arr[],int low,int mid,int high)
	{
	int i=low,j=mid+1,k=low;
	
	int arr2[high];
	
	while(i<=mid && j<=high)
	
	{
	
	if(arr[i]<arr[j])
	
	arr2[k++]=arr[i++];
	
	else
	
	arr2[k++]=arr[j++];
	}
	
	for(;i<=mid;i++)
	
	arr2[k++]=arr[i];
	
	for(;j<=high;j++)
	
	arr2[k++]=arr[j];
	
	for(i=low;i<=high;i++)
	
	arr[i]=arr2[i];
	
	
	
	}


	void merge_sortSort(int arr[],int low,int high,int n)
	{
		
	int mid;
	if(low<high)
	{
	
	mid=(low+high)/2;

	merge_sortSort(arr,low,mid,n);
	merge_sortSort(arr,mid+1,high,n);
	merge_sort(arr,low,mid,high);
	
	
}
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
	    cout<<"*SORTNG  OF FILE 1*"<<endl;
	checkfile("FILE 1.txt",arr,50);
		cout<<"*SORTNG  OF FILE 2*"<<endl;
	checkfile("FILE 2.txt",arr1,100);
		cout<<"*SORTNG OF FILE 3*"<<endl;
	checkfile("FILE 3.txt",arr2,200);
		cout<<"*SORTNG  OF FILE 4*"<<endl;
	checkfile("FILE 4.txt",arr3,300);
		cout<<"*SORTNG  OF FILE 5*"<<endl;
	checkfile("FILE 5.txt",arr4,400);
		cout<<"*SORTNG OF FILE 6*"<<endl;
	checkfile("FILE 6.txt",arr5,500);
		cout<<"*SORTNG OF FILE 7*"<<endl;
	checkfile("FILE 7.txt",arr6,1000);
	file.close();
}
