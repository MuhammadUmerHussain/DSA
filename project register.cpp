#include<iostream>

using namespace std;


class registeration{
	
	int pass_no;
	string fname;
	string lname;
	int phone;
	string add;
	string password;
	
 public:
 	registeration()
 	{
 		pass_no=0;
 		phone=0;
 		
	 }
	 
	 int getpassno()
	 {
	 	return pass_no;
	 }
	 string getpassword()
	 {
	 	return password;
	 }
	 int getphone()
	 {
	 	return phone;
	 }
	 string getfname()
	 {
	 	return fname;
	 }
	 string getlname()
	 {
	 	return lname;
	 }
	 string getadd()
	 {
	 	return add;
	 }
	 
	 void setfname(string x)
	 {
	 	fname=x;
	 }
	 void setlname(string x)
	 {
	 	lname=x;
	 }
	 void setadd(string x)
	 {
	 	add=x;
	 }
	 
	 void setpassno(int x)
	 {
	 	pass_no=x;
	 }
 	void setphone(int x)
 	{
 		phone=x;
	 }
	void setpassword(string x)
	{
		password=x;
	 } 
	 
	void input()
	{
				system("cls");
cout<<        "       #--------------------------------------------------------------------------#\n"<<endl;	
cout<<        "       #                  Real Estate Property Management                         #\n"<<endl;
cout<<        "       #                                                                          #\n"<<endl;
cout<<        "       #                    You have chosen to Regester                           #\n"<<endl;	
cout<<        "       #                                                                          #\n"<<endl;
cout<<        "       #                  Please provide us with your details                     #\n"<<endl;
cout<<        "       #--------------------------------------------------------------------------#\n"<<endl;

		cout<<"Input Your First Name:"<<endl;
		cin>>fname;
		cout<<"Input Your Last Name:"<<endl;
		cin>>lname;
		cout<<"Enput Your Passport Number:"<<endl;
		cin>>pass_no;
		cout<<"Input Your Phone Number:"<<endl;
		cin>>phone;
		cout<<"Input Your Password:"<<endl;
		cin>>password;
	 } 
	
};


int main()
{
	
	registeration xc;
	xc.input();
	
	}
