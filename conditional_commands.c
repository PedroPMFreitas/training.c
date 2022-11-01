#include <stdio.h>
#include <stdlib.h>
int main () {
int x,y;
    printf("write two numbers:");
    scanf("%d",&x);
    scanf("%d",&y);
if(x >=y){
    printf("the biggest is :%d",x);
    if(x ==y){
        printf("\nequal numbers");
    }
}else

    printf("the biggest one is :%d",y);     
return 0;
}