#include <iostream>
using namespace std;
 
int option_select();
bool availability_checking(int);
void reserve_boarding(int);
void next_flight();
 
int capacity[10]  = {0};
 
int main()
{
   int option;
   bool availability = false;
   bool availability_other = false;
 
for(int x = 0; x < 12; x++)
{
   // option select
   option = option_select();
 
   // check seats availibility in selected section
   availability = availability_checking(option);
 
   if(availability == 1)
   {
      // if there is available place print boarding pass
      reserve_boarding(option);
   }
   else
   // if there is no available place, check seats availability in other section
   {
      if(option == 1)
         availability_other = availability_checking(2);
      else
         availability_other = availability_checking(1);
   }
 
   // ask client is it acceptable to place in other section
   if(availability == 0 && availability_other == 1)
   {
      cout << "There is available place in other section "
         << "\nDo you want to buy it? ([Y]es, [N]o)" << endl;
 
      char other_section;
 
      cin >> other_section;
 
      while(other_section != 'y' && other_section != 'n')
      {
         cout << "Please enter correct answer option" << endl;
         cin >> other_section;
      }
      if(other_section == 'n')
         next_flight();
      else
         if(option == 1)
            reserve_boarding(2);
         else
            reserve_boarding(1);
 
 
   }
   
   else if(availability == 0 && availability_other == 0)
      next_flight();
 
 
   }
}
 
int option_select()
{
   int class_option;
 
   cout << "Please type 1 for \"First Class\""
      << "\nPlease type 2 for \"Economy\"" << endl;
 
   cin >> class_option;
 
   while(class_option != 1 && class_option != 2)
   {
      cout << "Please enter correct option!" << endl;
      cout << "Please type 1 for \"First Class\""
      << "\nPlease type 2 for \"Economy\"" << endl;
      cin >> class_option;
   }
 
   return class_option;
}
 
bool availability_checking(int opt)
{
   int counter_a = 0;
   int counter_b = 0;
 
   if(opt == 1)
   {
      for(int i = 0; i < 5; i++)
      {
         if(capacity[i] == 0)
            counter_a++;
      }
   }
   else
   {
      for(int j = 5; j < 10; j++)
      {
         if(capacity[j] == 0)
            counter_b++;
      }
   }
   if((opt == 1 && counter_a > 0) || (opt == 2 && counter_b > 0))
   {
      cout << "There is available place in section " << endl;
      return 1;
   }
   else
   {
      cout << "There is no available place in section " << endl;
      return 0;
   }
}
 
void reserve_boarding(int section)
{
   int seat = 0;
   if(section == 1)
   {
      for(int i = 0; i < 5; i++)
      {
         if(capacity[i] == 0)
         {
            capacity[i] = 1;
            seat = i + 1;
         }
         if(seat != 0)
            break;
      }
      if(seat != 0)
      {
         cout << "**** 1. Boarding Pass ****\nYour section:\t" << section
            << "\nYour seat:\t" << seat << endl;
      }
   }
   else
   {
      for(int j = 5; j < 10; j++)
      {
         if(capacity[j] == 0)
         {
            capacity[j] = 1;
            seat = j + 1;
         }
         if(seat != 0)
            break;
      }
      if(seat != 0)
      {
         cout << "**** 2. Boarding Pass ****\nYour section:\t" << section
            << "\nYour seat:\t" << seat << endl;
      }
   }
}
 
void next_flight(void)
{
   cout << "Next flight leaves in 3 hours." << endl;
}
