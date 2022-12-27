#include <iostream>
using namespace std;


class Dyn2dArrInt
{
	private:
		int** arr;
		int row_size;
		int col_size;
		int row_cap;
		int col_cap;
		
	public:
		enum { 	SPARE_ROW_CAPACITY = 10,
				SPARE_COL_CAPACITY = 10 };
		
		// Constructor
		Dyn2dArrInt(int row_size_=1, int col_size_=1, int **a=0){
			// Todo: check row and col can be zero or negative
			row_size = row_size_;
			col_size = col_size_;
			row_cap  = row_size + SPARE_ROW_CAPACITY;
			col_cap  = col_size + SPARE_COL_CAPACITY;
			
			arr = new(nothrow) int*[row_cap];
			
			for (int i=0;i<row_cap;i++){
				arr[i] = new(nothrow) int[col_cap];
			}
			
			for (int i=0;i<row_size;i++){
				for (int j=0; j<col_size;j++){
					arr[i][j] =a[i][j];
				}
			}
		}
		
		// Copy constructor
		Dyn2dArrInt(const Dyn2dArrInt& otherObject){
			row_size= otherObject.row_size;
			col_size= otherObject.col_size;
			row_cap = otherObject.row_cap;
			col_cap = otherObject.col_cap;
			
			// assign new dynamic 2d array
			arr = new(nothrow) int*[row_cap];
			for (int i=0;i<row_cap;i++){
				arr[i] = new(nothrow) int[col_cap];
			}
			
			// copy arr's values to new arr
			for (int i=0;i<row_size;i++){
				for (int j=0; j<col_size;j++){
					arr[i][j] = otherObject.arr[i][j];
				}
			}
		}
		
		// Assignment operator
		const Dyn2dArrInt& operator=(const Dyn2dArrInt& rightObject){
			if (this != &rightObject){
				row_size= rightObject.row_size;
				col_size= rightObject.col_size;
				row_cap = rightObject.row_cap;
				col_cap = rightObject.col_cap;
				
				// delete arr
				for (int i=0;i<row_cap;i++){
					delete[] arr[i];
				}
				delete[] arr;
				
				// assign new dynamic 2d array
				arr = new(nothrow) int*[row_cap];
				for (int i=0;i<row_cap;i++){
					arr[i] = new(nothrow) int[col_cap];
				}
				
				// copy arr's values to new arr
				for (int i=0;i<row_size;i++){
					for (int j=0; j<col_size;j++){
						arr[i][j] = rightObject.arr[i][j];
					}
				}
			}
			return *this;
		}
		
		// Access operator
		int*& operator[](int row_index){
			if (row_index < 0 || row_index >= row_size){
				throw ("Exception: Index out of bound!");
			}
			return arr[row_index];
		}
		
		int& operator()(int row_index, int col_index){
			if ((row_index < 0 || row_index >= row_size) || 
				(col_index < 0 || col_index >= col_size)){
				throw ("Exception: row and col indices are out of bound.");
			}
			if (row_index < 0 || row_index >= row_size){
				throw ("Exception: row index out of bound!");
			}
			if(col_index < 0 || col_index >= col_size){
				throw ("Exception: col index out of bound!");
			}
			return arr[row_index][col_index];
		}

		// Destructor
		~Dyn2dArrInt(){
			for (int i=0;i<row_cap;i++){
				delete [] arr[i];
			}
			delete [] arr;
		}
		
		// pushBackCol
		void pushBackCol(int val[], int val_size){
			if (val_size != row_size){
				throw ("Excception: input array size is not same as the row size!");
			}
			if (col_size >= col_cap){
				// double col_cap
				int** new_arr = new(nothrow) int*[row_cap];
				for (int i=0;i<row_cap;i++){
					new_arr[i] = new(nothrow) int[2*col_cap];
				}
				// copy from arr to new_arr
				for (int i=0;i<row_size;i++){
					for (int j=0; j<col_size;j++){
						new_arr[i][j] = arr[i][j];
					}
				}
				// delete arr
				for (int i=0;i<row_cap;i++){
					delete [] arr[i];
				}
				delete [] arr;
				arr = new_arr;
				col_cap = 2*col_cap;
			}
			for (int i=0; i<row_size;i++){
				arr[i][col_size]=val[i];
			}
			col_size++;
		}
		
		// pushBackRow
		void pushBackRow(int val[], int val_size){
			if (val_size != col_size){
				throw ("Excception: input array size is not same as the col size!");
			}
			if (row_size >= row_cap){
				// double row_cap
				int** new_arr = new(nothrow) int*[2*row_cap];
				for (int i=0;i<row_cap;i++){
					new_arr[i] = new(nothrow) int[col_cap];
				}
				// copy from arr to new_arr
				for (int i=0;i<row_size;i++){
					for (int j=0; j<col_size;j++){
						new_arr[i][j] = arr[i][j];
					}
				}
				// delete arr
				for (int i=0;i<row_cap;i++){
					delete [] arr[i];
				}
				delete [] arr;
				arr = new_arr;
				row_cap = 2*row_cap;
			}
			for (int i=0; i<col_size;i++){
				arr[row_size][i] = val[i];
			}
			row_size++;
		}
	
		// Get
		int get(int row_index, int col_index){
			if ((row_index < 0 || row_index >= row_size) || 
				(col_index < 0 || col_index >= col_size)){
				throw ("Exception: row and col indices are out of bound.");
			}
			if (row_index < 0 || row_index >= row_size) {
				throw ("Exception: row index out of bound.");
			}
			if(col_index < 0 || col_index >= col_size){
				throw ("Exception: col index out of bound!");
			}
			return arr[row_index][col_index];
		}
		
		// Set
		void set(int row_index, int col_index, int val){
			if ((row_index < 0 || row_index >= row_size) || 
				(col_index < 0 || col_index >= col_size)){
				throw ("Exception: row and col indices are out of bound.");
			}
			if (row_index < 0 || row_index >= row_size) {
				throw ("Exception: row index out of bound.");
			}
			if(col_index < 0 || col_index >= col_size){
				throw ("Exception: col index out of bound!");
			}
			arr[row_index][col_index] = val;
		}

		// Size
		int getRowSize(){
			return row_size;
		}
		int getColSize(){
			return col_size;
		}
		
		// print array
		void printArray(){
			for (int i=0;i<row_size;i++){
				for (int j=0; j<col_size;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
};

int main()
{
	int rows = 4, cols = 4;
	int maze[rows][cols] = {{0,1,1,1},
						    {0,1,1,1},
						    {0,0,1,1},
						    {1,0,0,2}};
	
	int **tmp_arr = new int*[1];
	for (int i=0;i<rows;i++){
		tmp_arr[i] = new int[2];
		tmp_arr[i][0] = 0;		// first position indexes
		tmp_arr[i][1] = 0;
	}
	
	Dyn2dArrInt ans(1,2,tmp_arr);
	
	int i = 0, j = 0;
	while (i < rows && j < cols){
		// check path right
		if (maze[i][j+1] == 0 ||
			maze[i][j+1] == 2){
			int a[2]={i,j+1};
			ans.pushBackRow(a, 2);
			if (maze[i][j+1] == 2)
				break;
			j++;
		}
		// check path down
		else if (maze[i+1][j] == 0 || 
				maze[i+1][j] == 2){
				int a[2]={i+1,j};
				ans.pushBackRow(a, 2);
				if (maze[i+1][j] == 2)
					break;
				i++;
		}
		else{
			j++;
		}
	}
	cout<<endl;
	ans.printArray();
}
