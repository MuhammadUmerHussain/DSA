#include<iostream>
using namespace std;

void rec(int arr[],int temp[],int n)
{
	static int i=0;
	static int j=0;
	static int k=0;
    
    if(i==n)
    {
    	
       for(int g=0;g<n;g++)
        {
        	
            cout<<"ARRAY IS "<<temp[g]<<endl;
            
        }
		
        return;
    }

    else if(i==j)
    {
    	
        temp[k]=arr[i];
		j=0;
		i++;
		k++;
		
        rec(arr,temp,n);

    }

    else{
        
        if(arr[i]==arr[j])
        {
        	
        	i++;
        	j=0;
            rec(arr,temp,n);
        }
        else
        {
		
        j++;
        
        rec(arr,temp,n);}
    }

}

int main()
{
int arr[]={1,2,3,3,4};
int temp[5];
rec(arr,temp,5);
}
