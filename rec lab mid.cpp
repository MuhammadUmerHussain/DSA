#include<iostream>
using namespace std;


void rec(string x,string c,int n,int f)
{
    static int i=0;
    static int j=0;
    static int count=0;
    if(i==n)
    {
        
        if(count==n)
        {
            cout<<"present"<<endl;
            return;
        }
        else
        {
            cout<<"Not Present"<<endl;
            return;
        }
        
    }
    else if(j>f)
    {
        

        cout<<"Not Present"<<endl;
            return;

    }
    else{
        if(c[i]==x[j])
        {
            
            count++;
            i++; 
            j=0;
            rec(x,c,n,f);
        }
        else{
            j++;
            rec(x,c,n,f);
        }
    }
}

int main()
{
    string x="table";
    string c="bat";
    int n=c.length();
    int f=x.length();
    rec(x,c,n,f);



}
