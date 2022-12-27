#include<iostream>
using namespace std;

class ArrayIndexOutOfBoundsException : public std::exception
{
	private:
		char const * s;
	
	public:
	ArrayIndexOutOfBoundsException(char const * s_=""){
		s = s_;
	}	
	const char * what () const throw ()
    {
		if (s=="row")    	
    		return "Exception: Row index out of bound!";
    	if (s=="col")	
    		return "Exception: Col index out of bound!";
    	if (s=="rowcol")	
    		return "Exception: row and col indices are out of bound!";
    	return "Exception: Index out of bound!";
    }
};

class DynJag2dArrInt
{
	private:
		int* arr;
		int* col_sizes;
		int size, row_size;
		
	public:
	// Constructor
		DynJag2dArrInt(int row_size_=1, int col_sizes_[2]=0, int *a=0){
			// Todo: check size can be zero or negative
			row_size = row_size_;
			col_sizes = new int[row_size];
			for (int i=0;i<row_size;i++){
				col_sizes[i] = col_sizes_[i];
			}
			size=0;
			for (int i=0;i<row_size;i++){
				size+=col_sizes[i];
			}
			arr = new(nothrow) int[size];
			
			for (int i=0;i<size;i++){
				arr[i] = a[i];
			}
		}
		
		// Copy constructor
		// Assignment operator
		
		// Access operator
		int& operator()(int row_index, int col_index){
			if (row_index < 0 || row_index >= row_size){
				throw ArrayIndexOutOfBoundsException("row");
			}
			if ((row_index < 0 || row_index >= row_size) &&
				(col_index < 0 || col_index >= col_sizes[row_index])){
					throw ArrayIndexOutOfBoundsException("rowcol");
			}
			if(col_index < 0 || col_index >= col_sizes[row_index]){
				throw ArrayIndexOutOfBoundsException("col");
			}
			int k=0;
			for (int i=0;i<row_index;i++){
				k += col_sizes[i];
			}
			return arr[k + col_index];
		}
		
		// Set
		void set(int row_index, int col_index, int val){
			if (row_index < 0 || row_index >= row_size){
				throw ArrayIndexOutOfBoundsException("row");
			}
			if ((row_index < 0 || row_index >= row_size) && 
				(col_index < 0 || col_index >= col_sizes[row_index])){
				throw ArrayIndexOutOfBoundsException("rowcol");

			}
			if(col_index < 0 || col_index >= col_sizes[row_index]){
				throw ArrayIndexOutOfBoundsException("col");
			}
			int k=0;
			for (int i=0;i<row_index;i++){
				k += col_sizes[i];
			}
			arr[k + col_index] = val;
		}
		
		// pushBackCol
		void pushBackCol(int row_index, int val){
			if (row_index < 0 || row_index >= row_size){
				throw ArrayIndexOutOfBoundsException("row");
			}
			int* arr_new = new int[size + 1];
			
			int i=0;
			int k=0;
			for (i=0; i<=row_index;i++){
				for (int j=0; j< col_sizes[i];j++){
					arr_new[k] = arr[k];
					k++;
				}
			}
			arr_new[k++] = val;
			col_sizes[row_index]++;
			for (int j=k; j<=size+1;j++){
				arr_new[j] = arr[j-1];
			}
			
			delete [] arr;
			arr = arr_new;
			size++;
		}
		
		// pushBackRow
		void pushBackRow(int val[], int val_size){
			// update col_sizes
			int* new_col_sizes = new int[row_size+1];
			for(int i=0; i<row_size;i++){
				new_col_sizes[i] = col_sizes[i];
			}
			new_col_sizes[row_size] = val_size;
			delete [] col_sizes;
			col_sizes = new_col_sizes;
			
			// update arr
			int *arr_new = new int[size+val_size];
			for(int i=0; i<size;i++){
				arr_new[i] = arr[i];
			}
			for(int i=size; i<size+val_size;i++){
				arr_new[i] = val[i-size];
			}
			
			delete [] arr;
			arr = arr_new;
			row_size++;
			size +=val_size;
		}
		
		// Size
		int getRowSize(){
			return row_size;
		}
		int getColSize(int row_index){
			return col_sizes[row_index];
		}
		
		// Destructor
		~DynJag2dArrInt(){
			delete [] arr;
			delete [] col_sizes;
		}
		
		// print array
		void printArray(){
			int k=0;
			for (int i=0;i< row_size;i++){
				for (int j=0;j< col_sizes[i];j++){
					cout<<arr[k]<<",";
					k++;
				}
				cout<<"\n";	
			}
			cout<<"\n";	
		}
};

int main()
{	
	// create initial array
	int row_size=3;
	int col_sizes[row_size]={1,2,3};
	int size=6;
	int *arr = new int[size];
	
	for (int i=0;i<size;i++){
		arr[i] = i+1;
	}
	
	DynJag2dArrInt darr(row_size,col_sizes,arr);
	darr.printArray();
	
	cout << "set value\n";
	try{
		darr(2,5) = 15;
	}
	catch(ArrayIndexOutOfBoundsException& e)
    {
        cout << e.what() << endl;
    }
	
	cout << "access value\n";
	try{
		cout<< darr(2,2) << endl << endl;
	}
	catch(ArrayIndexOutOfBoundsException& e)
    {
        cout << e.what() << endl;
    }
	
	cout << "push back col value\n";
	darr.pushBackCol(2,7);
	darr.printArray();
	
	cout << "push back row values\n";
	int c[2]={8,9};
	try{
		darr.pushBackRow(c,2);
	}
	catch(ArrayIndexOutOfBoundsException& e)
    {
        cout << e.what() << endl;
    }
	darr.printArray();
	
	cout << "get row and col sizes\n";
	cout<< "rows: " << darr.getRowSize() << " cols: " << darr.getColSize(3) << " \n";
}
