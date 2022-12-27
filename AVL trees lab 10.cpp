#include<iostream>
using namespace std;


class node{
	
	public:
		node *left;
		node *right;
		int height;
		int data;
		
		node()
		{
			left=NULL;
			right=NULL;
			data=-1;
		}
		node(int d)
		{
			left=NULL;
			right=NULL;
			data=d;
		}
};

node *root=NULL;
	
	int calculateheight(node *p);
	int balancefactor(node *p);	
		
		node * LLrotation(node *p)//
		{
			node *pl=p->left;
			node *plr=pl->right;
			
			pl->right=p;
			p->left=plr;
			p->height=calculateheight(p);
			pl->height=calculateheight(pl);
			if(root==p)
			{
				root=pl;
			}
			return pl;
		}
		node *LRrotation(node *p)
		{
			node *pl=p->left;
			node *plr=pl->right;
			
			pl->right=plr->left;
			p->left=plr->right;
			plr->left=pl;
			plr->right=p;
			
			pl->height=calculateheight(pl);
			p->height=calculateheight(p);
			plr->height=calculateheight(plr);
			
			return plr;
		}
		node * insertroot(int value,node *p)
		{
			
			
			if(p==NULL)
			{
				node *n=new node(value);
				n->height=1;
				return n;
			}
			else if(p->data<value)
			{
				p->right=insertroot(value,p->right);
			}
			else
			{
				p->left=insertroot(value,p->left);
			}
			p->height=calculateheight(p);
			if(balancefactor(p)==2&& balancefactor(p->left)==1)
			{
				LLrotation(p);
			}
			else if(balancefactor(p)==2 && balancefactor(p->left)==-1)
			{
				LRrotation(p);
			}
			else if(balancefactor(p)==-2 && balancefactor(p->right)==-1)
			{
				//return RRrotation(p);
			}
			else if(balancefactor(p)==-2 && balancefactor(p->right)==1)
			{
				//return RLrotation(p);
			}
			return p;
			
		}
		
	void preorder(node *p)
	{
	if(p != NULL)
	{
		cout << p->data << " ";
		preorder(p->left);
		preorder(p->right);
	}
	}
	void postorder(node *p)
	{
	if(p != NULL)
	{
		
		postorder(p->left);
		postorder(p->right);
		cout << p->data << " ";
	}
	}
	void inorder(node *p)
	{
	if(p != NULL)
	{
		
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
		
	}
	}
	void deletenode(node *p)
		{
			int arr[]={ 55, 66, 77, 11, 33, 22, 25, 44, 88 };
			cout<<"Pre-Order: ";
			preorder(p);
			cout<<endl<<"Post-Order:";
			postorder(p);
			cout<<endl<<"In-Order:";
			inorder(p);
			
		}

		int calculateheight(node *p)
		{
			int hl, hr;
			if(p==NULL)
			{
				return -1;
				
			}
			else
			{
				hl=calculateheight(p->left);
				hr=calculateheight(p->right);
				if(hl>hr)
				{
					return(hl+1);
				}
				else
				{
					return(hr+1);
				}
			}
		}
		int balancefactor(node *p)
		{
			int hl, hr;
			hl=calculateheight(p->left);
			hr=calculateheight(p->right);
			int h=hl-hr;
			return h;
		}
	void search(node *find,int x,int y,int z)
	{
	if(find !=NULL)
	{
		if(find->data == x || find->data == y || find->data == z)
		{
			cout<<find->data<<" has been found"<<endl;
		}
		search(find->left,x,y,z);
		search(find->right,x,y,z);
	}
}


		
int main()
{
	
	
	int arr[]={ 55, 66, 77, 11, 33, 22, 35, 25, 44, 88,99 };
	root=insertroot(arr[0],root);
	for(int i=1;i<11;i++)
	{
		insertroot(arr[i],root);
	}
	cout<<"Height of tree is:"<<calculateheight(root)<<endl;
	cout<<"Searching of 66,22,44: "<<endl;
	search(root,66,22,44);
	cout<<"After deleting orders are: "<<endl;
	deletenode(root);
	
	
}
