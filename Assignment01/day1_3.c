#include <stdio.h>

int main()
{
    int num1, num2, num3, max=0;

    
    printf("Enter three numbers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("Num1 = %d, Num2 = %d, Num3 = %d", num1, num2, num3);
      if( num1 > num2 && num1 > num3 )
         max=num1;
     else if( num2 > num3)
           max=num2;
      else
           max=num3;
     
    /*max = (num1 > num2 && num1 > num3) ? num1 :
          (num2 > num3) ? num2 : num3;*/

    printf("\nMaximum between %d, %d and %d = %d", num1, num2, num3, max);

    return 0;
}