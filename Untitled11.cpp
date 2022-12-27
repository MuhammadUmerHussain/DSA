#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    int data;
    node* next;
}*head; 

void createList(int n) 
{
	if(n>0)
	{
		
	
    struct node* frontNode, * temp;
    int num, i;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        cout << " Memory can not be allocated";
    }
    else
    {
        cout << "Enter the data for node 1: ";
        cin >> num;
        head->data = num;
        head->next = NULL; 
        temp = head;

        for (i = 2; i <= n; i++)
        {
            frontNode = (struct node*)malloc(sizeof(struct node));


            if (frontNode == NULL) 
            {
                cout << " Memory can not be allocated";
                break;
            }
            else
            {
                cout << "Enter the data for node " << i << ": "; 
                cin >> num;
                frontNode->data = num;
                frontNode->next = NULL;
                temp->next = frontNode;
                temp = temp->next;
            }
        }
    }}
    else
    {
    	cout<<"list is empty!"<<endl;
	}
}

void display() 
{
    struct node* temp;
    if (head == NULL)
    {
        cout << " No data found in the list";
    }
    else
    {
        temp = head;
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << "\t" << temp->data;
            temp = temp->next;
        }
    }
}

int main()
{
    int n, num;
    
    cout << "Enter the number of nodes: \n";
    cin >> n;
    createList(n);
    cout << "\nLinked list data: \n";
    display();

    return 0;
}
