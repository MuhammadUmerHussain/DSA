#include <iostream>
#include <string>

using namespace std;

int main()
{
	//2D Jagged array in C++
	int rows;
	cout << "Enter no of rows of array: ";
	cin >> rows;
	int *col_sizes = new int[rows];   //array to store no of columns in each row;
	//declaration of array
	int **array = new int*[rows];   //jagged array

	for (int i = 0; i < rows; i++)
	{
		cout << "Enter no. of cols in row " << i << ": ";
		cin >> col_sizes[i];
		array[i] = new int[col_sizes[i]];
	}
	//Input values in array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col_sizes[i]; j++)
		{
			cout << "Row " << i << ":- Enter value " << i*col_sizes[i] + j << ": ";
			cin >> array[i][j];
		}
	}
	//Output values of array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col_sizes[i]; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
