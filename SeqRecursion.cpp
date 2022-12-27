#include<iostream>
using namespace std;

void seq1(int t,int n,int s){
	if(t==0)
		return ;
	else{
		cout<<s<<" ";
		n++;
		t--;
		s+=n;
		seq1(t,n,s);
	}
	
}

void seq2(int t,int n,int s){
	if(t==1)
		return ;
	else{
		cout<<s<<" ";
		n++;
		t--;
		s+=n;
		seq2(t,n,s);
	}
	
}

int main()
{
	int t;
	cout<<"How long: ";
	cin>>t;
	cout<<endl;
	seq1(t,1,1);
	cout<<endl<<endl<<"1 ";
	seq2(t,0,1);

	return 0;
}




