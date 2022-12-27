#include<iostream>
using namespace std;


class Node
{
	public: 
		int data;
		Node* next;
		
		Node () 
		{
			data = 0;
			next = NULL;
		}
		Node (int d, Node* n)
		{
			data = d;
			next = n;
		}
};

class circularlink{
    public:
    Node *head;
    int size;
    circularlink()
    {
        head=NULL;
        size=0;
    }
    void print()
{
    Node *temp;
    temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    cout<<temp->data;
    cout<<endl;
}

    int const getsize()
    {
        return size;
    }

    void pushback(int data)
    {
        Node *ptr=new Node(data,NULL);

        if(head==NULL)
        {
            head=ptr;
            ptr->next=ptr;
            size++;
            return;
        }

        Node *temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        temp->next=ptr;
        size++;


    }
    void pushf(int data)
    {
        Node *ptr=new Node(data,NULL);

        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
            size++;
            return;
        }

        ptr->next=head;
        Node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;

        }
        temp->next=ptr;
        head=ptr;
        size++;

    }

    void insertpos(int post,int data)
    {
        Node *ptr=new Node(data,NULL);

        if(head==NULL)
        {
            cout<<"Error";
            return;
        }
        Node *temp=head;
        int count=1;
        while(temp->next!=head)
        {cout<<post<<" "<<count<<endl;
            if(count==post)
            {
                ptr->next=temp->next;
                temp->next=ptr;
                size++;
                return;
            }
            count++;
            temp=temp->next;
            
        }
        cout<<"Postion is not right"<<endl;
        return;


    }

    void deletenode(int post)
    {
        Node *temp=head;
        int count=1;
        if(head==NULL)
        {
            cout<<"Error";
            exit(1);

        }
        while(temp->next!=head)
        {   
            if(count==post)
            {
                delete temp;
                return;
            }
            temp=temp->next;

        }
        cout<<"error";
        return;
    }

};
int main()
{
    circularlink c;
    c.pushback(6);
    c.pushback(7);
    c.pushf(0);
    c.insertpos(2,10);
    //cout<<c.head->data<<endl;
    //cout<<c.head->next->next->next->data<<endl;
    c.print();
    //<<c.getsize()<<endl;

}