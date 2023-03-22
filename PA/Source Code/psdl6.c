#include <stdio.h>

void binSub(int num1[], int num2[]){
    int borrow = 0;
    int i = 0;
    int result[8];
    for(i = 0; i<8; i++){
        result[i] = ((num1[i] ^ num2[i]) ^ borrow);
        borrow = ((num1[i] & num2[i]) | ((num1[i] ^ num2[i]) & borrow));
    }

    for(int i = 7; i>=0; i--){
        printf("%d", result[i]);
    }
}

int main()
{
   int num1[8];
   int num2[8];
   int i = 7;
   int j = 7;
   printf("Enter the bits for first number: \n");


   while(i>=0){
       printf("Bit number %d: ", i+1);
       scanf("%d", &num1[i]);
       i--;
   }
   printf("Enter the bits for second number: \n");

   while(j>=0){
       printf("Bit number %d: ", j+1);
       scanf("%d", &num2[j]);
       j--;
   }

   binSub(num1, num2);
   return 0;
}
