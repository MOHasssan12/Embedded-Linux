
#include <stdio.h>
#include"../include/calc.h"

int main()
{
 int var1 , var2 , result;

 char sym;

printf("please enter calc operation");
scanf("%c",&sym);

printf("please enter the first number");
scanf("%d",&var1);

printf("please enter second number ");
scanf("%d",&var2);

result=calc(sym , var1 , var2);

printf("%d",result);


    return 0;
}
