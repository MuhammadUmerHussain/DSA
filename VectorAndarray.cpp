#include<iostream>
#include<vector>
using namespace std;
int fuc(int arr[],int num);
void input()
{
	int num;
    cin>>num;
   int *arr=new int[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    fuc(arr,num);
	
}
int fuc(int arr[],int num)
{
	int SUMM=0;
   bool initial=true;
   vector<int> maxi;
   vector<int> currentarray,sparearray;


   int presnt=arr[0],max2=arr[0];  //will help out in case of all elements.
   for(int i=0;i<num;i++){
        SUMM+=arr[i];
   
     if(SUMM>=max2){ //also tell us that arr[i] is positive.
        max2=SUMM;    //if max2 is found to be less than current subArray's sum.
        
        if(currentarray.size()>sparearray.size())
        {
            sparearray=currentarray;  //copy elements, when their is a negative element in between the current subArray.
        }
        sparearray.push_back(arr[i]);  //otherwise store the positive element only,
     }

    if(SUMM>0)
    {
        presnt=SUMM;
        currentarray.push_back(arr[i]);  //this is storing all elements including in-between negative element.
    }
    else
    {
        if(max2>presnt )
         {
            maxi=sparearray;  //
         }   
         else if(max2==presnt && initial)  //will help if the elements are all negative. 
         {
            maxi=sparearray; initial=false;
         }

         sparearray.clear();
         currentarray.clear();
         SUMM=0;
    }
   

   } 
   if(SUMM>0)
      maxi=sparearray;   // this is self-explainatory.


    for(int i=0; i<maxi.size(); i++)
    {
        cout<<maxi[i]<<" ";
    }
    cout<<endl<<max2; 

}



int main()
{
     input();
    
}

