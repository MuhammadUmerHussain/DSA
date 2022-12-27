#include<iostream>

using namespace std;

// BUBBLE SORTING

void BubbleSort(int arr[], int size)
{
	int i, j, temp;
	
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
}

// SELECTION SORTING

int ValueToBeSwapped(int arr[], int j, int max)
{
    if (j != max)
    {
    	int m;
		m = ValueToBeSwapped(arr, j + 1, max);
		
		if(arr[j] < arr[m])
		{
			return j;
		}
		else
		{
			return m;
		}
	}
    
	return j;
}

void SelectionSort(int arr[], int j, int size)
{
	if (j != size)
    {
    	int k;
		k = ValueToBeSwapped(arr, j, size-1);
 

    	if (k != j)
    	{
    		int temp;
    		temp = arr[k];
    		arr[k] = arr[j];
    		arr[j] = temp;
		}

    	SelectionSort(arr, j + 1, size);
	}
     
	return;
	
}


// QUICK SORTING



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
 
void QuickSort(int arr[], int low, int high)
{
    if(high > low)
    {
        int k = Partition(arr, low, high);
        
        QuickSort(arr, low, k - 1);
        QuickSort(arr, k + 1, high);
    }
}
 

// INSERTION SORTING

void InsertionSort(int arr[], int size)
{
    int i, key, j;
    
    for(i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// COMB SORTING

int GetNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 
void CombSort(int arr[], int size)
{
    int gap = size;
    bool swapped = true;
    int i;

    while (gap != 1 || swapped == true)
    {
        gap = GetNextGap(gap);
 
        swapped = false;
 
        // Compare all elements with current gap
        for (i = 0; i < size - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}


// Print Sorted Array

void Print(int arr[], int size)
{
	int i;
	
	cout<< "\n\nSorted Array : \n" << arr[0];
	
	for(i = 1; i < size; i++)
	{
		cout << ", " << arr[i];
	}
}


// Main Function

int main()
{
	cout << "______ Sorting Program ______ ";
	
	while(1)
	{
		int choice, i;
	
		cout << "\n\nEnter a number to select a method of sorting an array :\n1 for bubble sorting\n2 for selection sorting\n";
		cout << "3 for quick sorting\n4 for insertion sorting\n5 for comb sorting\nAny other number to exit out\nType any number here : ";
		cin >> choice;
		
		int size = 10;
		int arr[size] = {5, 3, 8, 1, 4, 6, 2, 7, 10, 9};   // GIVEN ARRAY IN THE TASK
		
		cout<< "\n\nUnsorted Array : \n" << arr[0];
		
		for(i = 1; i < size; i++)
		{
			cout << ", " << arr[i];
		}
		
		if(choice == 1)
		{
			cout << "\n\n|| Sorting through Bubble Sorting ||";
			BubbleSort(arr, size);
			Print(arr, size);
		}
		else if(choice == 2)
		{
			cout << "\n\n|| Sorting through Selection Sorting ||";
			SelectionSort(arr, 0, size);
			Print(arr, size);
		}
		else if(choice == 3)
		{
			cout << "\n\n|| Sorting through Quick Sorting ||";
			QuickSort(arr, 0, size - 1);
			Print(arr, size);
		}
		else if(choice == 4)
		{
			cout << "\n\n|| Sorting through Insertion Sorting ||";
			InsertionSort(arr, size);
			Print(arr, size);
		}
		else if(choice == 5)
		{
			cout << "\n\n|| Sorting through Comb Sorting ||";
			CombSort(arr, size);
			Print(arr, size);
		}
		else
		{
			cout << "\n\nProgram is going to shut down !! ";
			exit(0);
		}
			
	}
	
}
