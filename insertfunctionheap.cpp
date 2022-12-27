#include<iostream>
using namespace std;

void insertheap(int arr[],int n)
{
    int i=n;
    int temp=arr[n];

    while(i>0 && temp>arr[i/2])
    {
        arr[i]=arr[i/2];
        i=i/2;

    }
    arr[i]=temp;
}
int main()
{
    int arr[]={10,20,30,25,5,40,35};
    for(int i=1;i<7;i++)
    {
        insertheap(arr,i);
    }
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}