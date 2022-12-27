#include<iostream>
using namespace std;
#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	Node(int d,Node *ptr)
	{
		data=d;
		next=ptr;
	}
};


class singly{
	
	public:
		Node *head;
		
		singly()
		{
			head=NULL;
		}
		
		void push_back(int value)
		{
			Node *n;
			n=new Node(value,NULL);
			
			if(head==NULL)
			{
				head=n;
				return;
			}
			
			Node *temp;
			temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			
			
		}
		void delete_node(int position)
		{
			int count=1;
			Node *prev=NULL;
			Node *temp=head;
			
			while(count==position)
			{
				count++;
				prev=temp;
				temp=temp->next;
				
			}
			prev->next=temp->next;
			delete temp;
			temp=prev->next;
			
			
		}
		void deletelist()
		{
			Node *temp=head->next;
			Node *prev=head;
			
			//temp=head->next;
			
			while(prev!=NULL)
			{
				delete prev;
				prev=temp;
				temp=temp->next;
			}
		}
		
		singly(const singly &obj)
		{
			head=NULL;
			Node *temp;
			Node *n;
			Node *temp2;
			temp=obj.head;
			
			
			while(temp!=NULL)
			{
				n=new Node(temp->data,NULL);
				if(head==NULL)
				{
					head=n;
					}
				else
				{
					temp2->next=n;
					
					
						}
				temp=temp->next;
				temp2=n;
				
								
			}
		}
		
		void removeduplicate()
		{
			Node *p=head;
			Node  *prev=head;
			Node *q=head->next;
			
			while(p!=NULL)
			{
				
				while(q!=NULL)
				{ 
					
					if(q->data==p->data)
					{
						prev->next=q->next;
						delete q;
						q=prev->next;
					}
					else{
						prev=q;
						q=q->next;
						
					}
				}
				
				if(p->next==NULL)
				{
					break;
				}
				else{
				
				p=p->next;
				q=p->next;
				
				prev=p;}
			}
		}
		
		void printList()
		{
	    	Node* temp = head;
		    while (temp != NULL)
			 {
		        cout << temp->data << " ";
		        temp = temp->next;
		    }
		    cout << "\n";
		}
		
		void reverselist()
		{
			Node *p=head;
			Node *q=NULL;
			Node *r=NULL;
			
			while(p!=NULL)
			{
				r=q;
				q=p;
				p=p->next;
				q->next=r;
			}
			head=q;
		}
		
		bool friend operator==(const singly&obj, singly &obj2)
		{
			int size=0;
			int size2=0;
			Node *temp=obj.head;
			Node *temp2=obj2.head;
			while(temp!=NULL)
			{
				size++;
				temp=temp->next;
				
			}
			temp=obj.head;
			while(temp2!=NULL)
			{
				size2++;
				temp2=temp2->next;
			}
			obj2.reverselist();
			temp2=obj2.head;
			
			if(size==size2)
			{
				while(temp!=NULL)
				{
					if(temp2->data==temp->data)
					{
						temp=temp->next;
						temp2=temp2->next;
					}
					else
					{
						cout<<"False";
						return false;
						
					}
				}
				cout<<"true"<<endl;
				return true;
			}
		}



		
		 
		
		
};
int main()
{
	
}
