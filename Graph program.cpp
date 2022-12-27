#include<iostream>
#include<queue>

using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node()
		{
			data=-1;
			next=NULL;
			
		}
		node(int x)
		{
			data=x;
		}
};

class List
{
	public:
		node *head;
		
		List()
		{
			head=NULL;
		}
		
		void addnode(int x)
		{
			node *n=new node(x);
			if(head==NULL)
			{
				head=n;
				return;
			}
			node *temp=head;
			while(temp->next!=NULL)
			{
				cout<<"*";
				temp=temp->next;
			}
			temp->next=n;
			return;
		}
		void print()
		{
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
	
};

class graph{
	
	public:
		List *array;
		int vertex;
		graph()
		{
			array=NULL;
		}
		graph(int x)
		{
			array=new List[x];
		}
		void create(int x)
		{
			vertex=x;
			array=new List[x];
		}
		void addedge(int u,int v)
		{
			array->addnode(u);
			array->addnode(v);
		}
		void BFS(int x)
		{
			int value[vertex];
			for(int i=0;i<vertex;i++)
				value[vertex]=0;
			
				
			
		}
		void print()
		{
			for(int i=0;i<vertex;i++)
			{
				cout<<i<<" ";
				array[i].print();
			}
		}
};
int main()
{
	graph g;
	g.create(3);
	g.addedge(0,1);
	g.print();
	
}
