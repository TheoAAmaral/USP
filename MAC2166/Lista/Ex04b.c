#include <stdio.h>

#define PI 3.141592654


float pot(float num, int exp){
    float res = num;
    int i;
    if(num == 0){
        return 0;
    }
    else if(exp == 1){
        return num;
    }
    else if(exp == 0){
        return 1;
    }
    else{
        for(i = 0; i < exp; i++){
            res *= num;
        }
        return res;
    }
}


float arctan(float valor){
    float arco = 0;
    int i;
    int sinal = 0;
    for (i = 1; pot(valor,i)/i > 0.0001; i += 2){
        arco = arco + pot(-1,sinal)*(pot(valor,i)/i);
        sinal ^= 1;
    }
    return arco;
}

float angulo(float x, float y){
    float tg;
    if(!x)
        return PI/2;
    else{
        tg = y/x;
        return (arctan(tg));
    }
}

int main(){
    float x, y;
    printf("digite um ponto: ");
    scanf("%f %f", &x, &y);


    printf("o angulo eh %.2f graus ou %.2f rad\n", (angulo(x, y)*180)/PI, angulo(x, y));
    return 0;
}