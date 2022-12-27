#include<iostream>
using namespace std;
#include <sstream>
class Node{
	public:
	string data;
	int length;
	Node *next;
	
	Node(string d,Node *ptr)
	{
		data=d;
		next=ptr;
		length=d.length();
	}
};




class singly{
	public:
	Node *head;
	public:
		
		int len;
		string sen;
		int size;
		
		singly()
		{
			head=NULL;
		}
		
		void push_back(string value)
		{
			Node *n;
			n=new Node(value,NULL);
			
			if(head==NULL)
			{
				head=n;
				len=n->length;
				sen=value;
				size++;
				return;
			}
			
			Node *temp;
			temp=head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
			len=n->length;
			sen=value;
			size++;
			
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
		
	
		
		
		
};
class nodebst
{
	public:
		string word;
		nodebst *left;
		nodebst *right;
		
		singly d;
		
		nodebst()
		{
			
		}
		nodebst(string x)
		{
			word=x;
			left=NULL;
			right=NULL;
		}
};
nodebst *root=NULL;

string *num;

bool checkword(string value,string value2)
{
	for(int i=0;i<value.length();i++)
	{
		if(value[i]>value2[i])
		{
			return true;
		}
		else if(value[i]<value2[i])
		{
			return false;
		}
	}
}
nodebst *insertbst(nodebst *p,string value)
{
	//cout<<"*";
	
	
	if(p==NULL)
	{
	//	cout<<1<<endl;
		return new nodebst(value);
	}
	 if(checkword(p->word,value))
	{
		
		p->left=insertbst(p->left,value);
		//cout<<p->left->word<<endl;
	}
	else //(checkword(value,p->word))
	{
		p->right=insertbst(p->right,value);
	}
	return p;
	
}

void inorder(nodebst *p)
{
	//cout<<p->left->word<<endl;
	
	if(p==NULL)
	{
		return;
	}
	 
	{
		//cout<<"*"<<endl;
		inorder(p->left);
		cout<<p->word<<" ";
		p->d.printList();
		inorder(p->right);
	}
	
}


static int l=0;
bool search(Node *s,nodebst *b)
{
	bool CHECKER=false;
	string number;
	char c;
	stringstream ss;
	int counter=0;
	//cout<<s->data<<endl;
	for(int i=0;i<s->data.length();i++)
	{
		
		
		if(b->word[0]==s->data[i])
		{	counter++;
		 //cout<<i<<endl;
		//cout<<b->word[0]<<" "<<s->data[i]<<endl;
			
		CHECKER=true;
		for(int j=1;j<b->word.length();j++)
		{
			//cout<<s.sen[i+j]<<endl;
			
			if(b->word[j]==s->data[i+j])
			{
				counter++;
				//cout<<s->data[i+j]<<" ";
				
				CHECKER=true;
			}
			else
			{
				CHECKER=false;
				break;
			}
//			if(counter==b->word.length())
//			{
//				
//			
//		cout<<b->word<<" "<<number<<endl;
//		
//				
//				break;
//			}
//			
		}if(CHECKER)
		{
			//cout<<b->word<<endl;
			return true;
		}
		}
	}
	return false;
	
}
void makenumber(Node *s,singly d,nodebst *t)
{
	string number;
	stringstream ss;
	num=new string[d.size];
	for(int k=0;;k++)
			{
			if(s->data[k]==' ')
			{
				break;
			}
			else
			{
				
				number[k]=s->data[k];
				ss << s->data[k];
    			number=ss.str();
				//cout<<number[k];
				
			}
		}
		t->d.push_back(number);
		
		
		
}
void check(nodebst *p,singly s)
{
	
	if(p==NULL)
	{
		return;
	}
	Node *temp=s.head;
	
	for(int i=0;i<s.size;i++)
	{
		
		if(search(temp,p))
		{
			makenumber(temp,s,p);
		
		}
		temp=temp->next;
	}
	check(p->left,s);
	check(p->right,s);
	
	
}

int main()
{
	
	int terms;
	cin>>terms;
	cin.ignore();
	string data;
	for(int i=0;i<terms;i++)
	{
		getline(cin,data);
		if(i==0)
		{
			root=insertbst(root,data);
		}
		else
		{
			insertbst(root,data);
		}
		
		
	}
	int sen_size;
	
	cin>>sen_size;
	cin.ignore();
	singly s;
	for(int i=0;i<sen_size;i++)
	{
		getline(cin,data);
		s.push_back(data);
		
	}
	check(root,s);
	inorder(root);
	
//	root=insertbst(root,"machine learning");
//	insertbst(root,"computer");
//	insertbst(root,"machine");
//	insertbst(root,"learning");
//	insertbst(root,"algorithm");
//	insertbst(root,"supervised");
//	insertbst(root,"data");
//	insertbst(root,"training");
//	insertbst(root,"training example");
////	
////	//inorder(root);
////	
//	singly s;
//	s.push_back("001 machine learning is the science of training computer to act without being explicitly programmed");
//	//cout<<s.sen<<endl;
//	s.push_back("002 neural network is a popular machine learning algorithm");
//	s.push_back("003 neural network perform learning by using supervised data");
//	s.push_back("004 via neural network algorithm computer acts like human brain");
//	s.push_back("005 supervised data mean for each training example output is known");
////	search(s.head,root);
////	//cout<<root->left->word;
//	check(root,s);
////	//makenumber(s.head,s,root);
//	inorder(root);
////	//while()
////	//s.printList();
////	
}
