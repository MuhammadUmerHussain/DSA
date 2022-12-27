#include<iostream>
using namespace std;
class clothes     //THIS IS A CLASS OF CLOTHES...
{             
	private:
	string tag_id;
	float revenue;
	public:
		clothes()   //DEFAULT CONSTRUCTOR
		{
			tag_id=" ";
			revenue=0;
		}
		clothes(string i, float r)   //PARAMETRIZED CONSTRUCTOR
		{
			tag_id=i;
			revenue=r;
		}
		// SETTERS AND GETTERS TO SET VALUES.
		void set_id(string x)
		{
			tag_id=x;
		}
		string get_id()
		{
			return tag_id;
		}
		void set_revenue(float x)
		{
			revenue=x;
		}
		float get_revenue(){
			return revenue;
		}
	};
		//THIS IS A CLASS OF SHIRTS WHICH IS INHERITED FROM THE CLASS OF 'clothes'.
		class shirts:public clothes{
			private:
				int quantity;
				float discount;
			string design;
			float price;
			public:
				shirts()    //DEFAULT CONSTRUCTOR
				{
					design="";
					price=0;
					quantity=0;
					discount=0;
				}
				shirts(string d,string i,float r,int q,float ds):clothes(i,r)  //PARAMETRIZED 
				                                                  // CONSTRUCTOR
	             {
					design=d;
					quantity=q;
					price=1500;
					discount=ds;
				}
				shirts(string d,string i,float r,int q):clothes(i,r)  //PARAMETRIZED 
				                                                  // CONSTRUCTOR
	             {
					design=d;
					quantity=q;
					price=1500;
				
				}
				//SETTERS AND GETTERS OF 'shirts' class DATA MEMBERS.
				void set_design(string d)
				{
					design=d;
				}
				string get_design()
				{
					return design;
				}
				float get_price()
				{
					return price;
				}
				void set_quantity(int q)
				{
					quantity=q;
				}
				int get_quantity()
				{
					return quantity;
				}
				void set_discount(float ds)
				{
					discount=ds;
				}
				float get_ds()
				{
					return discount;
				}
				float bill()
				{
					float total;
					total=price*quantity;
					return total;
				
				}
				
				float bill(string x)
				{
					float total;
					if(x.length()==7)
					{
						discount=bill()*discount;
						total=discount*bill();
					    return total;
					}
					
				}
				
				
		};
		class pants:public clothes{
			private:
				string design;
				float price;
				int quantity;
				public:
					pants()    //DEFAULT CONSTRUCTOR
					{
						design="";
						price=0;
						quantity=0;
					}
					pants(string d, string i,float r,int q):clothes(i,r)
					{
						quantity=q;
						design=d;
						if(design=="narrow")
						{
							price=2000;
						}
						else if(design=="bell bottomed")
						{
							price=1600;
						}
						else
						{
						  price=200;
						}
					}
					//SETTERS AND GETTERS TO SET DESIGN OF PANT.
					void set_design(string d)
					{
						design=d;
					}
					string get_design()
					{
						return design;
					}
					float get_price()
					{
						return price;
					}
				void set_quantity(int q)
				{
					quantity=q;
				}
				int get_quantity()
				{
					return quantity;
				}
				float bill()
				{
					float total;
					total=price*quantity;
					return total;
				
				}	
		};
    class tie:public clothes{
    	string pattern;
    	float price;
    	int quantity;
    	public:
    		tie()  //DEFAULT CONSTRUCTOR
    		{
    			pattern="";
    			price=0;
    			quantity=0;
			}
			//PARAMETRIZED CONSTRUCTOR.
			tie(string p,string i,float r,int q):clothes(i,r)
			{
				quantity=q;
				pattern=p;
				if(pattern=="checkered")
				{
					price=800;
				}
				else if(pattern=="striped")
				{
					price=700;
				}
				else{
					cout<<"PATTERN NOT AVAIALABLE:"<<endl;
				}
			}
			//SETTER AND GETTER TO SET PATTERN OF TIE.
			void set_pattern(string p)
			{
				pattern=p;
			}
			string get_pattern()
			{
				return pattern;
			}
			float get_price()
			{
				return price;
			}
			float bill()
				{
					float total;
					total=price*quantity;
					return total;
				
				}
	};
	class suite:public pants,public shirts,public tie{
		private:
			float price;
			public:
				suite()
				{
					price=0;
				}
				suite(string ds,string dp,string dt,string i,float r,float qs,float qp,float qt):shirts(ds,i,r,qs),pants(dp,i,r,qp),tie(dt,i,r,qt)
				{
					
				}
			float add_bill()	
			{
				price=pants::get_price()+shirts::get_price()+tie::get_price();
				return price;
			}
			bool operator <(const suite obj )
			{
				if(pants::bill()< shirts::bill())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
	};
	int main()
	{
		suite s("blue","narrow","checkered","umer",500,2,1,1);
		suite s1("red","narrow","checkered","umer",500,2,1,1);
		cout<<(s<s);
	}
