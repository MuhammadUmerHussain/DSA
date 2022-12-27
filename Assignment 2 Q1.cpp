#include<iostream>

using namespace std;

class Node{
    public:
    int coeffi;
    char var;
    int exp;
    Node *next;
    Node *prev;
    Node()
    {
        coeffi=0;
        exp=0;

    }
    Node(int a,char c,int e,Node *ptr,Node *p)
    {
        coeffi=a;
        var=c;
        exp=e;
        next=ptr;
        prev=p;
    }


};

class Doubly{

    Node *head;
    Node *tail;
    public:
    Doubly()
    {
        head=NULL;
        tail=NULL;
    }

    void pushback(int co,char c,int e)
    {
        Node *n=new Node(co,c,e,NULL,NULL);
        
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
    void print()
    {
        Node *temp=head;

        while(temp!=NULL)
        {
            cout<<temp->coeffi<<" "<<temp->var<<" "<<temp->exp<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    Doubly d;
    d.pushback(3,'X',3);
    d.pushback(2,'Y',4);

}