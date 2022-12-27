#include <iostream>
using namespace std;

int main() {
	int rows=3;
	int cols=4;
	int **arr = new int*[rows];
	for (int i=0;i<rows;i++){
		arr[i] = new int[cols];
	}
	
	arr[1][2] = 33;
	arr[2][2] = 125;
	cout<<sizeof(arr[1])<<endl;
	int a = &arr[1];
	
	//print arr
	for (int i=0;i<rows;i++){
		for (int j=0; j<cols;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	// delete arr
	for (int i=0;i<rows;i++){
		delete[] arr[i];
	}
	delete[] arr;
	arr=0;
	
   	return 0;
}

