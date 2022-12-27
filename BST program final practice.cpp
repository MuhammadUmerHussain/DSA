#include<iostream>
using namespace std;
#include <queue>
class Nodebst{
	public: 
	int data;
	Nodebst *left;
	Nodebst *right;
	
	int height;
	Nodebst()
	{
		
	}
	Nodebst(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};
	int balancefactor(Nodebst *p);
	Nodebst *Rlrotation(Nodebst *p);
	Nodebst *LRrotation(Nodebst *p);
int calculateheight(Nodebst *p);
	Nodebst * LLrotation(Nodebst *p);
		Nodebst * RRrotation(Nodebst *p);
Nodebst *root=NULL;

		
		Nodebst * insert(Nodebst *p,int x)
		{
			if(p==NULL)
			{
				Nodebst *n=new Nodebst(x);
				n->height=1;
				return n;
			}
			else if(x>p->data)
			{
				p->right=insert(p->right,x);
			}
			else if(x<p->data)
			{
				p->left=insert(p->left,x);
			}
			p->height=calculateheight(p);
			if(balancefactor(p)==2 && balancefactor(p->left)==1)
			{
				LLrotation(p);
			}
			else if(balancefactor(p)==-2 &&balancefactor(p->right)==-1)
			{
				RRrotation(p);
			}
			else if(balancefactor(p)==2 && balancefactor(p->left)==-1)
			{
				LRrotation(p);
			}
			else if(balancefactor(p)==-2 && balancefactor(p->right)==1)
			{
				Rlrotation(p);
			}
			//calculateheight(p);
			return p;
			
		}
		Nodebst *Inpre(Nodebst *p)
		{
			if(p&&p->right!=NULL)
			{
				Inpre(p->right);
			}
			else
			{
				return p;
			}
		}
		Nodebst* Insuc(Nodebst *p)
		{
			if(p && p->left!=NULL)
			{
				Insuc(p->left);
				
			}
			else
			{
				return p;
			}
		}
		
		Nodebst * deletenode(Nodebst *p,int key)
		{
			Nodebst *q;
			if(p==NULL)
			{
				return NULL;
			}
			if(p->right==NULL && p->left==NULL)
			{
				if(p==root)
				{
					root=NULL;
					//free(p);
					
					
				}
				return NULL;
			}
			if(key>p->data)
			{
				p->right=deletenode(p->right,key);
			}
			else if(key<p->data)
			{
				p->left=deletenode(p->left,key);
			}
			
			else
			{
				if(calculateheight(p->left)>calculateheight(p->right))
				{
					Nodebst *q=Inpre(p->left);
				p->data=q->data;
				p->left=deletenode(p->left,q->data);
				}
				else
				{
					q=Insuc(p->right);
					p->data=q->data;
					p->right=deletenode(p->right,q->data);
				}
			}
		}
		void inorder(Nodebst *p)
		{
			if(p==NULL)
			{
				return;
			}
			inorder(p->left);
			cout<<p->data<<" ";
			inorder(p->right);
			
		}

		void search(Nodebst *p,int x)
		{
			if(p==NULL)
			{
				return;
			}
			if(p->data==x)
			{
				cout<<"Found Height"<<p->height<<endl;
				return;
			}
			
			if(x>p->data)
			{
				search(p->right,x);
			}
			else if(x<p->data)
			{
				search(p->left,x);
			}
			
		}
//		void topView(Nodebst * p) 
//		{
//			if(p==NULL)
//			{
//				return;
//			}
//			topView(p->left);
//			cout<<p->data<<" ";
//			
//			if(p==root)
//			{
//				topViewR(p);
//			}
//    	}
    	void topViewR(Nodebst *p)
    	{
    		if(p==NULL)
    		{
    			return;
			}
			cout<<p->data<<" ";
			topViewR(p->right);
		}
		
		int calculateheight(Nodebst *p)
		
		{
			
			if(p==NULL)
			{
				//cout<<"*";
				
				return -1;
			}
			
			else{
			
			 int hl=calculateheight(p->left);
			 int hr=calculateheight(p->right);
			
			if(hr>hl)
			{
				return (hr+1);
			}
			else 
			{
				return (hl+1);
			}
		}
		}
		int balancefactor(Nodebst *p)
		{
			int hl,hr,h;
			hl=calculateheight(p->left);
			hr=calculateheight(p->right);
			h=hl-hr;
			return h;
		}
		Nodebst * LLrotation(Nodebst *p)
		{
			Nodebst *pl=p->left;
			Nodebst  *plr=pl->right;
			
			pl->right=p;
			p->left=plr;
			
			pl->height=calculateheight(pl);
			p->height=calculateheight(p);
			if(root==p)
			{
				root=pl;
			}
			return pl;
			
		}
		Nodebst *LRrotation(Nodebst *p)
		{
			Nodebst *pl=p->left;
			Nodebst *plr=p->right;
			
			p->left=plr->right;
			pl->right=plr->left;
			
			plr->left=pl;
			plr->right=p;
			plr->height=calculateheight(plr);
			p->height=calculateheight(p);
			pl->height=calculateheight(pl);
			
			return plr;
		}
		
		Nodebst *Rlrotation(Nodebst *p)
		{
			Nodebst *pr=p->right;
			Nodebst *prl=pr->left;
			
			p->right=prl->left;
			pr->left=prl->right;
			
			prl->left=p;
			prl->right=pr;
			prl->height=calculateheight(prl);
			p->height=calculateheight(p);
			pr->height=calculateheight(pr);
			
			return prl;
		}
		Nodebst *RRrotation(Nodebst *p)
		{
			Nodebst *pr=p->right;
			Nodebst *prl=pr->left;
			
			pr->left=p;
			p->right=prl;
			
			pr->height=calculateheight(pr);
			p->height=calculateheight(p);
			
			if(root==p)
			{
				root=pr;
			}
			return pr;
			
		}
		void levelorder(Nodebst *p)
		{
			
			queue<Nodebst*> q;
			Nodebst *n;
			//cout<<p->data<<" ";
			q.push(p);
			q.push(NULL);
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
		
		
//		int calculateheight(node *p)
//		{
//			int hl, hr;
//			if(p==NULL)
//			{
//				return -1;
//				
//			}
//			else
//			{
//				hl=calculateheight(p->left);
//				hr=calculateheight(p->right);
//				if(hl>hr)
//				{
//					return(hl+1);
//				}
//				else
//				{
//					return(hr+1);
//				}
//			}
//		}

int main()
{
	root=insert(root,10);
	
	insert(root,20);
	insert(root,30);
	//deletenode(root,30);
	//cout<<root->left->data<<endl;
//	inorder(root);
	cout<<endl;
//	levelorder(root);
	search(root,50);
	//cout<<"height "<<calculateheight(root)<<endl;
}
