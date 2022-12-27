#include<iostream>
using namespace std;

class book{
	public:
	int value;
	int data;
	

	book(int v,int k)
	{
		value=v;
		data=k;
	}
	
	
};

class hash{
	
	book **arr;
	int size;
	int capacity;
	book *dummy;
	public:
	hash()
	{
		capacity=20;
		arr=new book*[capacity];
		
		for(int i=0;i<capacity;i++)
		{
			arr[i]=NULL;
		}
		dummy=new book(-1,-1);
	}
	
	int hashdata(int data)
	{
		return data%capacity;
	}
	
	void insertbook(int data,int value)
	{
		book *n=new book(value,data);
		
		int index=hashdata(data);
		//cout<<index<<endl;
		
		while(arr[index]!=NULL&&arr[index]->data!=-1)
		{
			index++;
			
			index=hashdata(index);
			
		}
		if(arr[index]==NULL||arr[index]->data==-1)
		{
			arr[index]=n;
			size++;
		}
	}
	int deletebook(int data)
	{
		int index=hashdata(data);
		
		while(arr[index]!=NULL &&arr[index]->data!=-1)
		{
			if(arr[index]->data==data)
			{
				book *temp=arr[index];
				arr[index]=dummy;
				size--;
				return temp->value;
			}
			index++;
			index=index%capacity;
		}
		return NULL;
	}
	int getvalue(int data)
	{
		
		
		int index=hashdata(data);
		
		int counter=0;
		while(arr[index]!=NULL && arr[data]->data!=-1)
		{
			counter++;
			if(arr[index]->data==data)
			{
				cout<<"found!"<<endl;
				return arr[index]->value;
			}
			if(counter>capacity)
			{
				return NULL;
			}
			index++;
			index=index%capacity;
		}
	}
	
	void display()
	{
		for (int i = 0; i < capacity; i++) {
			if (arr[i] != NULL && arr[i]->data != -1)
				cout << "data = " << arr[i]->data<< " value = "<< arr[i]->value << endl;
		}
	}
	
	
	
	
	
};
int main()
{
	hash h;
	h.insertbook(0346,1);
	h.insertbook(1864,2);
	h.insertbook(1684,5);
	
	cout<<"delete book: "<<h.deletebook(0346)<<endl;
	cout<<"Searching for book:"<<h.getvalue(1684)<<endl;
	
	h.display();
	
}
