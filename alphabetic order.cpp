
#include <iostream>
#include <string>
using namespace std;
char tolow(string s)
{
    if (s[0] >= 'A' && s[0] <= 'Z') 
        return (char)(s[0] + 32); 
    else
        return s[0];
}

//Task 1: Alphabetical
int main()
{
	int size = 0;

	cout << "Enter the size of an array: ";
	cin >> size;
	cin.ignore(); //important

	string *Array = new string[size]; //Array of pointers
	for (int i = 0; i < size; i++)
	{
		cout << "\n Enter word: ";
		getline(cin, Array[i]);
	}

	cout << endl;

	int j = 0;
	bool swap = true;
	string temp;
	while (swap)
	{
		swap = false;
		j++;
		for (int l = 0; l < size - j; l++)
		{
			if (lowerCase(Array[l])>lowerCase(Array[l+1]))
			{
				temp = Array[l];
				Array[l] = Array[l + 1];
				Array[l + 1] = temp;
				swap = true;
			}
		}
	}
	
	for (int k = 0; k < size; k++)
	{
		cout << Array[k] << endl;
		 
	}

	cout << endl << endl;

	delete[] Array;

	system("PAUSE");
	return 0;
}
