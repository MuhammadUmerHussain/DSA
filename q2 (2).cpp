#include<iostream>
using namespace std;

class nodebst
{
	public:
		string word;
		nodebst *left;
		nodebst *right;
		
		nodebst()
		{
			
		}
		nodebst(string x)
		{
			word=x;
		}
};
nodebst *root=NULL;
nodebst *insertbst(nodebst *p,string value)
{
	if(p==NULL)
	{
		return new nodebst(value);
	}
	else if(value<p->word)
	{
		p->left=insertbst(p->left,value);
	}
	else if(value>p->word)
	{
		p->right=insertbst(p->right,value);
	}
	
}

void inorder(nodebst *p)
{
	cout<<"*"<<endl;
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<"Word "<<p->word<<endl;
		inorder(p->right);
	}
	
}
class Node{
	public:
	int data;
	Node *next;
	
	Node(int d,Node *ptr)
	{
		data=d;
		next=ptr;
	}
};


class singly{
	
	public:
		Node *head;
		
		singly()
		{
			head=NULL;
		}
		
		void push_back(int value)
		{
			Node *n;
			n=new Node(value,NULL);
			
			if(head==NULL)
			{
				head=n;
				return;
			}
			
			Node *temp;
			temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			
			
		}
		void delete_node(int position)
		{
			int count=1;
			Node *prev=NULL;
			Node *temp=head;
			
			while(count==position)
			{
				count++;
				prev=temp;
				temp=temp->next;
				
			}
			prev->next=temp->next;
			delete temp;
			temp=prev->next;
			
			
		}
		void deletelist()
		{
			Node *temp=head->next;
			Node *prev=head;
			
			//temp=head->next;
			
			while(prev!=NULL)
			{
				delete prev;
				prev=temp;
				temp=temp->next;
			}
		}
		
	
		
		void printList()
		{
	    	Node* temp = head;
		    while (temp != NULL)
			 {
		        cout << temp->data << " ";
		        temp = temp->next;
		    }
		    cout << "\n";
		}
		
	



		
		 
		
		
};
int main()
{
	root=new nodebst("balgorithem");
	insertbst(root,"umer");
	insertbst(root,"alogoithem");
	inorder(root);
}


