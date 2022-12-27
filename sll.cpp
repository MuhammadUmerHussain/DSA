#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node *next;
	
	node()
	{
		
	}
	node(int value,node *ptr)
	{
		data=value;
		next=ptr;
	}
};


class singly{
	public:
		node *head;
		
		singly()
		{
			head=NULL;
			
		}
		void pushback(int value)
		{
		//	cout<<"*";
			node *new_node = new node(value,NULL);
			if(head==NULL)
			{
				head=new_node;
			}
			
			
			node *temp;
			temp=head;
			
			while(temp->next!=NULL)
			{
				
				temp=temp->next;
			}
			temp->next=new_node;
		}
		void push_front(int value)
		{
			node *new_node=new node(value,NULL);
			if (head==NULL)
			{
				
				head=new_node;
				return;
			}
			new_node->next=head;
			head=new_node;
		}
		void insert_after(int value,int number)
		{
			node *new_node=new node(value,NULL);
			
			node *temp=head;
			int counter=1;
			while(temp->next!=NULL)
			{
				temp=temp->next;
				counter++;
				if(counter==number)
				{
					cout<<counter<<endl;
					break;
				}
			}
			new_node->next=temp->next;
			temp->next=new_node;
			
//			if(prev->next==NULL)
//			{
//				prev->next=new_node;
//			}
//			new_node->next=prev->next;
//			prev->next=new_node;
		}
		void delete_value(int value)
		{
			node *temp;
			node *prev;
			
			temp=head;
			if(head==NULL)
			{
				cout<<"List is empty";
				return;
			}
			if(temp->data==value)
			{
				head=temp->next;
				delete temp;
				return;
			}
			
			while(temp->data!=value)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
			delete temp;
			return;
		}
		singly(const singly  &obj)
		{
			head=NULL;
			node *temp;
			temp=obj.head;
			node *n;
			node *temp2;
			while(temp!=NULL)
			{
				n=new node(temp->data,NULL);
				if(head==NULL)
				{
					head=n;
				}
				else{
					temp2->next=n;
				}
				temp2=n;
				temp=temp->next;
				
			}
		}
		void print()
		{
			node *temp;
			temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}	
		}
		
};
int main()
{
	node *ptr=new node(6,NULL);
	singly s;
	s.pushback(6);
	s.insert_after(7,2);
	//s.print();
	
}
