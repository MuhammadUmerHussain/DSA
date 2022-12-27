#include<iostream>

using namespace std;

class publication{
	
	string title;
	float price;
	
	public:
	publication()
	{
		
	}
	publication(string x,float a):title(x),price(a)
	{
		
	}
	
	void setPrice(float a)
	{
		price=a;
	}
	void setTitle(string x)
	{
			title=x;
	}
	
	string getTitle()
	{
		return title;
	}
	float getPrice()
	{
		return price;
	}
	
	void getData()
	{
		cout<<"Enter Title:"<<endl;
		cin>>title;
		cout<<"Enter Price:"<<endl;
		cin>>price;
		
		
	}
	void putData()
	{
		cout<<"Price: "<<getPrice()<<endl;
		cout<<"Title: "<<getTitle()<<endl;
		
	}
};

class Book:protected publication
{
	
	int page_count;
	
	public:
	
	Book()
	{
		
	}
	
	Book(string x,float a,int z):publication(x,a),page_count(z)
	{
		
	}
	
	void setPageCounter(int x)
	{
		page_count=x;
		
		}	
	int getPageCounter()
	{
		return page_count;
		}
	void getData()
	{
		publication::getData();
		cout<<"Enter Page Counter:"<<endl;
		cin>>page_count;
		
		//system("cls");
	}
	void putData()
	{
		publication::putData();
		cout<<"Page Count: "<<getPageCounter();
	}
		
			
 };
 
class tape:protected publication
{
	float play_time;
	
	public:
		tape()
		{
			play_time=0;
			
		}
		tape(string x,float y,float z):publication(x,y),play_time(z)
		{
			
		}
		void setPlayTime(float x)
		{
			play_time=x;
		}
		float getPlayTime()
		{
			return play_time;
	}		
	void getData()
	{
		publication::getData();
		cout<<"Enter Play Time:"<<endl;
		cin>>play_time;
		
		//system("cls");
	}
	void putData()
	{
		publication::putData();
		cout<<"Play Time: "<<getPlayTime()<<endl;
	}
		
  };  

int main()
{
	tape obj;
	obj.getData();
	obj.putData();
	Book obj2;
	obj2.getData();
	obj2.putData();
	
	
	
}
