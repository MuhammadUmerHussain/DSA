
#include<iostream>
using namespace std;

void print(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
void swap(int* arr1, int* arr2) 
{ 
    int temp = *arr1; 
    *arr1 = *arr2; 
    *arr2 = temp; 
} 

void select(int arr[],int i,int j,int n,int min)//selexton
{

	if(i==n)
	{
		print(arr,n);
		return;
	}
	
	else if(j==n)
	{
		//cout<<min<<endl;
		//cout<<min<<endl;
		if(min!=i)
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[min];
			//cout<<arr[i]<<endl;
			arr[min]=temp;
			//cout<<arr[min]<<endl;
		}
		select(arr,i+1,i+2,n,i+1);
	}
	else
	{
		//cout<<min<<endl;
		//cout<< i << " "<< j<<endl;
		if(arr[j]<arr[min])
		{
			
			min=j;
			
			
			
		}
		
		
		select(arr,i,j+1,n,min);
		
	}
}

//inserction sort
void insert(int arr[],int n)
{
	int temp;
	int j;
	for(int i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	print(arr,n);
	
}


void rec(int arr[],int i,int j,int n,int min)//bubble
{
	if(i==n)
	{
		print(arr,n);
		return;
	}
	else if(i==j)
	{
		
		j=n-1;
		min=arr[i+1];
		
		rec(arr,i+1,j,n,min);
	}
	else{
		if(min>arr[j])
		{
			int temp;
			temp=arr[i];//swapping
			min=arr[j];
			arr[i]=min;
			arr[j]=temp;
			
			
			
		}

		
		rec(arr,i,j-1,n,min);
	}
	
}
int newgap(int space)
{
    space=(space*10)/13;
	if (space < 1)
    return 1;
    return space;
}

void CSort(int arr[], int n)//comb sorting
{
    int space = n;//delecare for gaps 
    bool swapp = true;//checking swap need
    int i;

    while(space!=1 || swapp == true)
    {
        space=newgap(space);//function for gaps
 
        swapp=false;
 
        for (i = 0; i < n - space; i++)
        {if (arr[i] > arr[i + space])
            {swap(arr[i], arr[i+space]);
                swapp = true;
            }
        }
    }
    print(arr,n);
}

int FUN(int arr[], int a, int b) 
{ 
    int pivot = arr[b]; 
    int i=(a-1); 
  
    for (int j=a;j<=b-1;j++) 
    { 
     
        if(arr[j]<pivot) 
        { 
            i++; 
            swap(arr[i],arr[j]); 
        } 
    } 
    swap(arr[i+1],arr[b]); 
    return (i+1); 
} 
  
void quick(int arr[], int a, int b) 
{ 
    if (a < b) 
    { 
        
        int piv = FUN(arr, a, b); 
  
        
        quick(arr,a,piv-1); 
        quick(arr,piv+1,b); 
    } 
} 
  
int main()
{
	int arr[]={5, 3, 8, 1, 4, 6, 2, 7, 10, 9};
	int select1;
	cout<<"Array contains" << " :";
	print(arr,10);
	cout<<"Select the number:"<<endl;
	cout<<"1.bubble 2.selection 3.quick 4.insert 5.Comb"<<endl;
	cin>>select1;
	
	if(select1<6 && select1>0)
{
		
	if(select1==1)
	{
	rec(arr,0,7,10,'w');
	}
	if(select1==2)
	{
		select(arr,0,1,10,0);
		
	}
	if(select1==3)
	{
		CSort(arr,10);
	}
	if(select1==4)
	{
		insert(arr,10);
	}
	if(select1==5)
	{
		select(arr,0,1,10,0);
	}
}
	
}
