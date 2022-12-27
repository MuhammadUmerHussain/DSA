#include<iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class ArrayIndexOutOfBoundsException;

template <typename Type>
class DynArr
{
	private:
		Type* arr;
		int size;
		int capacity;
		
	public:
		enum { SPARE_CAPACITY = 10 };
		
		// Constructor
		DynArr(int size_=0){
			// Todo: check size can be zero or negative
			size = size_;
			capacity  = size + SPARE_CAPACITY;
			arr = new(nothrow) Type[capacity];
			
			for (int i=0;i<size;i++){
				arr[i] = 0;
			}
		}
		
		// Copy constructor
		DynArr(const DynArr& otherObject){
			size= otherObject.size;
			capacity = otherObject.capacity;
			
			arr = new(nothrow) Type[size];
			for(int i=0;i<size;i++){
				arr[i] = otherObject.arr[i];
			}
		}
		
		// Assignment operator
		DynArr& operator=(const DynArr& rightObject){
			if (this != &rightObject){
				size = rightObject.size;
				capacity = rightObject.capacity;
				
				delete [] arr;
				arr = new(nothrow) Type[capacity];
				for (int i=0;i<size;i++){
					arr[i] = rightObject.arr[i];
				}
			}
			return *this;
		}
		
		// Access operator
		Type& operator[](int index){
			if (index < 0 || index >= size){
				throw ArrayIndexOutOfBoundsException();
			}
			return arr[index];
		}
		
		// Destructor
		~DynArr(){
			delete [] arr;
		}
		
		// PushBack
		void pushBack(int val){
			if(size == capacity){
				Type* new_arr = new(nothrow) Type[2*capacity];
				for (int i=0;i<size;i++){
					new_arr[i] = arr[i];
				}
				delete arr;
				arr = new_arr;
				capacity = 2*capacity;
			}
			arr[size++]=val;
		}
		
		// Remove
		void remove(int index){
			if(index <0 || index >= size){
				throw ArrayIndexOutOfBoundsException();
			}
			for (int i=index;i<size-1;i++){
				arr[i] = arr[i+1];
			}
			size -= 1;
		}
		
		// Size
		int getSize(){
			return size;
		}
		
		// print array
		void printArray(){
			for (int i=0;i< size;i++){
				cout<<arr[i]<<",";
			}
			cout<<endl;
		}
};

class ArrayIndexOutOfBoundsException : public std::exception
{
	public:
	const char * what () const throw ()
    {
    	return "Exception: Index out of bound!";
    }
};


class MaxHeap{
	DynArr<int> A;
	
	// parent of `A[i]`
    int getParent(int i) {
        return (i - 1) / 2;
    }
 
    // left child of `A[i]`
    int getLeft(int i) {
        return (2*i + 1);
    }
 
    // right child of `A[i]`
    int getRight(int i) {
        return (2*i + 2);
    }
    
    // Recursive sift-up algorithm
    void sift_up(int i)
    {
        
        if (i && A[getParent(i)] < A[i])
        {
           
            swap(A[i], A[getParent(i)]);
 
            
            sift_up(getParent(i));
        }
    }
    
    
    void sift_down(int i)//heapify
    {
        
        int left = getLeft(i);
        int right = getRight(i);
 
        int largest = i;
 
        if (left < size() && A[left] < A[i]) {
            largest = left;
        }
 
        if (right < size() && A[right] < A[largest]) {
            largest = right;
        }
 
        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            swap(A[i], A[largest]);
            sift_down(largest);
        }
    }
 
	public:
    
    unsigned int size() {
        return A.getSize();
    }
 
    
    bool empty() {
    
		 if(size() <= 0)
		 {
		 	return true;
		 }
		 return false;
    }
 
    
    void insert(int key)	
    {
        
        A.pushBack(key);
 
        
        int index = size() - 1;
        sift_up(index);
    }
 
    // Function to remove an element with the highest priority (present at the root)
    int extract_minium() 	
    {
    
        
            if (size() == 0)
            {
                cout<<"empty"<<endl;
                exit(1);
            }
 
		
			
			int min=A[0];
			// replace the root of the heap with the last element
			A[0] = A[size()-1];
			// remove last element
            A.remove(size()-1);
 
            // call sift-down on the root node
            sift_down(0);
            return min;
        
       
    }
 
    // Function to return an element with the highest priority (present at the root)
    int getMin()	// top
    {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                
                        cout<<"empty!";
                        exit(1);
            }
 
            // otherwise, return the top (first) element
            return A[0];
        
        // catch and print the exception
        
    }
    
    void remove(int i){
    	A[i] = INT_MIN;
    	sift_up(i);
    	extractMinimum();
	}
	void print()
	{
		A.printArray();
	}
	

};

int main()
{
	MaxHeap mh;
 
 
    mh.insert(10);
    mh.insert(15);
    mh.insert(30);
 
	
 
   
   
 	mh.insert(40);
    mh.insert(50);
    mh.insert(100);
    mh.insert(40);
 
    mh.print() ;
 
    return 0;
}
