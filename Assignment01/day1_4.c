#include<stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int dev(int a, int b);
int acceptno();
int main(void)
{
    int choice,n1,n2;
    do{
        printf("enter the choice 0.exit 1.sum 2.sub 3.mul 4.dev");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
            n1=acceptno();
            n2=acceptno();
            sum(n1,n2);
            break;

        case 2:
            n1=acceptno();
            n2=acceptno();
            sub(n1,n2);
            break;
        case 3:
            n1=acceptno();
            n2=acceptno();
            mul(n1,n2);
            break;
        case 4 :
            n1=acceptno();
            n2=acceptno();
            dev(n1,n2);    
         break;
            break;
        
        default:
            printf("no of this");
            break;
        }
        }while(choice!=0);
        return 0;
    }



int sum( int a, int b)
{
    printf("addition of two no is =%d\n", (a+b));

}
int sub(int a, int b)
{
    printf("subtraction of two no is= %d\n",(a-b));
}
int mul (int a, int b)
{
    printf("multiplcation of two no is =%d\n",(a*b));

}
int dev(int a, int b)
{
    printf("dev of two no is=%d\n",(a/b));

}
int acceptno(int a)
{
    int val;
    printf("enter the no");
    scanf("%d",&val);
    return val;
}
