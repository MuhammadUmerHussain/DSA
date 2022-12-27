#include<iostream>

using namespace std;

class bstnode{//it is a node of bst node height is maintained beacuse of levels
	public:
		int data;
		bstnode *bstl;//connecting left nodes
		bstnode *bstr;//connecting right nodes
		int height;
		
		bstnode()
		{
			data=0;
			bstl=NULL;
			bstr=NULL;
		}
		bstnode(int x)
		{
			data=x;
			bstl=NULL;
			bstr=NULL;
		}
	
};

bstnode* root=NULL;//global pointer of root
int calculateheight(bstnode *rt)//function to calculate height of tree
		{
			int hel, her;
			if(rt==NULL)//if root is null then
			{
				return -1;
				
			}
			else
			{
			
				hel=calculateheight(rt->bstl);//recursively calling lefttree assigning it
				her=calculateheight(rt->bstr);//recursively callling right tree and assigning it
				if(hel>her)//checking which tree height is greater 
				{
					return(hel+1);// +1 beacuse of that node
				}
				else
				{
					return(her+1);// +1 because of that node
				}
			}
		}
bstnode *insert_node(bstnode *rt,int value)
{
	
	if(rt==NULL)//root is null means root
	{
		bstnode *n=new bstnode(value);
		n->height=0;
		return n;
		
	}
	else if(value>rt->data)
	{
		rt->bstr=insert_node(rt->bstr,value);//else assigning to right side if greater 
	}
	else{
		rt->bstl=insert_node(rt->bstl,value);//else assigning to left side
	}
	rt->height=calculateheight(rt);//assigning height
	return rt;
	
		}
	
	int root_height(bstnode *rt)
	{
		return rt->height;//returning root height
	}
	
//	int check_min(bstnode *rt,int h,int i)
//	{
//		
//		//cout << i << endl;
//		if(rt==NULL)
//		{
//			return INT_MAX;
//		}
//		else if(i==h)
//		{	
//			return rt->data;
//		}
////		else if(rt->bstl==NULL && rt->bstr==NULL)
////		{
////			return rt->data;
////		}
//		else if(rt->bstl!=NULL)
//		{
//			
//			check_min(rt->bstl,h,i+1);
//		}
//		else if(rt->bstl==NULL && rt->bstr!=NULL)
//		{
//			
//			
//				check_min(rt->bstr,h,i+1);
//		
//		}
//	}
//				
//	int check_max(bstnode *rt,int h,int i)
//	{
//		
//		//cout << i << endl;
//		if(rt==NULL)
//		{
//			return INT_MAX;
//		}
//		else if(i==h)
//		{	int max=rt->data;
//			
//			
//		
//			return rt->data;
//		}
////		else if(rt->bstl==NULL && rt->bstr==NULL)
////		{
////			return rt->data;
////		}
//		else if(rt->bstr!=NULL)
//		{
//			
//			check_max(rt->bstr,h,i+1);
//		}
//		else if(rt->bstr==NULL && rt->bstl!=NULL)
//		{
//			
//			
//				check_max(rt->bstr,h,i+1);
//		
//		}
//	}
	int check_least(bstnode *rt,int rooth)
	{
		if(rt==NULL)
		{
			//it there is no node it will return maximum so it will never be a minimum of both
			return INT_MAX;
		}
		else if(rooth==0)
		{
			//there will be a time when height will substracted and becomes 0
			return rt->data;
		} 
		else 
		{
			//height is substracting so it will go through at that level
		rooth--;	
		return min(check_least(rt->bstl,rooth),check_least(rt->bstr,rooth));//min is a default fuction in library 
		//which will check minimum of both trees 
		}
	}

	int check_great(bstnode *rt,int rooth)
	{
		if(rt==NULL){
			//it there is no node it will return manimum so it will never be a maximum of both
			return INT_MIN;
		}
		else if(rooth==0)
		
		{
			
			//there will be a time when height will substracted and becomes 0
			return rt->data;
		} else 
		{
			//height is substracting so it will go through at that level
			rooth--;
		return max(check_great(rt->bstl,rooth),check_great(rt->bstr,rooth));//max is function which will check max of both trees
	}}	
	
			//as recursively calling each time a left side node and right side node will be given which will check maximum of both tree
void input()
{
	int a;
	cin>>a;
	int b;
	cin>>b;
	root=insert_node(root,b);
	int c;
	for(int i=0;i<a-1;i++)
	{
		cin>>c;
		insert_node(root,c);
		
	}
	for(int i=0;i<=root_height(root);i++)
	{
		cout<<check_least(root,i)<<" ";
		cout<<check_great(root,i)<<endl;
		
		 }	 
}
int main()

{
	
	input(); 
	 
	
	
	 
	 
	 
	 
	
	
	
}
