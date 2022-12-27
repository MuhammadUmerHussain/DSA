#include<iostream>
#include<cstring>
#include<conio.h>
#include<fstream>
using namespace std;

class human
{
	
	string fname;
	string mname;
	string lname;
	protected:
	string RegisterID;
	
	string password;
	
	public:
		void DisplayUser()
		{
			cout<<"User Name Is : "<<fname <<" "<<mname<<" "<<lname<<endl;
			
		}
		void input()
		{
			
			
			cout<<"Enter Your First Name: "<<endl;
			cin>>fname;
			cout<<"Enter Your Middle Name:"<<endl;
			cin>>mname;
			cout<<"Enter Your Last Name: "<<endl;
			cin>>lname;
//			cout<<"Enter Your Resgister  "
			cout<<"Enter Your Password:"<<endl;
			cin>>password;
			write();
			
			
		}
		void write()
		{
			ofstream fout;
			fout.open("Input.txt",ios::out);
			fout<<fname<<"\t"<<mname<<"\t"<<lname<<"\t"<<password<<"\t";
			fout.close();
		}
		human()
		{
			
		}
		
		string get_FirstName()
		{
			return fname;
		}
		string get_LastName()
		{
			return lname;
		}
		string get_MiddleName()
		{
			return mname;
		}
		void login()
		{
			cout<<"Enter Your Registration ID:"<<endl;
			cin>>RegisterID;
			cout<<"Enter Your Password:"<<endl;
			cin>>password;
			}
			
			
		string get_registrationID()
		{
			return RegisterID;
		}	

			
};

struct Plot_Propertise{
	
	int Plot_Number;
	string Plot_Location;
	
};
class basicUser: public human{
	
//	struct record_user User,CheckUser;
	struct Plot_Propertise Plot;
	double citizenNo;
	string regno;
	string CheckPassword;
	
	double phoneNumber; 
	string adress;
	
	protected:
		void Options()
		{
				int option_number;
				cout<<"Please Select The Option:"<<endl;
				cout<<"1.View Property\n";
				cout<<"2.Buy Property OR Plot Resgistration:\n";
				cout<<"3.exit"<<endl;
				cin>>option_number;
				
				if(option_number==1)
				{
					basicUser::ViewProperty();
				}
				else if(option_number==2)
				{
					basicUser::PlotRegistration();
				}
				else {
					
					 int main();
				}
			
		}
		
	public:
		
		basicUser()
		{
			
		}
			
		double get_phonenum()
		{
			return phoneNumber;
		}
		string get_address()
		{
			return adress;
		}
		double get_citizen()
		{
			return citizenNo;
		}

		void input()
		{
			
	cout<<"#--------------------------------------------------------------------------#\n";	
	cout<<"#                  Real Estate Property Management                         #\n";
	cout<<"#                                                                          #\n";
	cout<<"#                    You have chosen to Regester                           #\n";	
	cout<<"#                                                                          #\n";
	cout<<"#                  Please provide us with your details                     #\n";
	cout<<"#--------------------------------------------------------------------------#\n";

	
			
			human::input();
			
			
			cout<<"Enter Your Registration Number:"<<endl;
			cin>>RegisterID;
			
			cout<<"Enter Your Phone Number: "<<endl;
			cin>>phoneNumber;
			cout<<"Enter Your Citizen Number"<<endl;
			cin>>citizenNo;
			cout<<"Enter Your Address: "<<endl;
			cin>>adress;
			fwrite();
		}
		void fwrite()
		{
			ofstream fout;
			fout.open("Input.txt",ios::app);
			fout<<"\t"<<RegisterID<<"\t"<<phoneNumber<<"\t"<<citizenNo<<"\t"<<adress<<"\t";
			fout.close();
		}
		void DisplayUser()
		{
			human::DisplayUser();
			cout<<"User Address Is: "<<adress<<endl;
			cout<<"User Citizen Number Is: "<<citizenNo<<endl;
			
			cout<<"User Phone Number Is: "<<phoneNumber;
			cout<<"User Registration Number Is:"<<RegisterID;
		}
		void login()
		{	
	string password;
	int Cnic;
	cout << "___________________"<< endl;
	cout << "----Real Estate----"<< endl;
	cout << "Enter Nic Number: "<< endl;
	cin  >> Cnic;
	cout << "Enter Password: "<< endl;
	cin  >> password; 

	
	ifstream login("Input.txt", ios::in);
	
		string fname;
		string lname;
		string mname;
		double nic;
		double phoneNumber;
		int age;
		string current_adress;
		string Password;
		string x;
	
	while( login>>fname >> mname >> lname >>Password>>x>> phoneNumber >>nic>>  current_adress )
	{
		cout << Password;
		cout << nic;
		
		if(Password == password && nic == Cnic)
		{
			cout << "Login SucessFull \n";
			//menuOf_Seller_Or_Register(password, Cnic);
		}
		else
		{
				cout << "Enter Nic Number: "<< endl;
				cin  >> Cnic;
				cout << "Enter Password: "<< endl;
				cin  >> password; 
		}
	}
//			human::login();
//			
//			if(password == "12345" && RegisterID=="123")//file password == user enter password && citizen number == file citizen number
//			{
//				cout<<"Login Successfull"<<endl;
//				getch();
//				
//				system("cls");
//				basicUser::Options();
//				
//			}
		}
		
	
		void ViewProperty()
		{
			char arr[100];
			ifstream fin;
			FILE *fp;
			char ch;
			
			fp=fopen("Input.txt","r");
			//fin.open("Input.txt",ios::in);
			
//			fin.read((char*)this,sizeof(this));
			while(!feof(fp))
			{
				
				fgets(arr,sizeof(arr),fp);
				cout<<arr<<endl;
			}
			fin.close();
			getch();
			
			
			}	
		void PlotRegistration()
		{
			cout<<"Enter Plot Number:"<<endl;
			cin>>Plot.Plot_Number;
			
			if(Plot.Plot_Number==12345)//file plot number should be added;
			{
				cout<<"Plot Is Available And You Have Register It Successfully:"<<endl;
			}
			
		}
		
		void Filtering()
		{
			int plot;
			cout<<"Enter Plot Number:";
			cin>>plot;
		
			if(plot==12345)//from file plot number
			{
				cout<<":: Plot Number Is Found :: "<<endl;
				cout<<":: Location Is ::"<<Plot.Plot_Location<<endl; //plot location from file;
				}	
			else
			{
				cout<<"Plot Not Found!"<<endl;
				getch();
				menu();
				}	
		}
		void menu()
		{
			system("cls");
			basicUser::Options();
		}
		void storeUser()
		{
			ofstream fout;
			fout.open("MyStore.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(this));
			fout.close();
		}
		void showuser()
		{
			ifstream fin;
			fin.open("MyStore.dat",ios::in|ios::binary);
			if(!fin)
			{
				cout<<"file not found";
			}
			else
			{
				fin.read((char*)this,sizeof(this));
				while(!fin.eof())
				{
					DisplayUser();
					fin.read((char*)this,sizeof(this));
				}
				fin.close();
			}
		}
		
};



int main()
{
	basicUser l;
	
	//l.input();
	//l.storeUser();
	//l.showuser();
	//l.login();
	
	//system("cls");
	l.ViewProperty();
}
