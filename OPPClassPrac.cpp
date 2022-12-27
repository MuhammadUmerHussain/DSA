#include <iostream>
using namespace std;
class office{
    string region;
    string head;
    double daily_expenditure;
    double sales_made;
    double profit;
    public:
        office(string x,string y){
            region=x;
            head=y;
        }
        office(){
            daily_expenditure=0;
            sales_made=0;
            profit=0;
        }
        void calculateProfit(){
            profit=sales_made - daily_expenditure;
        }
        void printingProfit(){
            cout << "Daily Expense: " << sales_made << endl;
            if(profit <= 0){
                cout << "No Profit was made";
            } else {
                cout << "Profit: " << profit << endl;
            }
        }
        void setSalesMade(int x){
            sales_made=x;
        }
        void setDailyExpenditure(int x){
            daily_expenditure=x;
        }
        void setRegion(string x){
            region=x;
        }
        void setHead(string x){
            head=x;
        }
        string getRegion(){
            return region;
        }
        string getHead(){
            return head;
        }
        double getSalesMade(){
            return sales_made;
        }
        double getDailyExpediture(){
            return daily_expenditure;
        }
        double getProfit(){
            return profit;
        }
        void inputSalesMade(){
            cout << "Enter the Sales Made: ";
            cin  >> sales_made;
        }
        void inputDailyExpenditure(){
            cout << "Enter the Daily Expenditure";
            cin  >> daily_expenditure;
        }
};
int main(){
    office senzu_beans("Karachi","Abdullah");
    senzu_beans.inputSalesMade();
    senzu_beans.inputDailyExpenditure();
    senzu_beans.calculateProfit();
    senzu_beans.printingProfit();
}
