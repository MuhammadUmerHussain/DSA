#include<stdio.h>
int main()
{

int num;
	
	int num2=1;
	int j, i;
	printf("Enter A Number:");
	scanf("%d",&num);
	
 
    for(j=0;num !=0 ;j++){
          digit = num % 10;
          multi = multi * digit;
          if(digit!=0)
          printf("%d*",digit);
          num = num / 10;
   }

	
}
