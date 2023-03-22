#include<stdio.h>
#include<math.h>

void main(){
int a,b,c;
printf("Enter the coeffiencts of quadratic equation");

printf("\nEnter a :");
scanf("%d",&a);
printf("\nEnter b :");
scanf("%d",&b);
printf("\nEnter c :");
scanf("%d",&c);

float D,root1,root2;

D=b*b-4*a*c;

if(D>0){
    root1=(-b+sqrt(D))/(2*a);
    root2=(-b-sqrt(D))/(2*a);
    printf("\nFirst Root : %f",root1);
    printf("\nSecond Root: %f",root2);
}
else if(D==0){
    root1=root2=-b/(2*a);
    printf("\nFirst Root : %f",root1);
    printf("\nSecond Root: %f",root2);
}
else{
        printf("\n Roots");

}

}
