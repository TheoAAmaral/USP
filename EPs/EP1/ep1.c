/***************************************************************/
/**                                                           **/
/**   Nome:       Theo Alves Amaral                           **/
/**   Professor:  Alair Pereira do Lago                       **/
/**   Turma:      03                                          **/
/**   NumeroUSP:  15489914                                    **/
/**   Exercicio-Programa 01                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>

int f, k, primo, primeiroPrimo, segundoPrimo, n, achouDivisor, i, procurarPrimo, achouPrimo, j, digitos, produtoPrimos;
int raizN, achouRaiz;

int main(){



    printf("Selecione a funcionalidade f do programa (0, 1, 2 ou 3): ");
    scanf("%d", &f);

    if (f == 0){
        printf("Entre com um inteiro a testar se eh primo: ");
        scanf("%d", &n);

        i = 2;
        primo = 0;
        while(i<n){
            if(n%i==0){
                primo = 0;
                i = n;
            }
            else 
                primo = 1;
            i++;
        }

        if(primo == 1)
            printf("O numero %d eh primo \n", n);
        else
            printf("O numero %d nao eh primo \n", n);
    }

    else if(f == 1){
        printf("Entre com n e k: ");
        scanf("%d", &n);
        scanf("%d", &k);

        if(k > 0){
            i = 0;
            procurarPrimo = n;
            achouPrimo = 1;

            while(i < k){
                if(procurarPrimo < 2147483647){
                    procurarPrimo++;
                    j = 2;
                    primo = 0;

                    achouRaiz = 0;
                    while (raizN < procurarPrimo && !achouRaiz){
                        raizN++;
                        if (raizN*raizN >= procurarPrimo){
                            achouRaiz = 1;
                        }
                    }

                    while(j<raizN){
                        if(procurarPrimo%j==0){
                            primo = 0;
                            j = procurarPrimo;
                        }
                        else 
                            primo = 1;
                        j++;
                    }
                    if(primo){
                        i++;
                    }
                }
                else{
                    achouPrimo = 0;
                    i = k;
                }
            }
            if(achouPrimo)
                achouPrimo = procurarPrimo;
        }

        else{
            i = 0;
            procurarPrimo = n;
            achouPrimo = 1;

            while(i < k*-1){
                if(procurarPrimo > 1){
                    procurarPrimo--;
                    j = 2;
                    primo = 0;

                    achouRaiz = 0;
                    while (raizN < procurarPrimo && !achouRaiz){
                        raizN++;
                        if (raizN*raizN >= procurarPrimo){
                            achouRaiz = 1;
                        }
                    }

                    while(j<raizN){
                        if(procurarPrimo%j==0){
                            primo = 0;
                            j = procurarPrimo;
                        }
                        else 
                            primo = 1;
                        j++;
                    }
                    if(primo){
                        i++;
                    }
                }
                else{
                    achouPrimo = 0;
                    i = k*-1;
                }
            }
            if(achouPrimo)
                achouPrimo = procurarPrimo;
        }
        

        if(achouPrimo > 0){
            if(k < 0)
                printf("O %d-esimo primo menor que %d eh %d \n", k*-1, n, achouPrimo);
            else
                printf("O %d-esimo primo maior que %d eh %d \n", k, n, achouPrimo);
        }
        else{
            if(k < 0)
                printf("Nao existe(m) %d primo(s) entre 0 e %d \n", k*-1, n);
            else
                printf("Nao existe(m) %d primo(s) entre %d e 2147483647 \n", k, n);
        }
    }

    else if (f == 2){
        printf("Entre com n e k: ");
        scanf("%d", &n);
        scanf("%d", &k);


        if(k > 0){
            i = 0;
            procurarPrimo = n;
            achouPrimo = 1;

            while(i < k){
                if(procurarPrimo < 2147483647){
                    procurarPrimo++;
                    j = 2;
                    primo = 0;

                    achouRaiz = 0;
                    while (raizN < procurarPrimo && !achouRaiz){
                        raizN++;
                        if (raizN*raizN >= procurarPrimo){
                            achouRaiz = 1;
                        }
                    }

                    while(j<raizN){
                        if(procurarPrimo%j==0){
                            primo = 0;
                            j = procurarPrimo;
                        }
                        else 
                            primo = 1;
                        j++;
                    }
                    if(primo){
                        i++;
                    }
                }
                else{
                    achouPrimo = 0;
                    i = k;
                }
            }
            if(achouPrimo)
                achouPrimo = procurarPrimo;
        }

        else{
            i = 0;
            procurarPrimo = n;
            achouPrimo = 1;

            while(i < k*-1){
                if(procurarPrimo > 1){
                    procurarPrimo--;
                    j = 2;
                    primo = 0;

                    achouRaiz = 0;
                    while (raizN < procurarPrimo && !achouRaiz){
                        raizN++;
                        if (raizN*raizN >= procurarPrimo){
                            achouRaiz = 1;
                        }
                    }

                    while(j<raizN){
                        if(procurarPrimo%j==0){
                            primo = 0;
                            j = procurarPrimo;
                        }
                        else 
                            primo = 1;
                        j++;
                    }
                    if(primo){
                        i++;
                    }
                }
                else{
                    achouPrimo = 0;
                    i = k*-1;
                }
            }
            if(achouPrimo)
                achouPrimo = procurarPrimo;
        }
        

        if(achouPrimo > 0){
                primeiroPrimo = achouPrimo;
                digitos = 0;
                while(achouPrimo > 0){
                    digitos++;
                    achouPrimo = achouPrimo/10;
                }

            if(k < 0)
                printf("O %d-esimo primo menor que %d eh %d e possui %d digito(s)\n", k*-1, n, primeiroPrimo, digitos);
            else
                printf("O %d-esimo primo maior que %d eh %d e possui %d digito(s)\n", k, n, primeiroPrimo, digitos);
        }
        else{
                primeiroPrimo = 0;
            if(k < 0)
                printf("Nao existe(m) %d primo(s) entre 0 e %d\n", k*-1, n);
            else
                printf("Nao existe(m) %d primo(s) entre %d e 2147483647\n", k, n);
        }

        printf("Entre com n e k: ");
        scanf("%d", &n);
        scanf("%d", &k);


        raizN = 0;
        if(k > 0){
            i = 0;
            procurarPrimo = n;
            achouPrimo = 1;

            while(i < k){
                if(procurarPrimo < 2147483647){
                    procurarPrimo++;
                    j = 2;
                    primo = 0;

                    achouRaiz = 0;
                    while (raizN < procurarPrimo && !achouRaiz){
                        raizN++;
                        if (raizN*raizN >= procurarPrimo){
                            achouRaiz = 1;
                        }
                    }

                    while(j<raizN){
                        if(procurarPrimo%j==0){
                            primo = 0;
                            j = procurarPrimo;
                        }
                        else 
                            primo = 1;
                        j++;
                    }
                    if(primo){
                        i++;
                    }
                }
                else{
                    achouPrimo = 0;
                    i = k;
                }
            }
            if(achouPrimo)
                achouPrimo = procurarPrimo;
        }

        else{
            i = 0;
            procurarPrimo = n;
            achouPrimo = 1;

            while(i < k*-1){
                if(procurarPrimo > 1){
                    procurarPrimo--;
                    j = 2;
                    primo = 0;

                    achouRaiz = 0;
                    while (raizN < procurarPrimo && !achouRaiz){
                        raizN++;
                        if (raizN*raizN >= procurarPrimo){
                            achouRaiz = 1;
                        }
                    }

                    while(j<raizN){
                        if(procurarPrimo%j==0){
                            primo = 0;
                            j = procurarPrimo;
                        }
                        else 
                            primo = 1;
                        j++;
                    }
                    if(primo){
                        i++;
                    }
                }
                else{
                    achouPrimo = 0;
                    i = k*-1;
                }
            }
            if(achouPrimo)
                achouPrimo = procurarPrimo;
        }
        

        if(achouPrimo > 0){
                segundoPrimo = achouPrimo;
                digitos = 0;
                while(achouPrimo > 0){
                    digitos++;
                    achouPrimo = achouPrimo/10;
                }

            if(k < 0)
                printf("O %d-esimo primo menor que %d eh %d e possui %d digito(s)\n", k*-1, n, segundoPrimo, digitos);
            else
                printf("O %d-esimo primo maior que %d eh %d e possui %d digito(s)\n", k, n, segundoPrimo, digitos);
        }
        else{
                segundoPrimo = 0;
            if(k < 0)
                printf("Nao existe(m) %d primo(s) entre 0 e %d\n", k*-1, n);
            else
                printf("Nao existe(m) %d primo(s) entre %d e 2147483647\n", k, n);
        }

        if(primeiroPrimo > 0 && segundoPrimo > 0){
            if(2147483647/primeiroPrimo > segundoPrimo){
                produtoPrimos = primeiroPrimo * segundoPrimo;
                digitos = 0;
                while (produtoPrimos > 0){
                    digitos++;
                    produtoPrimos = produtoPrimos/10;
                }
                
                printf("O produto dos dois primos eh %d e possui %d digito(s)", primeiroPrimo * segundoPrimo, digitos);
            }
            else
                printf("O produto dos dois primos eh maior que 2147483647");
        }
        else
            printf("Nao foi possivel calcular o produto dos dois primos");
    }
    else{
        printf("Entre com um inteiro a testar se eh produto de dois primos: ");
        scanf("%d", &n);

        raizN = 0;
        achouRaiz = 0;
        while (raizN < n && !achouRaiz){
            raizN++;
            if (raizN*raizN >= n){
                achouRaiz = 1;
            }
        }

        achouPrimo = 0;
        primo = 1;
        j = 2;
        while(primo && j < n/2){
            if(n%j == 0){
                primo = 0;
            }
            j++;
        }
        if(primo){
            printf("O numero %d nao eh produto de dois fatores que sao primos\n", n);
        }
        else{
            for(k = 2; k <= raizN && !achouDivisor; k++){
                primo = 1;
                j = 2;
                while(primo && j < k/2){
                    if(k%j == 0){
                        primo = 0;
                    }
                    j++;
                }
                if(primo && n%k == 0){
                    primo = 1;
                    j = 2;
                    while(primo && j < (n/k)/2){
                        if(n/k%j == 0){
                            primo = 0;
                        }
                        j++;
                    }
                    if(primo){
                        printf("O numero %d eh produto dos dois primos %d e %d\n", n, k, n/k);
                        achouDivisor = 1;
                    }
                }
            }
            if (!achouDivisor)
            {
            printf("O numero %d nao eh produto de dois fatores que sao primos\n", n);
            }
        }
    }
    return 0;
}