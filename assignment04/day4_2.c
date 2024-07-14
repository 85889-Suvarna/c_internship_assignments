#include<stdio.h>
void accept_data(int arr[3][3]);
void print_data(int arr[3][3]);
void submatrix(int mat1[3][3], int mat2[3][3], int result[3][3]);
void addmatrix(int mat1[3][3], int mat2[3][3], int result[3][3]);
void mulmatrix(int mat1[3][3], int mat2[3][3], int result[3][3]);


int main (void)
{
    int i,j;
    int a[3][3];
    int b[3][3];
    int result[3][3];

    accept_data(a);
    accept_data(b);
    print_data(a);

    print_data(b);
    addmatrix(a,b,result);
    printf("\nthe addtion of two matrix is=");
    print_data(result);

    submatrix(a,b,result);
    printf("\nthe subtraction of two matrix is=");
    print_data(result);

    mulmatrix(a,b,result);
    printf("\n the multiplcation of two matrix is=");
    print_data(result);
    

    
    
    
    return 0;
    

}
void accept_data(int arr[3][3])
{
    int i,j;
    printf("enter the element of the arry ");
    for(i=0; i<=3; i++)
    {
        for(j=0; j<=3; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
void print_data(int arr[3][3])
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
void submatrix(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void addmatrix(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void mulmatrix(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}
