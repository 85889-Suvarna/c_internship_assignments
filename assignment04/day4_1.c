//.Write a function to accept a 2-D array from the user. Write another function to 
//print the 2-d array . 

#include<stdio.h>
void accept_data(int arr[3][2]);
void print_data(int arr[3][2]);

int main (void)
{
    int a[3][2];
    int b[3][2];
    accept_data(a);
    accept_data(b);
    print_data(a);
    print_data(b);
    return 0;
    

}
void accept_data(int arr[3][2])
{
    int i,j;
    printf("enter the element of the arry ");
    for(i=0; i<=3; i++)
    {
        for(j=0; j<=2; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
void print_data(int arr[3][2])
{
    int i,j;
    printf("\nthe element of the arry is");
    for(i=0; i<=3; i++)
    {
        for(j=0; j<=2; j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n-----");
    }
}