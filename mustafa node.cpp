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

void print(node *n){
	
	
	node * temp=n;
	
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
}
}

void insertatStart(node* head, int val)
{
	node* n=new node(val,NULL);
	
	if(head==NULL)
	{
		head=n;
		return;
	}
	
	n->next=head;
	head=n;
	
//	while(temp->next!=NULL)
//	{
//		temp=temp->next;
//	}
	
}

void subs(node* head, int value_for_matching, int v)
{
	node* n=new node(v,NULL);
	node* temp=head;
	
	while(temp!=NULL)//by the way you can alsoput  if condition here
	{
		if(temp->data==value_for_matching)
		{
			n->next=temp->next;
			temp->next=n;
		}
		
		temp=temp->next;
//		cout<<temp->data;
	
	}
	
	
		
}

int main(){
	node *head= new node(5,NULL);
	node *second= new node(6,NULL);
	node *third = new node(9,NULL);
	
//	head -> data = 1;
	head -> next = second;
//	second -> data = 2;
	second -> next = third;
//	third -> data= 3; 
	third -> next = NULL;
	
	subs(head, 5,23);
	print(head);
	
	
//	insertatStart(head, 7);
	


	
	
}


