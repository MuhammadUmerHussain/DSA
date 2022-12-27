#include<iostream>

using namespace std;

class Movie{
	
	string MovieName;
	string Mpa_Ratings;
	int rating[5];
	float average;
	
	public:
	void SetName(string movie)
	{
		MovieName=movie;
	}
	void Set_Mpa_Ratings(string mpa)
	{
		Mpa_Ratings=mpa;
	}
	void input_ratings()
	{
		int temp=0;
		cout<<"Enter Rating Of Movie "<<MovieName<<endl;
		cin>>temp;
		
		while(temp<1 || temp>5)
		{
			cout<<"Enter Rating from 1 to 5"<<endl;
			cin>>temp;
		}
		addrating(temp);
		
	}
	void printMovie()
	{
		cout<<"Movie Name:"<<MovieName<<endl;
		cout<<"MPA Rating:"<<Mpa_Ratings<<endl;
		cout<<"Average Rating:"<<average<<endl;
	}
 	void calculateAverage(){
        average = ( (rating[0]*1) + (rating[1]*2) + (rating[2]*3) + (rating[3]*4) + (rating[4]*5) ) / (rating[0] + rating[1] + rating[2] + rating[3] + rating[4]);
    }
    Moive()
    {
    	int i;
    	for(i=0;i<5;i++)
    	{
    		rating[i]=0;
		}
	}
    Movie(string Name,string Mpa)
    {
    	int i;
    	MovieName=Name;
    	Mpa_Ratings=Mpa;
    for(i=0;i<5;i++)
	{
		rating[i]=0;
	}	
    	
	}
    int addrating(int rate)
    {
    	if(rate>0 && rate<6)
    	{
    		return rating[rate-1]++;
		}
	}
	float get_average()
	{
		return average;
	}
	string get_MovieName()
	{
		return MovieName;
	}
	string get_MpaRatings()
	{
		return Mpa_Ratings;
	}
};


int main()
{
	Movie movie1("Bollywood","G");
	Movie movie2("Toy Story","PG");
    for(int i=0;i<5;i++)
        {
		movie1.input_ratings();
		}
    for(int i=0;i<5;i++)
    {
	movie2.input_ratings();
	}
	system("CLS");
    movie1.calculateAverage();
    movie2.calculateAverage();
    movie1.printMovie();
    movie2.printMovie();
}
