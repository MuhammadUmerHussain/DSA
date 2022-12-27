#include<iostream>
#include<bits/stdc++.h>

using namespace std;
char tolow(string s)
{
    if (s[0] >= 'A' && s[0] <= 'Z') 
        return (char)(s[0] + 32); 
    else
        return s[0];
}

class Node{
	
    public:
    string data;
	Node *next;
	Node *prev;
	
	Node()
	{
		data="";
		next=NULL;
		prev=NULL;
	}
    Node(string x,Node *ptr1 ,Node *ptr2)
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
void pushback(string data)
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

void insertbeg(string data)
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

void insertpos(int pos,string data)
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



Node * deleten(Node *temp)
{
	if(temp==NULL)
	{
		return NULL;
	}
	else if(temp==head)
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
		temp=head;
		return temp;
	}
	else if(temp==tail)
	{
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete temp;
		temp=tail;
		return temp;
	}
	else
	{
		Node *temp2=temp->next;
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
		return temp2;
	}
}

void checkdouble()
{
	Node *temp=head;
	Node *temp2=head->next;
	int countt=2;
	int count=1;
	
	while(temp->next!=NULL)
	{
		while(temp2!=NULL)
		{
			if(temp->data==temp2->data)
			{

				temp2=deleten(temp2);
			
			
			
				
			}
			else
		{
		
			temp2=temp2->next;
			countt++;}

			
		}
		temp=temp->next;
		temp2=temp->next;
		
	}
}
void sorting()
{
	Node *temp=head;
	Node *temp2=head;
	while(temp->next!=NULL)
	{
		
		
		while(temp2!=NULL)
		{
			
			if(temp->data[0]>=65 && temp->data[0]<=92 || temp2->data[0]>=65 && temp2->data[0]<=92)
			{
				
//				string change;
				if(temp->data[0]>=65 && temp->data[0]<=92 )
				{
					if(tolow(temp->data)>tolow(temp2->data))
					{
						string temp3=temp->data;
						temp->data=temp2->data;
						temp2->data=temp3;
					}
//					change=temp->data[0]+32;
				}
				else if(temp2->data[0]>=65 && temp2->data[0]<=92)
				{
					if(tolow(temp->data)>tolow(temp2->data))
					{
						string temp3=temp->data;
						temp->data=temp2->data;
						temp2->data=temp3;
					}
//					change=temp2[0]+32;
				}
//				if(change)
//			}
			//cout<<"***"<<temp->data<<" "<<temp2->data<<endl;
//			if(temp->data.length()>temp2->data.length())
//			{
//				//cout<<"***"<<temp->data<<" "<<temp2->data<<endl;
//				string temp3=temp->data;
//				temp->data=temp2->data;
//				temp2->data=temp3;
//				//cout<<"***"<<temp->data<<" "<<temp2->data<<endl;				
			}
			else if(temp->data>temp2->data)
			{
//				cout<<"-----------------------------------"<<endl;
//				cout<<"***"<<temp->data<<" "<<temp2->data<<endl;
				string temp3=temp->data;
				temp->data=temp2->data;
				temp2->data=temp3;
				
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
	
	Doubly d;
	string input;
	string break_word;
	getline(cin,input);
	
	istringstream ss(input);
	
	while(ss>>break_word)
	{
		d.pushback(break_word);
	}
	d.checkdouble();
//	d.print();
	d.sorting();
	
	d.print();
	
	
	
    	
}
