#include <stdio.h>
#include<stdlib.h>
void swap(int *arr1,int *arr2)
{
int temp=*arr1;
*arr1=*arr2;
*arr2=temp;
}
void merge_sort(int arr[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low;
int arr2[100];
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
void merge_sortSort(int arr[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;

merge_sortSort(arr,low,mid);
merge_sortSort(arr,mid+1,high);
merge_sort(arr,low,mid,high);
}
}

int main()
{
int arr[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
merge_sortSort(arr,0,n);
for(i=0;i<10;i++)
printf("%d ",arr[i]);
printf("\n");
return 0;
}
