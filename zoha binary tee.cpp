#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
		
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
      node *create_node(int d)
      {
      	node *n=new node(d);
      	n->data=d;
      	n->left=NULL;
      	n->right=NULL; 
      	return n;
	  }
	  node *insert(node *root,int d)
	  {
	  	if(root==NULL)
	  	{
	  		root=create_node(d);
	  		return root;
		  }
		  queue<node*>q;
		  q.push(root);
		  
		  while(!q.empty())
		  {
		  	node *temp=q.front();
		  	q.pop();
		  	if(temp->left!=NULL)
		  	{
		  		q.push(temp->left);
			  }
			  else{
			  	temp->left=create_node(d);
			  	return root;
			  }
			  if(temp->right!=NULL)
		  	{
		  		q.push(temp->right);
			  }
			  else{
			  	temp->right=create_node(d);
			  	return root;
			  }
		  }
	  }
	  
	 
	  void search(node *temp,int find)
	  {
	  	if(temp==NULL)
	  	{
	  		
	  		return;
		  }
		  else
		  {
		  	search(temp->left,find);
		  	if(temp->data==find)
		  	{
		  		cout<<"found!"<<endl;
		  		return;
			  }
		  	search(temp->right,find);
		  	if(temp->data==find)
		  	{
		  		cout<<"found!"<<endl;
		  		return;
			  }
		  }
	  }
	  int main()
	  {
	  	node *root=create_node(1);
	  	root->left=create_node(2);
	  	root->right=create_node(3);
	  	root->left->left=create_node(4);
	  	root->left->right=create_node(5);
	  	
//	  	in_order(root);
	  	
	  	search(root,3);
	  	
	  	//root=insert(root,100);
//	  	cout"INORDER TRAVERSAL AFTER INSERTION:";
	  	
	  }
