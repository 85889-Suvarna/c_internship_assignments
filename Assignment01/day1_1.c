#include<stdio.h>
int main(void)
{
    int a;
    int b;
    printf("enter the no a=");
    scanf("%d",&a);
    printf("enter the no b=");
    scanf("%d",&b);
    printf("the sum of the no is\n");
    int c = a+b;
    printf("%d",c);
    printf("\ndiffer between the two no is\n");
    int e = a-b;
    printf("%d",e);
    printf("\n product of the no is");
    int d = a * b;
    scanf("%d*%d = %d",a,b,d);

    return 0;
}