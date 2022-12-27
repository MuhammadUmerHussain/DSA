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
   friend Doubly add(Doubly res,Doubly n);
   void operator=( const Doubly res)
   {
       
       Node *temp=res.head;
       while(temp!=NULL)
       {
           pushback(temp->coeffi,temp->var,temp->exp);
           temp=temp->next;
       }
   }
};
  Doubly add(Doubly res,Doubly n)
    {
        Node *temp=n.head;
        Node *temp2=n.head->next;
        
        
        while(temp->next!=NULL)
        {
            while(temp2!=NULL)
            {
                if(temp->exp==temp2->exp&& temp->var==temp2->var)
                {
                   res.pushback(temp->coeffi+temp2->coeffi,temp->var,temp->exp);
                   //res.print();

                   
                }
                temp2=temp2->next;
            }
            temp=temp->next;
            temp2=temp->next;
        }
        return res;
    }

int main()
{
    Doubly d;
    Doubly res;
    d.pushback(3,'X',3);
    d.pushback(2,'X',3);
    d.print();
    res=add(res,d);
    res.print();
    
    

}