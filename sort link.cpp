#include<iostream>
using  namespace std;

class Node{
public:
int data;
Node *next;
Node *prev;

Node()
{

}

Node(int x,Node *ptr,Node *ptr2)
{
    data=x;
    next=ptr;
    prev=ptr2;
}



};

class Stack{
   
    public:
    Node *head;
    Node *tail;
    

    Stack()
    {

    }

    void pushback(int x)
    {
        Node *n=new Node(x,NULL,NULL);
        if(head==NULL)
        {
            head=n;
            tail=n;
            return;

        }
        

        Node *temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
        tail=n;
        

    }

void reverse()
{
    Node *temp;
    Node *temp1;
    Node *temp3;
    temp=head;

    while(temp!=NULL)
    {
        temp3=temp1;
        temp1=temp;
        temp=temp->next;
        temp1->next=temp3;
        temp1->prev=temp;
    }
    tail=head;
    head=temp1;

}
void sort()
{
    Node *temp=head->next;
    Node *temp2=head;

    while(temp2->next!=NULL)
    {
    	
        while(temp!=NULL){
        if(temp->data<temp2->data)
        {
            int temp3;
            temp3=temp->data;
            temp->data=temp2->data;
            temp2->data=temp3;
        }
        temp=temp->next;
        }
        temp2=temp2->next;
        temp=temp2->next;
        

    }
}
void print()
{
    Node *temp=head;
    Node *temp2=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<" "<<endl;
        //cout<<temp2->data<<" "<<endl;
        temp=temp->next;
        //temp2=temp2->prev;
    }
    cout<<endl;
}

};


int main()
{
Stack s;
cout << "*";
s.pushback(6);
cout << "*";
s.pushback(7);
s.pushback(9);
s.sort(); 
s.print();
}
