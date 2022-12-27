#include<iostream>

using namespace std;

static int all=0;
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
    	all++;
        coeffi=a;
        var=c;
        exp=e;
        next=ptr;
        prev=p;
    }


};

class Doubly{
	
	public:
    Node *head;
    Node *tail;
    int size;
    Doubly()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    Doubly(int n)
    {
        size=n;
    }

    void pushback(int co,char c,int e)
    {
        Node *n=new Node(co,c,e,NULL,NULL);
        
        if(head==NULL)
        {
            head=n;
            tail=n;
            size++;
            return;
        }

        Node *temp=head;
       
        while(temp->next!=NULL)
        {
       
            temp=temp->next;
       
        }
        
        temp->next=n;
        
        n->prev=temp;
        size++;
        
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
   

   
   int getsize()
   {
       return size;
   }
   Node* deleteN(Node *temp)
   {
   	Node *temp2=head;
   	
   	if(temp==NULL)
   	{
   		return temp;
	}   
	
	while(temp2!=temp)
	{
		temp2=temp2->next;
	}
	if(temp2==head)
	{
		head=head->next;
		if(head!=NULL)
		head->prev=NULL;
		//cout<<temp2->exp<<endl;
		delete temp2;
		all--;
		return head;
		
	}
	else if(temp2==tail)
	{
		//cout<<"*";
		tail=tail->prev;
		if(tail!=NULL)
		tail->next=NULL;
		delete temp2;
		all--;
		return tail->next;
	}
	
//   else	if(temp->prev==NULL && temp->next!=NULL)
//   	{//cout<<temp->next->coeffi<<endl;
//   		temp2=temp;
//   		temp=temp->next;
//   		
//   		//cout<<temp->coeffi<<endl;
//   		temp->prev=NULL;
//   		delete temp2;
//   		//temp=temp2;
//   		n.head=temp;
//   		//cout<<n.head->coeffi<<endl;
//   		return;
//	}
//	else if(temp->prev==NULL && temp->next==NULL)
//	{
//		n.head=NULL;
//		n.tail=NULL;
//		delete temp;
//		return;
//	}
//else if(temp->next==NULL)
//	{
//		temp2=temp->prev;
//		temp2->next=NULL;
//		delete temp;
//		temp=temp2;
//		n.tail=temp;
//		return;
//	}
//   	
////   	while(temp2!=temp)
////   	{
////   		temp2=temp2->next;
////	}
//
else	
{
//	
	temp2->prev->next=temp2->next;
	temp2->next->prev=temp2->prev;
	temp=temp->next;
	delete temp2;
	all--;
	return temp;
//	temp=temp2;}
   }}
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
 
Doubly add2(Doubly res,Doubly n,Doubly n2)
    {
        Node *temp=n.head;
       // Doubly *temp3=res;
        Node *temp2=n2.head;
        int count=0;
        
        
        while(temp!=NULL)
        {
            while(temp2!=NULL)
            {//cout<<temp2->exp<<endl;
                if(temp->exp==temp2->exp&& temp->var==temp2->var)
                {
                   res.pushback(temp->coeffi+temp2->coeffi,temp->var,temp->exp);
                   count++;
                   //cout<<temp2->exp<<"*"<<endl;
                   temp2=n2.deleteN(temp2);
                   //cout<<"34"<<"**"<<endl;
                   //n2.print();
//                 cout<<temp2->coeffi<<endl;
                  // continue;
                   //res.print();
				}
				else
                {
                	temp2=temp2->next;	
				}
                
            }
            temp2=n2.head;
        //cout<<"*"<<endl;
          if(count>0)
           {
           	temp=n.deleteN(temp);
           	//cout<<"*"<<endl;
           	//cout<<temp->coeffi<<" *"<<endl;
            	//cout<<temp->coeffi<<endl;
//            //temp3=temp;
//            temp=temp->next;
//            temp2=n2.head;
//            cout<<temp->coeffi<<endl;
//            deleteN(n,temp);
            count=0;
			}
//			if(temp==NULL)
//			{
//				cout<<"*";
//				
//				break;
//			}
			//else
			else
			{
				
				//cout<<"*";
			//cout<<temp->coeffi<<"*"<<endl;
			temp=temp->next;
            //temp2=n2.head;
           // cout<<temp2->coeffi<<endl;
			}
			
            
        }
        temp=n.head;
        temp2=n2.head;
        
        //cout<<all<<endl;
        
        while(1)
        {
        	
        	if(temp!=NULL)
        	{
        		res.pushback(temp->coeffi,temp->var,temp->exp);
        		
        		temp=n.deleteN(temp);
//        		temp=temp->next;
			}
			if(temp2!=NULL)
			{
				res.pushback(temp2->coeffi,temp2->var,temp2->exp);
				temp2=n2.deleteN(temp2);
//				temp2=temp2->next;
			}
			if(temp2==NULL && temp==NULL)
			{
				break;
			}
		}
        //if(temp2!=NULL)
        
        temp=res.head;
        temp2=res.head->next;
        //cout<<temp2->exp<<endl;
        while(temp->next!=NULL)
        {
        	
        	while(temp2!=NULL)
        	{
			
        	if(temp->var==temp2->var&&temp->exp>temp2->exp)
        	{
        		//cout<<temp2->exp<<endl;
        		int ctemp=temp2->coeffi;
        		char vtemp=temp2->var;
        		int etemp=temp2->exp;
        		
				temp2->coeffi=temp->coeffi;
				temp2->var=temp->var;
				temp2->exp=temp->exp;
				temp->coeffi=ctemp;
				temp->var=vtemp;
				temp->exp=etemp;	
        		
        	}
        	else if(temp->var!=temp2->var)
        	{
        		if(temp->var>temp2->var)
        		{
        		int ctemp=temp2->coeffi;
        		char vtemp=temp2->var;
        		int etemp=temp2->exp;
        		
				temp2->coeffi=temp->coeffi;
				temp2->var=temp->var;
				temp2->exp=temp->exp;
				temp->coeffi=ctemp;
				temp->var=vtemp;
				temp->exp=etemp;
        			
				}
			}
        	temp2=temp2->next;
			}
			temp2=temp->next;
			temp=temp->next;
        	
		}
		cout<<res.getsize()<<endl;
        res.print();
        
        //if(temp!=NULL)
//        n.print();
//        if(temp2!=NULL)
//        n2.print();
        
        
        return res;
    }
    
    
int main()
{
//    Doubly d;
    Doubly res;
//    d.pushback(3,'X',3);
//    d.pushback(2,'X',3);
//    d.print();
//    res=add(res,d);
//    res.print();
    int first;
    cin>>first;

   	 Doubly d;
    	int coff;
        char c;
        int e;
    
    for(int i=0;i<first;i++)
    {
        
        cin>>coff;
        cin>>c;
        cin>>e;
        d.pushback(coff,c,e);
    }
	//d.print();
    
	Doubly s;
	int second;
	cin>>second;
	int scoff;
    char sc;
    int se;
	for(int i=0;i<second;i++)
    {
        
        cin>>scoff;
        cin>>sc;
        cin>>se;
        s.pushback(scoff,sc,se);
    }
    //s.print();
    //system("CLS");
	res=add2(res,d,s);
	//system("CLS");
	//res.print();
    
    
    

}
