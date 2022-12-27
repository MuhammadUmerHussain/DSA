#include<iostream>
using namespace std;


class node{
	public:
		int data;
		int key;
		
		node()
		{
			
			
		}
		node(int d,int k)
		{
			data=d;
			key=k;
			
		}
	
};

class hash{
	
	public:
		node **arr;
		node *dummy;
		int size;
		int capacity;
		
		hash(int c)
		{
			capacity=c;
			arr=new node*[c];
			for(int i=0;i<capacity;i++)
			{
				arr[i]=NULL;
			}
			dummy=new node(-1,-1);
			
		}
		int hasfun(int k)
		{
			return k%capacity;
		}
		void insertnode(int data,int value)
		{
			node *n=new node(value,data);
			if(size==capacity)
			{
				cout<<"Hastable is full"<<endl;
				exit(1);
			}
			int index=hasfun(data);
			
			while(arr[index]!=NULL)
			{
				index++;
				index=hasfun(index);
			}
			
			if(arr[index]==NULL)
			{
				arr[index]=n;
				size++;
			}
		}
		int deletenode(int key)
		{
			int index=hasfun(key);
			while(arr[index]!=NULL)
			{
				if(arr[index]->key==key)
				{
					node *temp=arr[index];
						arr[index]=dummy;
						return temp->data;
				}
				index++;
				index=hasfun(index);
			}
			return -1; 
			
		}
		int getvaluefromkey(int key)
		{
			int index=hasfun(key);
			int counter=0;
			while(arr[index]!=NULL)
			{
				if(arr[index]->key==key)
				{
					return arr[index]->data;
				}
				counter++;
				index++;
				index=hasfun(index);
				if (counter>capacity)
				{
					cout<<"no found!"<<endl;
					return -1;
				}
			}
		}
		void printtable()
		{
			
		}
		
};
int main()
{
	hash h(5);
	h.insertnode(5,20);
	h.insertnode(6,19);
	cout<<h.getvaluefromkey(5);
	
}
