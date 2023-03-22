#include <stdio.h>

int main()
{

    long a, b;
    int i = 0, remainder = 0, sum[9];



    printf("Enter the first binary number: ");
    scanf("%ld", &a);
    printf("Enter the second binary number: ");
    scanf("%ld", &b);
    while (a != 0 || b != 0)
    {
        sum[i++] =(a%10+b%10+remainder)%2;
        remainder =(a%10+b%10+remainder)/2;
        a= a/10;
        b= b/10;

    }
    if (remainder!=0)
        sum[i++]=remainder;
    --i;
    printf("\nSum of two binary numbers: ");
    while (i >= 0)
        printf("%d", sum[i--]);


    return 0;
}
