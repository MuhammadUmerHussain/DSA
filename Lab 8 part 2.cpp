#include <iostream>
using namespace std;

#define MAXARRAY 5

class myarray 
{
private:
	
	int value[MAXARRAY];

public:
	int a;
	void setvalue(int index, int newvalue){
		value[index]=newvalue;}
	int getvalue(int index){
		return value[index];}
	myarray operator+(myarray array2)
	{
		myarray temparray;
		for (int i=0; i<MAXARRAY; i++)
			temparray.value[i]=value[i] + array2.value[i];
		return temparray;
	}
	myarray operator-(myarray obj)
	{
		myarray temp;
		for(int i=0;i<MAXARRAY;i++)
		{
			temp.value[i]=value[i]-obj.value[i];
			
		}
		return temp;
	}
	friend ostream &operator <<(ostream &output,myarray  &obj)
	{
		output<<"\nArray Insertion Operator"<< endl;
		output<<"newarray:  ";
		for(int i=0;i<MAXARRAY;i++)
		{
			output<<obj.getvalue(i)<<"    ";
			
			
		}
		return output;
	}
//	myarray operator+(myarray array2)
//	{
//		myarray temparray;
//		for (int i=0; i<MAXARRAY; i++)
//			temparray.setvalue(i,getvalue(i) + array2.getvalue(i));
//		return temparray;
//	}
//		myarray operator+(myarray array2,myarray array3)
//	{
//		myarray temparray;
//		for (int i=0; i<MAXARRAY; i++)
//			temparray.setvalue(i,getvalue(i) + array2.getvalue(i));
//		return temparray;
//	}
//	
	myarray operator++(int)
	{
		myarray temp;
		temp.a=(a+90);
		return temp;
	}
};

int main ()
{

	myarray array1, array2, array3;
	int i;
	
	//INITIALIZE 
	for (i=0; i<MAXARRAY; i++)
	{
		array1.setvalue(i,i);
		array2.setvalue(i,i+3);
	}
	
	//ADD 
	array3=array1 + array2; 
	myarray obj1;
	obj1=array1 - array2; 
	
	//PRINT 
	cout << "array1   array2   array3" << endl;
	for (i=0; i<MAXARRAY; i++)
		cout << array1.getvalue(i) << "        " 
		     << array2.getvalue(i) << "        " 
		     << array3.getvalue(i) << endl;
	
	
	//PRINT 
	cout << "array1   array2   array3" << endl;
	for (i=0; i<MAXARRAY; i++)
		cout << array1.getvalue(i) << "        " 
		     << array2.getvalue(i) << "        " 
		     << obj1.getvalue(i) << endl;
	cout<<array1<<array2<<obj1;
	myarray temp;
	temp++;
	cout<<"AAAAAA"<<temp.a<<endl;
}
