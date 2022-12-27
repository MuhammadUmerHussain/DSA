#include<iostream>

using namespace std;

 struct data{
		string name;
		string add;
		string city;
		string state;
		int zip;
		
	};
	
class package
{
	
	 struct data  sender,reciever;
	 float weit;
	 float cost;
	 
	 public:
	 	void printname()
	 	{
	 		cout<<sender.name<<endl;
		 }
		 
	 	package()
	 	{
	 		
		 }
		package(struct data  x,struct data  y,float z,float a)
		{
			if(z>0 && a>0)
			{
			 weit=z;
			 cost=a;
			}
			sender=x;
			reciever=y;
		}
		void setCost(float x)
		{
			cost=x;
		}
		void setDataSender(string x,string y,string z,string a,int o)
		{
			sender.name=x;
			sender.city=y;
			sender.add=z;
			sender.state=a;
			sender.zip=o;
		}
		
		void setDataReciver();
		
		struct data getSender()
		{
			
			return sender;
		}
		friend void cal();
		struct data  getReciever()
		{
			return reciever;
		}
		float getweit()
		{
			return weit;
		}
		float getcost()
		{
			return cost;
		}
		
		double calculatecost()
		{
			return (weit*cost);
		}
		void input()
		{
			
			cout<<"Enter Name Of Sender:"<<endl;
			cin>>sender.name;
			cout<<"Enter City Of Sender"<<endl;
			cin>>sender.city;
			cout<<"Enter Address Of Sender:"<<endl;
			cin>>sender.add;
			cout<<"Enter State Of Sender:"<<endl;
			cin>>sender.state;
			cout<<"Enter Zipcode Of Sender:"<<endl;
			cin>>sender.zip;
			
			cout<<"Enter Name Of Reciever:"<<endl;
			cin>>reciever.name;
			cout<<"Enter City Of Reciever"<<endl;
			cin>>reciever.city;
			cout<<"Enter Address Of Reciever:"<<endl;
			cin>>reciever.add;
			cout<<"Enter State Of Reciever:"<<endl;
			cin>>reciever.state;
			cout<<"Enter Zipcode Of Reciever:"<<endl;
			cin>>reciever.zip;
			
			cout<<"Enter Weight Of Product:"<<endl;
			cin>>weit;
			cout<<"Enter Cost Of Product:"<<endl;
			cin>>cost;
			
		}
		void Display()
		{
			cout<<"Name Of Sender:"<<sender.name<<endl;
			cout<<"City Of Sender:"<<sender.city<<endl;
			cout<<"Address Of Sender:"<<sender.add<<endl;
			cout<<"State Of Sender:"<<sender.state<<endl;
			cout<<"Zipcode Of Sender:"<<sender.zip<<endl;
			
			
			cout<<"Weight Of Product"<<weit<<endl;
			cout<<"Cost Of Product"<<cost<<endl;
			
			cout<<"Name Of Reciever:"<<reciever.name<<endl;
			cout<<"City Of Receiver:"<<reciever.city<<endl;
			cout<<"Address Of Receiver:"<<reciever.add<<endl;
			cout<<"State Of Receiver:"<<reciever.state<<endl;
			cout<<"Zipcode Of Receiver:"<<reciever.zip<<endl;
			
			
		}
		
	
};

class TwoDayPackage:protected package
{
	float flatfee;
	
	public:
		TwoDayPackage()
		{
			
		}
		TwoDayPackage(struct data  x,struct data  y,float z,float a,float flat):package(x,y,z,a)
		{
			if(flat>0)
			{
				flatfee=flat;
			}
		}
		void setflatfee(float flat)
		{
				if(flat>0)
			{
				flatfee=flat;
			}
		}
		double calculatecost()
		{
			return (package::calculatecost()+flatfee);
		}
		print()
		{
			printname();
		}
		void input()
		{
			package::input();
			cout<<"Enter Flat Fee:"<<endl;
			cin>>flatfee;
			system("cls");
		}
		void Display()
		{
			package::Display();
			cout<<"Flat Fee:"<<flatfee<<endl;
			cout<<"Total: "<<calculatecost();
		}
		
		bool operator >( TwoDayPackage &obj)
		{
			if(calculatecost()>obj.calculatecost())
			{
				return true;
			}
			else
			return false;
			
		}
		
};


class OverNight:protected package
{
	float additionalFee;
	
	public:
	
	OverNight()
	{
	}
	OverNight(struct data x,struct data y,float z,float a,float fee):package(x,y,z,a)
	{
		additionalFee=fee;
	}
	
	void setadditionalfee(float fee)
	{
		additionalFee=fee;
	}
	float getadditionalfee()
	{
		return additionalFee;
	}
	double calculatecost()
	{
		return((getcost()+additionalFee)*getweit());
		
		}
	void input()
		{
			package::input();
			cout<<"Enter Addtitional Fee:"<<endl;
			cin>>additionalFee;
			system("cls");
		}	
	void Display()
	{
		package::Display();
		cout<<"Additional fee:"<<endl;
		cout<<"Total: "<<calculatecost()<<endl;
			}
	
					
};
	void cal()
	{
		package a;
		a.setCost(56.5);
	}

int main()
{
	struct data s={"umer","house","karachi","pak",75600};//structures giving values
	struct data r={"faizan","house","karachi","pak",75100};//structures 
	TwoDayPackage dhl(s,r,65.6,900.0,200.0);// parameterized constructors
	TwoDayPackage tcs(s,r,65.6,900.0,20.0);
	
	//dhl.input();  //checking input function
	dhl.Display(); //checking output
	
	
	//**EXTRA ***** practicing operator overloading
	if(dhl>tcs)
	{
		cout<<"\nTrue:"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
	
}
