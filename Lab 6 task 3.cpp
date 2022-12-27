#include<iostream>

using namespace std;

class Product{
	
	int barcode;
	
	string name;
	
	public:
		
		Product()
		{
			
		}
		Product(int x,string y)
		{
			name=y;
			barcode=x;
		}
		void setbar(int x)
		{
			barcode=x;
		}
		void setname(string x)
		{
			name=x;
		}
		int getbar()
		{
			return barcode;
		}
		string getname()
		{
			return name;
		}
		
};


class PrepakedFood:protected Product
{
	
	 const int price=0;
	
	public:
		PrepakedFood()
		{
		}
		PrepakedFood(int x,string y,int p):Product(x,y), price(p)
		{
			cout<<"\nPrepaked Food:\nBarcode:"<<getbar()<<endl;
			cout<<"Name:"<<getname()<<endl;
			cout<<"Price:"<<getprice()<<endl;
		}
		const void setprice(int x)
		{
			price++;
		}
		int getprice()
		{
			return price;
		}
		
		
};
class Freshfood:protected Product
{
	float weight;
	int price;
	
	public:
		Freshfood()
		{
			
		}
		Freshfood(int x,string y,float w,int p):Product(x,y),weight(w),price(p)
		{
			
			
		}
		void calculate()
		{
			price=weight*price;
		}
		
		int getprice()
		{
			return price;
		}
		int getweight()
		{
			return weight;
		}
		void setweight(int x)
		{
			weight=x;
		}
		void setprice(int x)
		{
			price=x;
		}
		void input()
		{
		int a;	
		cout<<"Enter Id:"<<endl;
		cin>>a;
		setbar(a);	
		}
		void print()
		{
			cout<<"FreshFood:\nBarcode:"<<getbar()<<endl;
			cout<<"Name:"<<getname()<<endl;
			cout<<"Weight:"<<getweight()<<endl;
			calculate();
			cout<<"Price:"<<getprice()<<endl;
		}
};

int main()
{
	Freshfood n(0000112,"Nestle",85,2);
	n.print();
	PrepakedFood n1(1222,"Coke",25);
	Freshfood b[10];
	b[0]=Freshfood(1234,"Pepsi",150,4);
	b[0].print();
	for(int i=0;i<10;i++)
	{
		b[i].input();
		
	}
}
