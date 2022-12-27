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
			node *n;
			n=new node(value,NULL);
			
			if(head==NULL)
			{
				head=n;
				return;
			}
			
			node *temp;
			temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			
			
		}
		void sum_of_list()
		{
			int sum=0;
			if(head==NULL)
			{
				cout<<"0"<<endl;
				return;
			}
			node *temp=head;
			
			while(temp!=NULL)
			{
				sum=sum+temp->data;
				temp=temp->next;
			}
			cout<<"The Sum is : "<<sum<<endl;
			
		}
		void input()
		{
			
			int a;
			int n;
			cout<<"Enter number of Elements: "<<endl;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"elements "<<i+1<<" : "<<endl;
				cin>>a;
				pushback(a);
				
			}
			
		}
		
};
int main()
{
	singly s;
//	s.input();
	s.pushback(6);
	s.pushback(7);
	s.pushback(8);
	s.sum_of_list();
	
}
