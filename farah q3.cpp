#include<iostream>
#include<vector>
using namespace std;
void MaxSum(int array[], int number);
void Input()
{
	cout<<"\nEnter the size of the array : ";
	int num;
    cin>>num;
    
    cout<<"\nEnter the elements in the array : ";
   int *arr=new int[num];//assigning memory to the array
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    MaxSum(arr,num);
}
void MaxSum(int array[],int number)
{
	
	int Sum=0; //for holding the sum 
   bool initially=true;//have setted the bool in the first time true
   
   
   vector<int> Sub_curr;//}
   vector<int> Spare_sub;//}
    vector<int> Max_subArr;//}have used vectors for the sub arrays


   int Curr_sum=array[0];///here initially setting the sum to zero 
   int Max_sum=array[0]; 
    
   for(int i=0;i<number;i++){
        Sum+=array[i];
   
     if(Sum>=Max_sum){ 
        Max_sum=Sum;    
        //// here if the max sum is lesser then the sum then assign sum to max sum
        if(Sub_curr.size()>Spare_sub.size())
        {///initailly we setted the spare sub size now assign the curr subsize to the spare sub size just to store in that
            Spare_sub=Sub_curr;  
        }
       Spare_sub.push_back(array[i]);  
     }

    if(Sum>0)
    {
       Curr_sum=Sum;//1
        Sub_curr.push_back(array[i]); //1 
    }
    else
    {
        if(Max_sum>Curr_sum )
         {
         	/// if the max sum is greator then the curr sum then assign sapre sub to the max sub array
           Max_subArr=Spare_sub; 
         }   
         else if(Max_sum==Curr_sum && initially)  
         {
         	//now here if the max sum and the curr sum are equal then assign the  the spare sub to the max sub array
            Max_subArr=Spare_sub; initially=false;
         }

        Spare_sub.clear();
        Sub_curr.clear();
        Sum=0;
        
    if(Sum>0)
      Max_subArr=Spare_sub;   


    for(int i=0; i<Max_subArr.size(); i++)
    {
    	
        cout<<Max_subArr[i]<<" ";
    }
    cout<<endl<<Max_sum; 
    }
   

   } 
}
int main()
{
   
   Input();//in this func will take input the array size and the and the elements in the array

	
   

}
