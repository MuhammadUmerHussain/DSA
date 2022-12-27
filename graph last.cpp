#include<iostream>
#include<queue>
using namespace std;

class nodegraph{
	
	public:
		int data;
		nodegraph *next;
		
		nodegraph()
		{
			next=NULL;
		}
		nodegraph(int d)
		{
			data=d;
			next=NULL;
		}
};


class list{
	public:
		nodegraph *head;
		
		list()
		{
		
			head=NULL;
		}
		
		void addnode(int data)
		{
			nodegraph *n=new nodegraph(data);
			if(head==NULL)
			{
				head=n;
				return;
				
			}
			nodegraph *temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			return;
		}
		
		
		
		
};

class graph{
	public:
		list *ptr;
		int vertex;
		
		graph()
		{
			ptr=NULL;
		}
		graph(int n)
		{
			ptr=new list[n];
			vertex=n;
		}
		
		void addedge(int x,int y)
		{
			ptr[x].addnode(y);
			ptr[y].addnode(x);
		}
		void bfs(int x)
		{
			int valid[vertex];
			for(int i=0;i<vertex;i++)
			{
				valid[i]=0;
			}
			queue<int> q;
			q.push(x);
			valid[x]=1;
			while(!q.empty())
			{
				x=q.front();
				cout<<x<<endl;
				q.pop();
				
				for(nodegraph *temp=ptr[x].head;temp!=NULL;temp=temp->next)
				{
					if(!valid[temp->data])
				{
					q.push(temp->data);
					valid[temp->data]=1;
				}
				}
				
				
				
			}
		}
		void dfs(int x)
		{
			bool visited[vertex]={false};
			cout<<x<<" ";
			visited[x]=1;
			
			for(nodegraph *temp=ptr[x].head;temp!=NULL;temp=temp->next)
			{
				if(!visited[temp->data])
				{
					visited[temp->data]=1;
					dfssearch(visited,temp->data);
				}
			}
		}
		void dfssearch(bool visited[],int x)
		{
			cout<<x<<endl;
			visited[x]=1;
			for(nodegraph *temp=ptr[x].head;temp!=NULL;temp=temp->next)
			{
				if(!visited[temp->data])
				{
					visited[temp->data]=1;
					dfssearch(visited,temp->data);
				}
			}
		}
			
		};
		


int main()
{
	graph g(5);
	g.addedge(0,1);
	g.addedge(2,3);
	g.addedge(4,0);
	g.dfs(0);
	g.bfs(0);
}
