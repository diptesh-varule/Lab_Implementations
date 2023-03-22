#include <stdio.h>
#include <math.h>
int main() {
  int x,y;
  printf("Enter First Number : ");
  scanf("%d",&x);
  printf("Enter Second Number : ");
  scanf("%d",&y);
  int g=x, h=y;
  int a[8];
  int d=0;
    d=x%10;
    for(int i=7;i>3;i--){
      a[i]=d%2;
      d/=2;
    }
    x/=10;
    d=x;
    for(int i=3;i>=0;i--){
      a[i]=d%2;
      d/=2;
    }


  int b[8];
  d=0;
    d=y%10;
    for(int i=7;i>3;i--){
      b[i]=d%2;
      d/=2;
    }
    y/=10;
    d=y;
    for(int i=3;i>=0;i--){
      b[i]=d%2;
      d/=2;
    }
  int c[8];
  int carry=0;
  for(int i=7;i>=0;i--){
    c[i]=carry^(a[i]^b[i]);
    carry=(carry+a[i]+b[i])/2;
  }
  int e=0;
  for(int i=7;i>=4;i--){
    if(c[i]==1){
      e+=pow(2,7-i);
    }
  }
  for(int i=3;i>=0;i--){
    if(c[i]==1){
      e+=pow(2,3-i)*10;
    }
  }
  printf("\n\nThe numbers are: %d and %d\n",g,h);
  printf("The BCD form of %d is: ",g);
  for(int i=0;i<8;i++){
    printf("%d",a[i]);
  }
  printf(" and of %d is : ",h);
  for(int i=0;i<8;i++){
    printf("%d",b[i]);
  }
  printf("\n");
  printf("The addition is : %d",e);

}
