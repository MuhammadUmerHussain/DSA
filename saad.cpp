#include<iostream>
using namespace std;
static int sum=0;
//this is the type iof binary tree which is called as Binary search tree no duplicates are handle in this!
class node
{
	public:
		int data;
		node *left;
		node *right;
		
		node()
		{
			data=-1;
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
void sumfunction(node *ptr)
{
    if (ptr==NULL) {
        return;
    }
    sumfunction(ptr->left);
    sum=sum+ptr->data;
    //cout<<sum<<endl;
    sumfunction(ptr->right);
}
node* insertnode(node *root,int x)
{
	if(root==NULL)
	{
		return new node(x);
	}
	else if(root->data>x)
	{
		root->left=insertnode(root->left,x);
	}
	else if(root->data<x)
	{
		root->right=insertnode(root->right,x);
	}
	
}

void input()
{
	int n;
	cout<<"Number Of Inputs Number: ";
	cin>>n;
	int a;
	int i=0;
	cout<<endl<<"Input "<<i+1<<" Number: ";
	cin>>a;
	node *root=new node(a);
	for(int i=1;i<n;i++)
	{
		cout<<endl<<"Input "<<i+1<<" Number: ";
		cin>>a;
		insertnode(root,a);
		
	}
	sumfunction(root);
	cout<<"SUM = "<< sum<<endl;
}



int main()
{
	
	input();
	//cout<<root->right->data;
	
}
