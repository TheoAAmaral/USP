#include <stdio.h>

int main(){
    int n, k, impar, i=0, cond = 1;

    printf("Digite o tamanho da sequência: ");
    scanf("%d", &n);

    printf("Digite a sequência: ");
    scanf("%d", &k);

    impar = k % 2;
    n--;

    while(i < n && cond == 1){
        scanf("%d", &k);
        if(k % 2 == impar){
            cond = 1;
        }
        else
            cond = 0;
    }
    if (cond == 1)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}