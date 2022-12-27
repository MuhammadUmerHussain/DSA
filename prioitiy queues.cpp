  #include<iostream>
  using namespace std;
  #define SIZE 5
  class queue{
  	
  	public:
  	int arr[SIZE];
  	int size;
  	int pri[SIZE];
  	int front;
  	int rear;
  	queue()
  	{
  		front=rear=-1;
  		size=0;
	}
	
	bool empty()
	{
		if(front==-1 && rear==-1)
		{
			return true;
		}
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool full()
	{
		if(rear==SIZE-1)
		{
			return true;
			
			
		}
		else 
		{
			return false;
		}
	}
	int enqueue(int d,int p)
	{
		if(empty())
		{
			front=rear=0;
			arr[rear]=d;
			pri[rear]=p;
			size++;

		}
		
		else
		{
			int i;
			for(i=rear;i>=front;i--)
			{
				if(p>pri[i])
				{
					arr[i+1]=arr[i];
					pri[i+1]=pri[i];
					
				}
				else
				{
					break;
				}
			}
			arr[i+1]=d;
			pri[i+1]=p;
			rear++;
			size++;
			
		
		}
		return true;
	}
	int dequeue()
	{
		if(empty())
		{
			cout<<"error!";
			exit(1);
		}
		if(front==rear)
		{
			int d=arr[front];
			front=rear=-1;
			return d;
			
		}
		else
		{
			int d=arr[front];
			front++;
			return d;
			
		}
		
	}
	void print()
	{
		cout << "\ndisplaying queue elements:" << endl;
		for (int a = front; a <= rear; a++)
			cout << arr[a] << " " << pri[a] << endl;
	}
  	
  };
  
  int main()
  {
  	queue q;
  	q.enqueue(5,6);
  	q.enqueue(7,7);
  	q.print();
  	
  }
