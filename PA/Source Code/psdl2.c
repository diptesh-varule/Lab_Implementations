#include<stdio.h>
#include<math.h>

void main(){
int num;
printf("Enter the number to convert :");
scanf("%d",&num);

int binary[10],i;

for(i=0;num>0;i++){
    binary[i]=num%2;
    num=num/2;
    }

printf("\nBinary of Given Number is=");
for(i=i-1;i>=0;i--)
{
printf("%d",binary[i]);
}

}
