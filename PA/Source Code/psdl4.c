#include<stdio.h>
#include<math.h>

void main(){

int num;
printf("Enter the number of elements :");
scanf("%d",&num);

printf("Enter the elements :");

int arr[num];

for(int i=0;i<num;i++){
    scanf("%d",&arr[i]);
}

printf("Before Selection Sort: ");
   for(i=0;i<num;i++)
      printf(" %d",arr[i]);

//int arr[10]={44,13,10,67,48,82,1,22,34,90};
int i,j,temp;
for(i=0;i<num;i++){
      for(j=i+1;j<num;j++){
         if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
}


printf("\nAfter Selection Sort : ");
   for(i=0;i<num;i++)
      printf(" %d",arr[i]);

}
