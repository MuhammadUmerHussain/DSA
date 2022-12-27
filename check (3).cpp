#include<iostream>
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
//		DynArr(const<Type>arr& otherObject){
//			size= otherObject.size;
//			capacity = otherObject.capacity;
//			
//			arr = new(nothrow) Type[size];
//			for(int i=0;i<size;i++){
//				arr[i] = otherObject.arr[i];
//			}
//		}
		
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
//			if(index <0 || index >= size){
//				throw ArrayIndexOutOfBoundsException(index);
//			}
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
class Maxheap{
	DynArr<int> A;
	
	public:
	
	int getparent(int index)
	{
		return(index-1)/2;
		
		}	
		
	int getleft(int index )
	{
		return (2*index+1);
		}
	int getright(int index )
	{
		return (2*index+2);
		}
	void siftdown(int index )
	{
		int left=getleft(index);
		int right=getright(index);
		
		int largest=index;
		
		if(A[index]<A[left]&& left<A.getSize())
		{
			largest=left;
		}
		 if(A[largest]<A[right] && right<A.getSize())
		{
			largest=right;	
		}
		if(largest!=index)
		{
			swap(A[index],A[largest]);
			siftdown(largest);
		}
				}			
		
	void siftup(int index)
	{
		if(index&&A[getparent(index)]<A[index])
		{
			swap(A[index],A[getparent(index)]);
			siftup(getparent(index));
		}
		
		}	
	void insert(int key)
	{
		A.pushBack(key);
		
		int index=A.getSize()-1;
		
		siftup(index);
	}
	int getmax()
	{
		return A[0];
	}
	void remove(int index)
	{
		A[index]=INT_MAX;
		siftup(index);
		extracTmAX();
	}
	
	
};
int main()
{
	
}
