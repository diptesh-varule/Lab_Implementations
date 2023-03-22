#include<stdio.h>
#include<math.h>

void main(){
long int bin,count=0;
printf("Enter the binary number : ");
scanf("%d",&bin);
int binary[10],grey[10];

for(int i=0;bin>0;i++)
{
    bin=bin/10;
    binary
    count++;
}



grey[0]=bin[0];

int i=0,j=1;

for(i=0;i<count;i++){
    grey[j]=bin[i]^bin[j];
    j++;
}

for(int i=0,i<count;i++){
    printf("%d",grey[i]);
}
