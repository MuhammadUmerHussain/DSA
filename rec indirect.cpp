#include<iostream>
using namespace std;

void sum1(int t,int n,int s);
void sum2(int t,int n,int s);
void seq1(int t,int n,int s){
	if(t==1)
		return ;
	else{
		
		n++;
		t--;
		s+=n;
		sum1(t,n,s);
	}
	
}
void seq2(int t,int n,int s){
	if(t==1)
		return ;
	else{
		n++;
		t--;
		s+=n;
		sum2(t,n,s);
	}
	
}
void sum1(int t,int n,int s){
	cout<<s<<" ";
	seq1( t, n,s);
}

void sum2(int t,int n,int s){
	cout<<s<<" ";
	seq2( t, n,s);
}


int main()
{
	int t;
	//cout<<"How long: ";
	//cin>>t;
	//cout<<endl;
	//cout<<"1 ";
	seq1(8,1,1);		
	//cout<<endl<<endl<<"1 ";
	//cout<<"1 ";
	//seq2(t,0,1);
	return 0;
}
