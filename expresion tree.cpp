#include<iostream>
using namespace std;
#include<queue>

class node{
	public:
		
		string a;
		node *left;
		node *right;
		node()
		{
			
		}
		node(string x)
		{
			a=x;
			left=NULL;
			right=NULL;
		}
		
};
node *root=NULL;
class nodel{
	public:
		char x;
		nodel *next;
		nodel()
		{
			next=NULL;
		}
		nodel(char a)
		{
			x=a;
			next=NULL;
		}
};

class stack{
	
	public:
		
		nodel *temp;
		stack()
		{
			temp=NULL;
		}
		
		
	void push(char x)
	{
		nodel *n=new nodel(x);
		if(temp==NULL)
		{
			
			temp=n;
			return;
		}
		
		else
		{
		n->next=temp;
		temp=n;
		return;
		}
		
		}
		char pop()
		{
			char d=temp->x;
			nodel *temp2=temp;
			temp=temp->next;
			delete temp2;
			return d;
			
			
		}
		char peek()
		{
			return temp->x;	
		}	
		
};



		
		
	node* insertNode(node* root, string data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = new node(data);
	        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<node*> q;
    q.push(root);
 
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = new node(data);
	            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = new node(data);
	            return root;
        }
    }
}
		void experssion(string x)
{
	//insertNode(root,x[0]);
	//inorder(root);
	stack s;
	//s.push(x[0]);
	
	for(int i=0;i<x.length();i++)
	{
		//cout<<"*";
		if(x[i]>='a'&& x[i]<='z')
		{
			s.push(x[i]);
			cout<<s.peek()<<endl;
		}
	}
	
}

		void inorder(node *p)
		{
			if(p==NULL)
			{
				return;
			}
			inorder(p->left);
			cout<<p->a;
			inorder(p->right);
		}
		


int main()
{
//	root=insertNode(root,"a");
//	insertNode(root,"b");
//	insertNode(root,"c");
//	insertNode(root,"d");
//	inorder(root);
	stack s;
//	s.push("x");
	


	
	string x="ab*c/ef/g*+k+xy*-";
	//cout<<x[0];
	experssion(x);
}
