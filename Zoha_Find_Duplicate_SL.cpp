#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};
class singly{
	public:
		node *head;
		singly()
		{
			head=NULL;
		}
		void push_front(int d) //insert at front
		{
			node *n=new node(d);
			n->next=head;
			head=n;
		}
		void push_back(int d)  //insert at back
		{
			node *n=new node(d);
			if(head==NULL)
			{
				head=n;
				return;
			}
			node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
		}
		void push_pos(int d,int pos)  //insert at given position
		{
			node *n=new node(d);
			if(head==NULL)
			{
				head=n;
				return;
			}
			node *temp=head;
			int count=1;
			while(temp->next!=NULL)
			{
				if(pos==count)
				{
					n->next=temp->next;
					temp->next=n;
				}
				temp=temp->next;
				count++;
				
			}
		}
		void delete_front() //delete front
		{
			if(head==NULL)
			{
				cout<<"NO LIST PRESENT.";
				return;
			}
			node *temp=head;
			head=head->next;
			delete temp;
		}
//		void delete_last()
//		{
//			if(head==NULL)
//			{
//				cout<<"NO LIST PRESENT.";
//				return;
//			}
//			node *temp=head;
//			while(temp->next!=NULL)
//			{
//				temp=temp->next;
//			}
//			delete temp;
//		}
//    void search(int d)
//    {
//    	if(head==NULL)
//    	{
//    		cout<<"NO LIST PRESENT.";
//    		return;
//		}
//		node *temp=head;
//		int count=1;
//		while(temp->next!=NULL)
//		{
//			if(temp->data==d)
//			{
//				cout<<temp->data<<"PRESENT AT POSITION "<<count;
//			}
//			temp=temp->next;
//			count++;
//		}
//	}
	void search(int d) //this function can search any value.
		{
			node *temp=head;
			int count=1;  // count is used to print position of value
			while(temp->next !=NULL)
			{
				if(temp->data==d)
				{
					cout<<"\nVALUE "<<temp->data<<" IS FOUND!";
					cout<<"   POSITION:"<<count<<endl;
					break;
				}
				temp=temp->next;
				count++;
			}
		}
		void display()
		{
			node *temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		void last_node() //last node
		{
			node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			cout<<" LAST NODE IS:"<<temp->data;
		}
		void middle()  //middle element
		{
			int count=1;
			node *temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
				count++;
			}
			count=count/2;
			node *temp2=head;
			for(int i=0;i<count;i++)
			{
				temp2=temp2->next;
			}
			cout<<"MIDDLE ELEMENT IS:"<<temp2->data;
		}
		void maximum()
		{
			int max=-38764;
			node *temp=head;
			while(temp!=NULL)
			{
				if(temp->data>max)
				{
					max=temp->data;
				}
				temp=temp->next;
			}
			cout<<"\n.MAXIMUM ELEMENT IS:"<<max;
		}
		void minimum()
		{
			int min=69000044;
			node *temp=head;
			while(temp!=NULL)
			{
				if(temp->data<min)
				{
					min=temp->data;
				}
				temp=temp->next;
			}
			cout<<"\nMINIMUM ELEMENT IS:"<<min;
		}
		void duplicates()
		{
			node *temp=head;
			node *temp2=temp->next;
			while(temp->next!=NULL)
			{
				 
			
				while(temp2->next!=NULL)
				{
					if(temp->data==temp2->data)
				{
					
					cout<<"DUPLICATES FOUND."<<endl;
					cout<<"DUPLICATE ELEMENT IS:"<<temp->data;
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
	singly obj;
	obj.push_back(12);
	obj.push_back(22);
	obj.push_back(33);
	obj.push_back(12);
	obj.push_back(44);
	obj.push_back(55);
	obj.display();
//	obj.last_node();
//	cout<<endl;
//	obj.middle();
//	obj.maximum();
//	obj.minimum();
	obj.duplicates();
}
