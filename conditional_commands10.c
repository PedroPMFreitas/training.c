#include <stdio.h>
#include <stdlib.h>
int main () {
char g;
float h,w;
    printf("tell me your gender(m for male , f for female):");
    scanf("%c",&g);
    printf("tell me your height in meters:");    
    scanf("%f",&h);
    switch( g ){
        case 'm':
            w = (72.7*h)-58;
            printf("your ideal weight as a male is: %f kilogram",w);
        break;
        case 'f':
            w = (62.1*h)-44.7;
            printf("your ideal weight as a female is:%f kilogram",w);
        break;
        default:
            printf("you wrote an invalid genre ");
            
    }


 
    






return 0;
}