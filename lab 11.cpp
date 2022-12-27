#include<iostream>
using namespace std;

class node{
	public:
	int value;
	int data;
	

	node(int v,int k)
	{
		value=v;
		data=k;
	}
	
	
};

class hash{
	
	node **arr;
	int size;
	int capacity;
	node *dummy;
	public:
	hash()
	{
		capacity=20;
		arr=new node*[capacity];
		
		for(int i=0;i<capacity;i++)
		{
			arr[i]=NULL;
		}
		dummy=new node(-1,-1);
	}
	
	int hashdata(int data)
	{
		return data%capacity;
	}
	
	void insertnode(int data,int value)
	{
		node *n=new node(value,data);
		
		int index=hashdata(data);
		
		
		while(arr[index]!=NULL&&arr[index]->data==data&&arr[index]->data!=-1)
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
	int deletenode(int data)
	{
		int index=hashdata(data);
		
		while(arr[index]!=NULL &&arr[index]->data!=-1)
		{
			if(arr[index]->data==data)
			{
				node *temp=arr[index];
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
		int index=hashdata(index);
		int counter=0;
		while(arr[index]!=NULL && arr[data]->data!=-1)
		{
			counter++;
			if(arr[index]->data==data)
			{
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
	int middle_value(int value)
	{
		
		return value/2;
	}
	int mid_square_hash(int key)
	{
	int value = key*key;
	int mid= middle_value(value);
	
	return mid;
	}	
	void insertmidnode(int data,int value)
	{
		
		if(size==capacity)
		{
			cout<<"Full!"<<endl;
			return;
		}
		node *n=new node(value,data);
		
		int index=mid_square_hash(data);
		if(index>capacity)
		{
			cout<<"greater!"<<endl;
			return;
		}
		
		
		while(arr[index]!=NULL&&arr[index]->data==data&&arr[index]->data!=-1)
		{
			index++;
			index=mid_square_hash(index);
			
		}
		if(arr[index]==NULL||arr[index]->data==-1)
		{
			
			arr[index]=n;
			size++;
		}
	}
	int Folding_hash(int value1, int value2, int value3)
	{
	return value1 + value2 + value3;
	}
	void insertfoldnode(int data,int value)
	{
		node *n=new node(value,data);
		
		int index=Folding_hash(data,2,2);
		
		
		while(arr[index]!=NULL&&arr[index]->data==data&&arr[index]->data!=-1)
		{
			index++;
			index=Folding_hash(index,2,2);
			
		}
		if(arr[index]==NULL||arr[index]->data==-1)
		{
			arr[index]=n;
			size++;
		}
	}
	int getmidvalue(int data)
	{
		int index=index=mid_square_hash(index);
		int counter=0;
		while(arr[index]!=NULL && arr[data]->data!=-1)
		{
			counter++;
			if(arr[index]->data==data)
			{
				return arr[index]->value;
			}
			if(counter>capacity)
			{
				return NULL;
			}
			index++;
			index=mid_square_hash(index);
		}
	}
	int getfoldvalue(int data)
	{
		int index=Folding_hash(index,2,2);
		int counter=0;
		while(arr[index]!=NULL && arr[data]->data!=-1)
		{
			counter++;
			if(arr[index]->data==data)
			{
				return arr[index]->value;
			}
			if(counter>capacity)
			{
				return NULL;
			}
			index++;
			index=Folding_hash(index,2,2);
		}
	}
	int deletemidnode(int data)
	{
		int index=mid_square_hash(data);
		
		while(arr[index]!=NULL &&arr[index]->data!=-1)
		{
			if(arr[index]->data==data)
			{
				node *temp=arr[index];
				arr[index]=dummy;
				size--;
				return temp->value;
			}
			index++;
			index=mid_square_hash(data);
		}
		return NULL;
	}
	int deletefoldnode(int data)
	{
		int index=Folding_hash(index,2,2);
		
		while(arr[index]!=NULL &&arr[index]->data!=-1)
		{
			if(arr[index]->data==data)
			{
				node *temp=arr[index];
				arr[index]=dummy;
				size--;
				return temp->value;
			}
			index++;
			index=Folding_hash(index,2,2);
		}
		return NULL;
	}
	
	
	
};
int main()
{
	hash h;
	h.insertnode(1,1);
	h.insertnode(2,2);
	h.insertnode(2,5);
	
	cout<<"delete node: "<<h.deletenode(1)<<endl;
	h.insertmidnode(3,3);
	h.insertfoldnode(4,1);
	h.display();
	
}
