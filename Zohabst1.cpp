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
	
	
	
	
	bool dispacthertest(node *root)
	{
		if (root == NULL)
    {
    return true;	
	}
     
  if (root->left != NULL && root->left->data > root->data)
    {
    return false;	
	}
     
  if (root->right != NULL && root->right->data < root->data)
    {
    return false;	
	}
   
  if (!dispacthertest(root->left) || !dispacthertest(root->right))
    {
    return false;	
	}
     
  
  return true;
	}
	
	int main()
	{
		root=insertnode(3,root);
		insertnode(4,root);
		insertnode(2,root);
		insertnode(5,root);
		if(dispacthertest(root))
		{
			cout<<"Allowed!"<<endl;
		}
		else
		{
			cout<<"False!"<<endl;
		}
		//deletenode(root,4);
		//levelorder(root);
		//cout<<counter<<endl;
	
	}
	
