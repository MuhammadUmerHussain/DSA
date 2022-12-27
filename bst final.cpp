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
	
	int calculateheight(node *p)
	{
		if(p==NULL)
		{
			return -1;
		}
		else
		{
			int hl=calculateheight(p->left);
			int hr=calculateheight(p->right);
			
			if(hl>hr)
			{
				return (hl+1);
			}
			else
			{
				return (hr+1);
			}
		}
	}
	node *predes(node *p)
	{
		while(p&&p->right!=NULL)
		{
			p=p->right;
		}
		
			return p;
		
	}
	node *insuc(node *p)
	{
		while(p&&p->left!=NULL)
		{
			p=p->left;
		}
			return p;
	}
	
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
	node *deletenode(node *p,int d)
	{
		if(p==NULL)
		{
			return NULL;
		}
		if(p->right==NULL && p->left==NULL)
		{
			if(p==NULL)
			
			{
				root=NULL;
				
			}
			//free(p);
			return NULL;
			
		}
		if(d>p->data )
		{
			p->right=deletenode(p->right,d);
		}
		else if(d<p->data)
		{
			p->left=deletenode(p->left,d);
		}
		else 
		{
			
			if(calculateheight(p->left)>calculateheight(p->right))
			{
				
				node *q=predes(p->left);
				p->data=q->data;
				p->left=deletenode(p->left,q->data);
			}
			else
			{
				//cout<<"*";
				node *q=insuc(p->right);
				p->data=q->data;
				p->right=deletenode(p->right,q->data);
			}
		}
		//cout<<"*";
		return p;
		
	}
	
	void levelorder(node *p)
	{
		queue<node *>q;
		q.push(p);
		q.push(NULL);
		node *n;
		while(!q.empty())
		{
			n=q.front();
			
			q.pop();
		
		if(n!=NULL)
		{
			cout<<n->data<<" ";
				
			if(n->left!=NULL)
			{
				q.push(n->left);
			}
			if(n->right!=NULL)
			{
				q.push(n->right);
			}
		}
		else if(!q.empty())
		{
			q.push(NULL);
		}
		}
	}
	//static int counter=0;
	int  decendant(node *p,int counter)
	{
		int hl;
		if(p->right==NULL && p->left==NULL)
		{
			//cout<<"*";
			//cout<<counter<<endl;
			return counter;
		}
		else if(p->left!=NULL)
		{
			hl=decendant(p->left,counter+1);
		}
		 if(p->right!=NULL)
		{
		hl=hl+decendant(p->right,counter+1);	
		
		}
		//cout<<"*";
		return hl;
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
		int counter=0;
		cout<<decendant(root,counter);
		//deletenode(root,4);
		//levelorder(root);
		//cout<<counter<<endl;
	
	}
	
