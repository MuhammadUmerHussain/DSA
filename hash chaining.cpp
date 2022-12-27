#include<iostream>
using namespace std;


class nodehash{
	public:
		int data;
		int key;
		
		nodehash *next;
		nodehash()
		{
			data=-1;
			key=-1;
			next=NULL;
		}
		nodehash(int x,int y)
		{
			data=x;
			key=y;
		}
};


class hash{
	public:
		nodehash **arr;
		int table_size;
		
		hash(int x)
		{
			table_size=x;
			arr=new nodehash*[table_size];
			for(int i=0;i<table_size;i++)
			{
				arr[i]=NULL;
			}
	    }
	    
	    int hashfun(int x)
	    {
	    	return x%table_size;
		}
	    
		void insertnode(int value,int key)
		{
			int hashvalue=hashfun(key);
			
			nodehash *n=new nodehash(value,key);
			
			
			nodehash *temp=arr[hashvalue];
			
			if(temp==NULL)
			{
				temp=n;
				return;
			}
			while(temp->next!=NULL)
			{
				cout<<"*";
				temp=temp->next;
			}
			temp->next=n;
			return;
			
			
		}
		
};

int main()
{
	hash h(9);
	h.insertnode(4,7);
}
