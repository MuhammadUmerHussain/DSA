#include<iostream>
using namespace std;
#include<queue>

class node
	{
		public:
	int data;
	
	node *left;
	node *right;
	
	node()
	{
		data=0;
		left=NULL;
		right=NULL;
	}
	node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
	
	
	};
	
	node *root=NULL;
	node *insertnode(int x,node *p)
	{
		if(p==NULL)
		{
			return new node(x);
		}
		else if(p->data>x)
		{
			p->left=insertnode(x,p->left);
		}
		else if(p->data<x)
		{
			p->right=insertnode(x,p->right);
		}
		return p;
	}
	
	void inorder(node *root)
	{
		if(root==NULL)
		{
			return;
		}
		
		inorder(root->left);
		cout<<root->data<<" ";;
		inorder(root->right);
	}
	void postorder(node *root)
	{
		if(root==NULL)
		{
			return;
		}
		
		postorder(root->left);
		
		postorder(root->right);
		cout<<root->data<<" ";;
	}
	void preorder(node *root)
	{
		if(root==NULL)
		{
			return;
		}
		
		cout<<root->data<<" ";
		preorder(root->left);
		
		preorder(root->right);
	}
	node *root2;
	int main()
	{
		
		
	int 	X[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
		int Y[] = { 15, 10, 12, 8, 25, 30, 6, 20, 18, 9, 22 };
		root=insertnode(15,root);
		root2=insertnode(15,root2);
		for(int i=1;i<11;i++)
		{
			insertnode(X[i],root);
		}
		for(int i=1;i<11;i++)
		{
			insertnode(Y[i],root2);
			
		}	
		cout<<"Post Order "<<endl;
		postorder(root);
		cout<<endl<<"Pre Order "<<endl;
		preorder(root);
		cout<<endl<<"In Order "<<endl;
		inorder(root);
	}
	
