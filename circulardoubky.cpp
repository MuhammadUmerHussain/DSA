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
    while(temp->next!=head)
    {
        cout<<temp->data;
        temp=temp->next;
        cout<<endl;
    }
    cout<<temp->data<<endl;
}
void insertend(int data)
{
    Node *n=new Node(data,NULL,NULL);

    if(head==NULL)
    {
        head=n;
        n->next=n;
        n->prev=n;
        tail=n;
        return;
    }

    n->prev=tail;
    tail->next=n;
    tail=n;
    n->next=head;
    size++;


}

void insertbeg(int data)
{
    Node *newnode=new Node(data,NULL,NULL);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
        tail=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    tail->next=newnode;
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
    Node *temp=head->next;
    int count=1;
    
    
    while(count!=pos)
    {

        
        if(temp!=head)
        {temp=temp->next;
        count++;
        if(temp==NULL)
        {
        cout<<"Undefined Reference To Position"<<endl;
        return;

        }
        //if(temp==tail)
        {
           // cout<<"error"<<endl;
            //return;
        }

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
    n.insertpos(2,0);

    n.print();

    	
}