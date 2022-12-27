#include <iostream>
#include <string>
using namespace std;

class Node
{
public:

	string number;
	Node* next;
	int key;
	
	
	Node(string d)
	{
		number = d;
		next = NULL;
		key=0;
	}
};

class LinkedList
{
public:

	Node* head;

	LinkedList()
	{
		head = NULL;
	}

	void push_last(string data)
	{
		Node* node = new Node(data);

		if (head == NULL)
		{
			head = node;
			head->next = NULL;
			node->key++;
		}

		else
		{
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			node->key = temp->key;
			node->key++;
			temp->next = node;
			node->next = NULL;
		}
	}

	void sort()
	{
		static Node* temp = head;
		if (temp != NULL) {
			Node* j = temp->next;
			while (j != NULL) {
				if (temp->number[4] > j->number[4]) {
					swap(temp->number,j->number);
				}
				j = j->next;
			}
			temp = temp->next;
			sort();
		}
	}

	void remove_dup()
	{
		Node* current = head;
		Node* next_next;
		Node* save;
		while (current->next!= NULL)
		{
			if(current->number[0] < current->next->number[0] && (current->number[2] == current->next->number[2]) && (current->number[4] == current->next->number[4]))
			{
				swap(current->number,current->next->number);
			}
			current = current->next;
		}
		current = head;
		while (current->next!= NULL)
		{
			if ((current->number[2] == current->next->number[2]) && (current->number[4] == current->next->number[4]))
			{
				next_next = current->next->next;
				delete(current->next);
				current->next = next_next;
//				
//				next_next=current;
//				while((current->number[2] == current->next->number[2]) && (current->number[4] == current->next->number[4]))
//				{
//					current = current->next;
//				}
//				save=current->next;
//				current=next_next;
//				current->next=save;
			}
			else
			{
				current = current->next;
			}
		}
	}

	void display()
	{
		Node* temp = head;
		int count =0;
				
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		cout << count << endl;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->number << endl;
			temp = temp->next;
		}
	}
};

void process(LinkedList obj1, LinkedList obj2, LinkedList obj3)
{
	Node* temp1 = obj1.head;
	Node* temp2 = obj2.head;
	int add;
	char ad;
	//Needed info in index 0(coefficient), 2(variable), 4(exponent)
	while (temp1 != NULL)
	{
		if(temp1->key!=0)
		{
			while (temp2 != NULL)
		{
//			cout << temp2->key << " ";
					if ((temp1->number[2] == temp2->number[2])&& (temp1->number[4] == temp2->number[4]))
				{
					add = (temp1->number[0] - '0') + (temp2->number[0] - '0');
					ad = add + '0';
					temp1->number[0] = ad;
					obj3.push_last(temp1->number);
					temp1->key=0;
					temp2->key=0;
				}
					else if(temp2->key!=0)
				{
					obj3.push_last(temp2->number);
					temp2->key=0;
				}
			temp2 = temp2->next;
		}
		temp2 = obj2.head;
		obj3.push_last(temp1->number);
		temp1->key=0;
		}
		temp1=temp1->next;
	}

	obj3.sort();
	obj3.remove_dup();
	obj3.display();
}

int main()
{
	LinkedList first, second, third;
	int first_poly, second_poly;
	string number;
	cin >> first_poly;

	cin.ignore();
	for (int i = 0; i < first_poly; i++)
	{
		getline(cin, number);
		first.push_last(number);
	}

	cin >> second_poly;

	cin.ignore();
	for (int i = 0; i < second_poly; i++)
	{
		getline(cin, number);
		second.push_last(number);
	}
	cout << endl;
	
	process(first, second, third);
}
