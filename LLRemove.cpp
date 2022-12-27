#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		string str;
		int p;
		Node* next;

		Node(string n)
		{
			str = n;
			p = 0;
			next = NULL;
		}
};

class list
{
public:

	Node* head;

	list()
	{
		head = NULL;
	}

	void pushback(string str)
	{
		Node* temp = head;
		Node* n = new Node(str);

		if (head == NULL)
		{
			n->p++;
			head = n;
			head->next = NULL;
			return;
		}
	
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		n->p = temp->p;
		n->p++;
		temp->next = n;
		n->next = NULL;
	}
	

	void sort()
	{
		Node* temp = head;
		
		while(temp != NULL) {
			Node* curr = temp->next;
			while (curr != NULL) {
				if (temp->str[4] > curr->str[4]) {
					string t = temp->str;
					temp->str = curr->str;
					curr->str = t;
				}
				curr = curr->next;
			}
			temp = temp->next;
		}
	}

	void removeDup()
	{
		Node* curr = head;
		
		while (curr->next != NULL)
		{
			if(curr->str[0] < curr->next->str[0] && (curr->str[2] == curr->next->str[2]) && (curr->str[4] == curr->next->str[4]))
			{
				string t = curr->str;
				curr->str = curr->next->str;
				curr->next->str = t;
			}
			curr = curr->next;
		}
		
		curr = head;
		
		while (curr->next!= NULL)
		{
			if ((curr->str[2] == curr->next->str[2]) && (curr->str[4] == curr->next->str[4]))
			{
				curr->next = curr->next->next;
			}
			else
			{
				curr = curr->next;
			}
		}
	}

	void output()
	{
		Node* temp = head;
		int i = 0;
				
		while(temp != NULL)
		{
			i++;
			temp=temp->next;
		}
		
		cout << i << endl;
		temp = head;
		
		while (temp != NULL)
		{
			cout << temp->str << endl;
			temp = temp->next;
		}
	}
};

void addition(list l1, list l2, list l3)
{
	Node* temp1 = l1.head;
	Node* temp2 = l2.head;
	
	int sum;
	char c;
	
	while (temp1 != NULL){
		if(temp1->p!=0){
			while (temp2 != NULL){
				if ((temp1->str[2] == temp2->str[2])&& (temp1->str[4] == temp2->str[4])){
					sum = (temp1->str[0] - '0') + (temp2->str[0] - '0');
					c = sum + '0';
					temp1->str[0] = c;
					l3.pushback(temp1->str);
					temp1->p=0;
					temp2->p=0;
				}
				else if(temp2->p!=0){
					l3.pushback(temp2->str);
					temp2->p=0;
				}
				temp2 = temp2->next;
			}	
			temp2 = l2.head;
			l3.pushback(temp1->str);
			temp1->p=0;
		}
		temp1=temp1->next;
	}
	l3.sort();
	l3.removeDup();
}

int main()
{
	list l1, l2;
	
	string str;
	int terms1, terms2;
	
	cin >> terms1;
	for(int i = 0; i < terms1; i++){
		getline(cin, str);
		l1.pushback(str);
	}

	cin >> terms2;
	for (int i = 0; i < terms2; i++){
		getline(cin, str);
		l2.pushback(str);
	}

	list l3;
	addition(l1, l2, l3);

	l3.output();
	
}
