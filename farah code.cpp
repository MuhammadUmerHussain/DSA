#include <iostream>
using namespace std;
class BST
{
	int data;
	BST *left, *right; 
public:
	BST()
	{
		left=right=NULL;
		data=0;
	}
	BST(int x)
	{
		data = x;
		left = right = NULL;
	}
	BST* Insert(BST *node, int value)
	{
		if (!node)
		{
			return new BST(value);
		}
		if (value > node->data)
		{
			node->right = Insert(node->right, value);
		}
		else
		{
			node->left = Insert(node->left, value);
		}
		return node;
	}
	void Inorder(BST *node)
	{
		if (!node)
		{
			return;
		}
		Inorder(node->left);
		cout<<node->data<<" ";
		Inorder(node->right);
	}
	int findMax(BST* root)
	{
		if(root==NULL)
		{
			return INT_MIN;
		}
		int max=root->data;
		int lmax=findMax(root->left);
		int rmax=findMax(root->right);
		if(lmax>max)
		{
			max=lmax;
		}
		if(rmax>max)
		{
			max=rmax;
		}
		return max;
	}
	int findMin(BST* root)
	{
		if(root==NULL)
		{
			return INT_MAX;
		}
		int min=root->data;
		int lmin=findMin(root->left);
		int rmin=findMin(root->right);
		if(lmin<min)
		{
			min=lmin;
		}
		if (rmin<min)
		{
			min=rmin;
		}
		return min;
	}
};
int main()
{
	int min, max, x;
	BST b, *node = NULL;

	cout<<"Level 1: Enter 1 No(s)."<<endl;
	for(int i=0;i<1;i++)
	{
		cin>>x;
		if(i==0)
		{
			node=b.Insert(node, x);
		}
		b.Insert(node, x);
	}
	cout<<"Miniumum: "<<b.findMin(node)<<endl;
	cout<<"Maxiumum: "<<b.findMax(node)<<endl;
	
	cout<<"Level 2: Enter 2 No(s)."<<endl;
	for(int i=0;i<2;i++)
	{
		cin>>x;
		if(i==0)
		{
			node=b.Insert(node, x);
		}
		b.Insert(node, x);
	}
	cout<<"Miniumum: "<<b.findMin(node)<<endl;
	cout<<"Maxiumum: "<<b.findMax(node)<<endl;
	
	cout<<"Level 3: Enter 4 No(s)."<<endl;
	for(int i=0;i<4;i++)
	{
		cin>>x;
		if(i==0)
		{
			node=b.Insert(node, x);
		}
		b.Insert(node, x);
	}
	cout<<"Miniumum: "<<b.findMin(node)<<endl;
	cout<<"Maxiumum: "<<b.findMax(node)<<endl;
	
	cout<<"Level 4: Enter 3 No(s)."<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>x;
		if(i==0)
		{
			node=b.Insert(node, x);
		}
		b.Insert(node, x);
	}
	cout<<"Miniumum: "<<b.findMin(node)<<endl;
	cout<<"Maxiumum: "<<b.findMax(node)<<endl;
	
	return 0;
}
