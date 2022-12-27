#include<iostream>

using namespace std;


class Node{
	
    public:
    int data;
	Node *next;
	Node *prev;
	
	Node()
	{
		data=0;
		next=NULL;
		prev=NULL;
	}
    Node(int x,Node *ptr1 ,Node *ptr2)
    {
        data=x;
        next=ptr1;
        prev=ptr2;
     }
	
};

class Doubly
{
public:
Node *head;
Node *tail;
int size;

Doubly()
{
    head=NULL;
    tail=NULL;
}

void print()
{
    Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        cout<<endl;
    }
}
void insertend(int data)
{
    Node *n=new Node(data,NULL,NULL);

    if(head==NULL)
    {
        head=n;
        tail=n;
        return;
    }

    n->prev=tail;
    tail->next=n;
    tail=n;
    size++;


}

void insertbeg(int data)
{
    Node *newnode=new Node(data,NULL,NULL);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    size++;


}

void insertpos(int pos,int data)
{
    Node *n=new Node(data,NULL,NULL);
    
    if(head==NULL)
    {
        cout<<"Undefined Reference To Position"<<endl;
        return;

    }
    Node *temp=head;
    int count=0;
    while(count!=pos)
    {
        temp=temp->next;
        count++;
        if(temp==NULL)
        {
        cout<<"Undefined Reference To Position"<<endl;
        return;

        }
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    size++;

    


}
void deletenode(int post)
{
    Node *temp=head;
    int count=1;
    
    if(post==1)
    {
        head=temp->next;
        temp->prev=NULL;
        delete temp;
        return;
    }
    while(count!=post)
    {
        temp=temp->next;
        count++;
        if(temp==NULL)
        {
        cout<<"Undefined Reference To Position"<<endl;
        return;

        }
    }
    cout<<count<<" "<<post<<endl;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    delete temp;
}
 
};





int main()
{
    Doubly n;
    n.insertbeg(6);
    n.insertbeg(5);
    n.insertpos(0,2);
    n.deletenode(1);
    n.print();
    
    Doubly t;
    t.insertend(4);
    t.insertend(4);
    t.insertend(4);
	
	
    	
}
