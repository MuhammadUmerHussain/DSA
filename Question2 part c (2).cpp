#include<iostream>

using namespace std;

class sales{
	float sale[3];
	
	public:
		sales()
		{
			sale[0]=0;
			sale[1]=0;
			sale[2]=0;
		}
		sales(float x,float y,float z)
		{
			sale[0]=x;
			sale[1]=y;
			sale[2]=z;
			
		}
		float getSales()
		{
			return *(sale);
		}
		void setSales(float i,float j,float k)
		{
			sale[0]=i;
			sale[1]=j;
			sale[2]=k;
		}
		void getData()
		{
			int i;
			for(i=0;i<3;i++)
			{
			cout<<"Enter Sales Of "<<i<< " month: "<<endl;
			cin>>sale[i];	
		}}
		void putData()
		{
			for(int i=0;i<3;i++)
			{
				cout<<"Sale of Book"<<i<<" is:"<<*(sale+i)<<endl;
			}
		}
		
		
};

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

class Book:protected publication,protected sales
{
	
	int page_count;
	
	public:
	
	Book()
	{
		
	}
	
	Book(string x,float a,int z,float w,float e,float q):publication(x,a),page_count(z)
	{
		sales::setSales(w,e,q);
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
		sales::getData();
		//system("cls");
	}
	void putData()
	{
		
		publication::putData();
		cout<<"Page Count: "<<getPageCounter();
		sales::putData();
	}
		
			
 };
 
class tape:protected publication,protected sales
{
	float play_time;
	
	public:
		tape()
		{
			play_time=0;
			
		}
		tape(string x,float y,float z,float a,float w,float q,float e):publication(x,y),play_time(z)
		{
			sales::setSales(w,q,e);
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
		sales::getData();
		
		//system("cls");
	}
	void putData()
	{
		publication::putData();
		cout<<"Play Time: "<<getPlayTime()<<endl;
		sales::putData();
	}
		
  };  
  
  class disk:protected publication,protected sales
  {
  	bool Cd;
  	bool dVd;
  	string type;
  	public:
  		disk()
  		{
  			Cd=false;
		  	dVd=false;
		  }
		  disk(string x,float a,string f,float w,float q,float e):publication(x,a),type(f)
		  {
		  	sales::setSales(w,q,e);
		  	Cd=false;
		  	dVd=false;
		  	if(type=="Cd"|| type=="CD" || type=="cd")
		  	{
		  		Cd=true;
			  }
			else if(type=="DVD"|| type=="dvd" || type=="Dvd")
			{
				dVd=true;
			  }
			else 
			{
				cout<<"Your Disk Type Is Invalid Try To Input New Disk!"<<endl;
				throw(type);
				}    
		  }
		  getData()
		  {
		  	publication::getData();
		  	sales::getData();
		  	cout<<"Enter Your Disk Type:"<<endl;
		  	cin>>type;
		  	
			if(type=="Cd"|| type=="CD" || type=="cd")
		  	{
		  		Cd=true;
			  }
			  
			else if(type=="DVD"|| type=="dvd" || type=="Dvd")
			{
				dVd=true;
			  }
			  
			else 
			{
				cout<<"Your Disk Type Is Invalid Try To Input New Disk!"<<endl;
				throw(type);
				}    
		  }
		  void putData()
		  {
		  	publication::putData();
		  	sales::putData();
		  	cout<<"Type Is "<<type<<endl;
		  }
		  
		  
  	
  };

int main()
{
//	tape obj;
//	obj.getData();
//	obj.putData();
//	Book obj2;
//	obj2.getData();
//	obj2.putData();
//	
	disk CDD("World Full Of Terror",155.5,"Cd",200202.2,21012.21,421212.1);
	CDD.putData();
	
	
}
