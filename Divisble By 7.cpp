#include<stdio.h>

int main()
{
	int a;
	int num;
	
	printf("Enter A Number:");
	scanf("%d",&a);
	
	
	if(a!=0 || a!=-7 || a!=7)
	{
	num=a%10;
	//printf("\n%d",num);
	num=num*2;
	//printf("\n%d",num);
	a=a/10;
	//printf("\n%d",a);
	a=a-num;
	printf("%d",a);
		if(a!=0 || a!=-7 || a!=7)
		{
			
		num=a%10;
	//printf("\n%d",num);
		num=num*2;
	//printf("\n%d",num);
		a=a/10;
	//printf("\n%d",a);
		a=a-num;
		
		printf("\n%d",a);
		
		if(a!=0 || a!=-7 || a!=7)
		{
			
		num=a%10;
	//printf("\n%d",num);
		num=num*2;
	//printf("\n%d",num);
		a=a/10;
	//printf("\n%d",a);
		a=a-num;
		
		printf("\n%d",a);
		}
		}
	
	
	}
	
	else if(a == 7 || a== -7 || a==0)
	{
		printf("\nNumber is Divisible By 7");
	}}
