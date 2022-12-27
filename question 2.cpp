#include<iostream>

using namespace std;
class Applicant{
	
	string name;
	int age;
	
	public:
		
		Applicant()
		{
		}
		
		Applicant(int x,string y):age(x),name(y)
		{
		}
		
		string getname()
		{
			return name;
		}
		int getage()
		{
			return age;
		}
		void setname(string x)
		{
			name=x;
		}
		void setage(int x)
		{
			age=x;
		}
		
		void input()
		{
			string x;
			int y;
		
		cout<<"Enter Name Of Person:"<<endl;
		
		cin>>x;
		
		setname(x);
		
		cout<<"Enter Age of Person:"<<endl;
		
		cin>>y;
				
		setage(y);
		}
		
	
		
	
};




int main()
{
	Applicant a[3];
	
	for(int i=0;i<3;i++)
	{
	a[i].input();
}
	system("cls");
			int ao=0;
			int k[3];
			int l[3];
	for(int i=0;i<3;i++)
	{
//		if(i!=0)
//		{
//			
//			for(int j=0;j<3;j++)
//			if(a[i].getage()==a[j].getage())//checking all element
//			{
//			cout<<"Same Ages are:"<<endl;
//			cout<<a[i-1].getname()<<endl;
//			cout<<a[i-1].getage()<<endl;
//			cout<<a[i].getname()<<endl;
//			cout<<a[i].getage()<<endl;
//			}
//		}
		 
		{
			
			
			for(int j=1;j<3;j++)
			if(a[i].getage()==a[j].getage())//checking a[0] element with 
			{
				if(j!=i)
				{
					k[ao]=i;
					l[ao]=j;
				cout<<"("<<a[i].getage()<<",";
				cout<<a[i].getname()<<")";
				cout<<"("<<a[j].getage()<<",";
				cout<<a[j].getname()<<")";
				ao++;
			}}
		}
//		for(i=0;i<3;i++)
//		{
//		
//		for(int j=1;j<3;j++)
//			if(a[i].getage()!=a[j].getage())//checking a[0] element with 
//			{
//				if(j!=i && i!=k[i] && i!=l[i]  )
//				{
//				
//				cout<<"("<<a[i].getage()<<",";
//				cout<<a[i].getname()<<")";
//				cout<<"("<<a[j].getage()<<",";
//				cout<<a[j].getname()<<")";
		//	}}
		}
		
}

