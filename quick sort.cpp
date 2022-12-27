#include<iostream>

using namespace std;
 #define __STDC_LIMIT_MACROS
#include <stdint.h>
 int partition(int arr[],int l,int h)
 {
	int privot=arr[l];
	
	int i=l;
	int j=h;
	do{
		
		
		do{
		i++;}while(arr[i]<=privot);
		do{
		j--;}while(arr[j]>privot);
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}while(i<j);
	
	swap(arr[l],arr[j]);
	
	return j;
 }
 
 void quick(int arr[],int l,int h)
 {
 	int j;
 	
 	if(l<h)
 	{
 		j=partition(arr,l,h);
 		quick(arr,l,j);
 		quick(arr,j+1,h);
	 }
 }
 
 
 
 
 
 int main()
{
	
int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
int arr[]={1,0,5,6};
quick(arr,0,4);
for(i=0;i<4;i++)
printf("%d ",arr[i]);
printf("\n");
return 0;
}
