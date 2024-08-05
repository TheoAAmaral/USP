/***************************************************************/
/**                                                           **/
/**   Nome:       Theo Alves Amaral                           **/
/**   Professor:  Alair Pereira do Lago                       **/
/**   Turma:      03                                          **/
/**   NumeroUSP:  15489914                                    **/
/**   Exercicio-Programa 02                                   **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>


double constante = 2.0/0.6931471806;


double Pot(double base, int expoente){
    double num = base;
    int pot;
    if (expoente == 0){
        return 1;
    }
    else if(expoente == 1){
        return base;
    }
    else{
        for(pot = 0; pot < expoente-1; pot++)
            num = num * base;
        return num;
    }
}

double Log2(double z, double eps){
    int limite = 0;
    double serie = 0;
    double i;
    double modDivisao;
    double prox;

    if(z>1)
        modDivisao = (z-1)/(z+1);
    else
        modDivisao = (-1.0)*((z-1)/(z+1));

    for(i = 1; limite == 0; i = i + 2){
        prox = (1.0/i) * Pot((z-1)/(z+1), i);
        serie = serie + prox;
        if(Pot(modDivisao, i) < eps)
            limite = 1;
    }
    return serie*constante; 
}

double InformacaoMutua(int N11, int N10, int N01, int N00, double eps){
    double N = N11 + N10 + N01 + N00;
    int x, y;
    double px, py, pxy;
    double res = 0, div;
    for(x = 0; x < 2; x++){
        for(y = 0; y < 2; y++){
            if(x == 1){
                px = (N11+N10)/N;
                if(y == 1){
                    pxy = N11/N;
                    py = (N01+N11)/N;
                }
                else{
                    pxy = N10/N;
                    py = (N00+N10)/N;
                }
            }
            else{
                px = (N01+N00)/N;
                if(y == 1){
                    pxy = N01/N;
                    py = (N01+N11)/N;
                }
                else{
                    pxy = N00/N;
                    py = (N00+N10)/N;
                }
            }
            div = pxy/(px*py);
            res = res + (pxy * Log2(div, eps));
        }
    }
    return res;
}

int main(){
    int f;
    double z, eps, log;
    printf("Selecione a funcionalidade f do programa (1 ou 2): ");
    scanf("%d", &f);
    if(f == 1){
        printf("Entre com x e eps: ");
        scanf("%lf %lf", &z, &eps);
        log = Log2(z,eps);
        printf("O logaritmo de %g com precisao %g eh %g\n", z, eps, log);
    }
    else{
        int N11, N10, N01, N00;
        double eps, IM;
        printf("Entre com contadores N11, N10, N01, N00 e com eps: ");
        scanf("%d %d %d %d %lf", &N11, &N10, &N01, &N00, &eps);
        IM = InformacaoMutua(N11, N10, N01, N00, eps);
        printf("A informacao mutua entre as duas variaveis aleatorias eh %g\n", IM);
    }
    return 0;
}