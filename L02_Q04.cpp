#include<iostream>

using namespace std;

int main()
{
	int rows, columns, people, i,j;
	bool** arr;
	
	cout << "Enter the number of people : ";
	cin >> people;
	
	rows = people;
	columns = people;
	
	arr = new bool * [rows];
	
	for(i = 0; i < rows; i++)
	{
		arr[i] = new bool [columns];	
	}
	
	// Data entry 
	
	int num;
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			if(i != j)
			{
				cout << "Is person " << i << " the friend of person " << j << " ? 0(No) or 1(Yes) = ";
				cin >> num;
				
				if(num == 1)
				{
					arr[i][j] = true;
				}
				else if(num == 0)
				{
					arr[i][j] = false;
				}
				else
				{
					cout << "\nYou entered a number other than 1 or 0 so assuming it as false !";
					arr[i][j] = false;
				}
			}
		}
	}
	
	// Printing the table
	
	cout << "\n\n";
	
	for(j = 0; j < columns; j++)
	{
		cout << "\t";
		cout << j;
	}
		
	for(i = 0; i < rows; i++)
	{
		cout << "\n" << i;
		
		for(j = 0; j < columns; j++)
		{
			cout << "\t";
			if(*(*(arr+i)+j)==true)
			{
				cout << "*";
			}
			else 
			{
				cout << " ";
			}
		}
	}
	
	
	// Main Task
	
	while(1)
	{
		int p1, p2, count = 0;
	
		cout << "\n\nEnter any two people for whom you want to check the mutual friend !\n1st: ";
		cin >> p1;
		cout << "2nd: ";
		cin >> p2;
		
		cout << "Common friends of " << p1 << " and " << p2 << " are : \n";
		
		for(j = 0; j < columns; j++)
		{
			if(*(*(arr+p1)+j) == true && *(*(arr+p2)+j) == true)
			{
				cout << j << "  ";
				count++;
			}
		}
		
		if(count == 0)
		{
			cout << "None ! ";
		}
		
		int n;
		
		cout << "\n\nDo you want to once more check the mutual friends ? -1 for No, and any other number for Yes : ";
		cin >> n; 
		if(n == -1)
		{
			break;
		}
	}
	
}
