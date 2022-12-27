#include <iostream>
#include <iomanip>
using namespace std;
class Movie {
    string name;
    string MPAA_rating;
    int rating[5];
    double average;
    public:
    void addRating(int x){
        if(x<1||x>5)
            return;
        rating[x-1]++;
    }
    double getverage(){
        return average;
    }
    void calculateAverage(){
        average = ( (rating[0]*1) + (rating[1]*2) + (rating[2]*3) + (rating[3]*4) + (rating[4]*5) ) / (rating[0] + rating[1] + rating[2] + rating[3] + rating[4]);
    }
    Movie(string x,string y){
        for(int i=0;i<5;i++)
            rating[i]=0;
        name=x;
        MPAA_rating=y;
    }
    Movie(){
        for(int i=0;i<5;i++)
            rating[i]=0;
    }
    string getNane(){
        return name;
    }
    string getMPAARating(){
        return MPAA_rating;
    }
    void setName(string x){
        name=x;
    }
    void setMPAARating(string x){
        MPAA_rating=x;
    }
    void print(){
        cout << "Movie Name: " << name << endl;
        cout << "MPAA Rating: " << MPAA_rating << endl;
        cout << "Average Rating: " << average << endl;
    }
    void inputRating(){
        int x;
        cout << "Enter Rating for " << name << ": ";
        cin  >> x;
        while( x < 1  ||  x > 5 ){
            cout << "Please Enter a rating between 1 and 5: ";
            cin  >> x;
        }
        rating[x-1]++;
    }
};
int main(){
    Movie m1("Star Wars","PG-13"), m2("Toy Story","E");
    for(int i=0;i<5;i++)
        m1.inputRating();
    for(int i=0;i<5;i++)
        m2.inputRating();
    m1.calculateAverage();
    m2.calculateAverage();
    m1.print();
    m2.print();
}
