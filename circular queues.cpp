#include<iostream>
using namespace std;
#define MAX 5

class circular{
	int arr[MAX];
	int front;
	int rear;
	int count;
	
	
	public:
		circular()
		{
			front=rear=-1;
			count=0;
		}
		
	bool isempty()
	{
		if(front==-1 && rear==-1)
		{
			return true;
		}
		return false;
		}
	bool isfull()
	{
		if(rear+1%MAX==front)
		{
			return true;
		}
		return false;
			}
	
	bool enque(int d)
	{
	if(isfull())
	{
		return false;
	}
	if(isempty())
	{
		front=rear=0;
		arr[rear]=d;
	}
	else 
	{
		rear=(rear+1)%MAX;
		arr[rear]=d;
		
	}
	count++;
	return true;
					}
	int deque()
	{
		if(isempty())
		{
			return false;
		}
		if(front==rear)
		{
			int d=arr[front];
			front=rear=-1;
			count--;
			return d;
		}
		else 
		{
			int d=arr[front];
			arr[front]=INT_MIN;
			front=(front+1)%MAX;
			count--;
			return d;
		}
		
	}	
	
	void display()
	{
		if(isempty())
		{
			return;
		}
		else
		{
			int c=0;
			int i=front;
			while(c<count)
			{
				cout<<arr[i]<<" ";
				i=(i+1)%MAX;
				c++;
				
				
			}
			cout<<endl;
		}
	}
								
		
	
	
};
int main()
{
	circular c;
	c.enque(5);
	c.enque(6);
	c.display();
}
