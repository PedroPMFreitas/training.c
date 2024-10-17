#include <stdio.h>

int main() {

    float A,B,C,aux;
    scanf("%f %f %f",&A,&B,&C);
    if(A<B){
        aux=A;
        A=B;
        B=aux;
    }
    if(C>A){
        aux=C;
        C=A;
        A=aux;
    }
    if(C>B){
        aux=C;
        C=B;
        B=aux;
    }
    if(A>=(B+C)){
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    aux=((B*B)+(C*C));
    if((A*A)==aux){
        printf("TRIANGULO RETANGULO\n");
    }
    if((A*A)>aux){
        printf("TRIANGULO OBTUSANGULO\n");
    }
    if((A*A)<aux){
        printf("TRIANGULO ACUTANGULO\n");
    }
    if((A==B)&&(B==C)){
        printf("TRIANGULO EQUILATERO\n");
    }else if(A==B||B==C||A==C){
        printf("TRIANGULO ISOSCELES\n");
    }

    return 0;
}
