#include <stdio.h>
#include <stdlib.h>


int main(){
    printf("escolha um numero inteiro e positivo:")
    scanf("%d",&n)
    double e = 1;
for (int i = 1; i <= n; i++){
  e -= 1/fatorial(i);
}
int fatorial, x = 1;
scanf("%d", &fatorial);
for (int j = 1; j <= fatorial; j++){
  x *= j;
}

return 0
}