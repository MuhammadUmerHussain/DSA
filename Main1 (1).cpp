#include "HeaderFile1.h"
#include <conio.h>
#include <string.h>
#include<unistd.h>
using namespace std;

int main()
{
	int date,month,minute;
	time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    month=1+ local_time->tm_mon;
	date=local_time->tm_mday;
    minute=local_time->tm_min;
    
	string monthname[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout<<"Date:"<<date<<" "<<monthname[month-1]<<" 2020"<<endl<<endl;
    
    char cha[]={"\n\t\t\t\t\t      WELCOME TO MMS BANK"};
    a:
	style(cha);
	int choice;
	string AccountNumber;	
	cout << "1. CREATE ACCOUNT\n   ---------------\n2. LOG IN ACCOUNT\n   ---------------\n3. EXIT BANK\n   ---------------\n\n";
	cout << "Enter your choice.";
	cin >> choice;
	
	switch (choice){
		case 1:	
			b:
			system("cls");
			style(cha);
			int opt;
			cout << "1. CURRENT ACCOUNT\n   ---------------\n2. SAVING ACCOUNT\n   ---------------\n3. EXIT BANK\n   ---------------\n\n";
			cout << "SELECT TYPE: ";
			cin >> opt;
			if(opt==1)
			{
				CurrentAccount s;
				s.signUp(date,month);
				system("cls");
			 	goto a;
			}
			else if(opt==2)
			{
				SavingsAcc c;
				c.signUp(date,month);
				system("cls");
			 	goto a;
			}
			else if (opt == 3)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\t\t\t****************  THANK YOU FOR USING OUR SERVICE  ****************\n\n\n\n\n\n";
		   		exit(0);	
			}
			
			else
			{
				goto b;
				exit(0);	
			}
		break;	
		
		case 2:		
			c:
			system("cls");
			style(cha); 	
			cout << "1. CURRENT ACCOUNT\n   ---------------\n2. SAVING ACCOUNT\n   ---------------\n3. EXIT BANK\n   ---------------\n\n";
			cout << "SELECT TYPE: ";
			cin >> opt;
			if(opt==1)
			{
				cout << "\nEnter Account Number to login: ";
				cin >> AccountNumber;
			 	CurrentAccount a(AccountNumber, date , month);
			 	
			 	
			} 	
			else if(opt==2)
			{
				cout << "\nEnter Account Number to login: ";
			   	cin >> AccountNumber;
			  	SavingsAcc d(AccountNumber,date , month);
			  	
			}
			else if (opt == 3)
			{
				system("cls");	
				cout << "\n\n\n\n\n\n\n\t\t\t****************  THANK YOU FOR USING OUR SERVICE  ****************\n\n\n\n\n\n";
				exit(0);	
			}
			else
			{
				goto c;
				exit(0);	
			}
			break;
			
	   	case 3:
	   		system("cls");
	   		cout << "\n\n\n\n\n\n\n\t\t\t****************  THANK YOU FOR USING OUR SERVICE  ****************\n\n\n\n\n\n";
		   	exit(0);
			break;
			 
	   	default:
	   		cout << "wrong choice--Press any key to continue\n";
	   		getch();
	   		system("cls");
	   		goto a;
	   		break;
	}
}
