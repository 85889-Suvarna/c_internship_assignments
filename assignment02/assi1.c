#include<stdio.h>
int main(void)
{
    int t1=0, t2=1,t3=0,n;
    printf("enter the no");
    scanf("%d",&n);
    printf(" fibbonacci series= %d,%d",t1,t2);
    t3=t1+t2;
    while(t3<=n){
        printf("t3=%d",t3);
        t1=t2;
        t2=t3;
        t3=t1+t2;
    } 
    return 0;
    
}