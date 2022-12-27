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
			next=NULL;
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
			array[u].addnode(v);
		}
		void print()
		{
			//cout<<""<<endl;
			for(int i=0;i<vertex;i++)
			{
				cout<<i<<" ";
				array[i].print();
			}
		}
		void BFS(int x)
		{
			int value[vertex];
			for(int i=0;i<vertex;i++)
				value[vertex]=0;
			
			queue<int> q;
			q.push(x);
			value[x]=1;
			
			while(!q.empty())
			{
				x=q.front();
				cout<<x<<" ";
				q.pop();
				
				for(node *temp=array[x].head;temp!=NULL;temp=temp->next)
				{
					//cout<<"*";
					if(!value[temp->data])
					{
						value[temp->data]=1;
						q.push(temp->data);
					}
					
				}
				
			}
			
				
			
		}
		//int value[vertex]=0;
		void DFS(int x)
		{
			int value[vertex];
			for(int i=0;i<vertex;i++)
				 value[vertex]=0;
				
			if(value[x]==0)
			{
				cout<<x<<" ";
				value[x]=1;
				}	
			
		}
		bool cyclicu(int x,int value[],int parent)
		{
			value[x]=1;
			
			for (node *temp=array[x].head;temp!=NULL;temp=temp->next)
			{
				if(!value[temp->data])
				{
					if(cyclicu(temp->data,value,x))
					{
						return true;
					}
				}
				else if(x!=parent)
				{
					return true;
				}
			}
			return false;
		}
		bool cyclic()
		{
			int value[vertex];
			for(int i=0;i<vertex;i++)
				value[vertex]=0;
				
			for(int i=0;i<vertex;i++)
			{
				if(!value[vertex])
				{
					if(cyclicu(i,value,-1))
					{
						return true;
					}
				}
				}	
			return false;
		}
};
int main()
{
	graph g;
	g.create(3);
	g.addedge(0,1);
	cout<<g.cyclic();
	//g.print();
	//g.BFS(0);
	
}
