#include<iostream>
using namespace std;


void swap(int* arr1, int* arr2) 
{ 
    int temp = *arr1; 
    *arr1 = *arr2; 
    *arr2 = temp; 
} 

int newgap(int space)
{
    space = (space*10)/13;
 
    if (space < 1)
        return 1;
    return space;
}

void CombSort(int arr[], int size)
{
    int space = size;
    bool swapp = true;
    int i;

    while (space != 1 || swapp == true)
    {
        space = newgap(space);
 
        swapp = false;
 
        for (i = 0; i < size - space; i++)
        {
            if (arr[i] > arr[i + space])
            {
                swap(arr[i], arr[i+space]);
                swapp = true;
            }
        }
    }
}
int main()
{
	
}
