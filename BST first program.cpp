#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int x)
	{
		data=x;
	}
};
class Btree{
	public:
		Node *root;
		Btree()
		{
			root=NULL;
		}
		void insert(int n)
		{
			Node *nw=new Node(n);
			Node *t=root;
			Node *r=NULL;
			if(root==NULL)
			{
				root=nw;
				return;
			}
			while(t!=NULL)
			{
				r=t;
			if(n<t->data)
			{
				t=t->left;
				}
			else if(n>t->data)
			{
				t=t->right;
			}
			else if(n==t->data)
			{
				cout<<"DUPLICATE FOUND!"<<endl;
				return;
			}
							
			}
			if(n>r->data)
			{
				r->right=nw;
				return;
			}
			else if(n<r->data)
			{
				r->left=nw;
				return;
			}
			
			
		}
		void print()
		{
			Node *temp=root;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
			
		}
		
	
};

int main()
{
	Btree n;
	n.insert(5);
	n.insert(10);
	n.print();
}

