#include <stdio.h>


double constante = 2.8853900818;
double serie;

double Pot(double base, int expoente){
    double num = base;
    int pot;
    if (expoente == 0){
        return 1;
    }
    else{
        for(pot = 0; pot < expoente-1; pot++)
            num = num * base;
        return num;
    }
}


double Log2(float z, float eps){
    double i;
    double divisao = (z-1)/(z+1);
    for(i = 1; (1/i) * Pot(divisao, i) > eps; i = i + 2){
        serie = serie + (1/i) * Pot(divisao, i);
    }
    return serie*constante; 
}

int main(){
    int f;
    float z, eps, log;
    printf("Selecione a funcionalidade f do programa (1 ou 2): ");
    scanf("%d", &f);
    if(f == 1){
        printf("Entre com x e eps: ");
        scanf("%f %f", &z, &eps);
        log = Log2(z,eps);
        printf("O logaritmo de %g com precisao de %g eh %g\n", &z, &eps, &log);
    }
    else{

    }
    return 0;
}