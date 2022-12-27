#include<iostream>

using namespace std;


class Node
{
	public:
	int data;
	Node *next;
	
	public:
	Node()
	{
		
	}
	Node(int d,Node *ptr)
	{
		data=d;
		next=NULL;
	}
};

class stack{
	
	Node *top;
	
	public:
		
		stack()
		{
			top=NULL;
		}
		
	void pushback(int data)
	{
		Node *n=new Node(data,NULL);
		if(top==NULL)
		{
			top=n;
			return;
		}
		
		n->next=top;
		top=n;
		return;
		
	}
	
	bool empty()
	{
		if(top==NULL)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
	void pop()
	{
		if(empty())
		{
			cout<<"Stack Overflow"<<endl;
		}
		else
		{
			int d=top->data;
			Node *temp=top;
			top=top->next;
			delete temp;
		}
	}
	
	void print()
	{
		Node *temp=top;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
		
		}	
		
	void sort()
	{
		
		Node *temp=top;
		Node *temp2=top->next;
		while(temp->next!=NULL)
		{
			while(temp2!=NULL)
			{
				if(temp->data>temp2->data)
				{
					int a;
					a=temp->data;
					temp->data=temp2->data;
					temp2->data=a;
				}
				temp2=temp2->next;
			}

			temp=temp->next;
			temp2=temp->next;
			
			
		}
		
		}	
	
	
	
};

int main()

{
	stack s;
	s.pushback(1);
	s.pushback(2);
	s.pushback(5);
	
	s.pushback(7);
	s.sort();
	
	s.print();
	
	
}
