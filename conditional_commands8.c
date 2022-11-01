#include <stdio.h>
#include <stdlib.h>
int main () {
float x,y,z;
    printf("write two notes:");
    scanf("%f",&x);
    scanf("%f",&y);
z = (x+y)/2;
if(x<=10){
    if(x>=0){
    printf("%f",z);
        }else{
            printf("the note does not have a valid value");
            }
}else{
    printf("the note does not have a valid value");
    } 
return 0;
}