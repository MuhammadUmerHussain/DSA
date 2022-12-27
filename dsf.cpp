#include<iostream>
using namespace std;
#define size 5
class node{

	public:
		int value;
		int key;
		node *next;
		node(int k,int v)
		{
			key=k;
			value=v;
		}
}

class hash{
	
	node ** table;
	
	hash()
	{
		table=new node*[size];
		for(int i=0;i<size;i++)
		{
			table[i]=NULL;
		}
		
	}
	int haskey(int key)
	{
		return key%size;
	}
	void insert(int key,int value)
	{
		int index=hashkey(key);
		node *n=table[index];
		node *prev=NULL;
		
		while(n!=NULL)
		{
			prev=n;
			n=n->next;
		}
		if(n==NULL)
		{
			n=new node(key,value);
			if(prev==NULL)
			{
				arr[index]=n;
			}
			else
			{
				prev->next=n;
			}
		}
		
	}
};

int main()
{
	
	
}
