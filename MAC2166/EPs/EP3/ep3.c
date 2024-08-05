/***************************************************************/
/**                                                           **/
/**   Nome:       Theo Alves Amaral                           **/
/**   Professor:  Alair Pereira do Lago                       **/
/**   Turma:      03                                          **/
/**   NumeroUSP:  15489914                                    **/
/**   Exercicio-Programa 03                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>

#define NUM 0
#define CONT 1
#define COLS 2
#define MAX 1000
int codificacao[26] = 
{
    1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  ,
    10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90 ,
    100, 200, 300, 400, 500, 600, 700, 800
};

int gMACtria(char c);
int Numetrica(char texto[], int seqnum[]);
int Busca(int tabela[][COLS], int n, int numetria);
int Tabula(int seqnum[], int n, int tabela[][COLS], int m);


int main(){
    char texto[MAX], c;
    int tabela[MAX][COLS],
    seqnum[MAX], 
    i, n, numetria, m = 0, f, resultado;

    while(1){
        printf("Selecione a funcionalidade f do programa (1-7): ");
        scanf("%d", &f);

        if(f == 1){
            printf("Digite um caractere: ");
            scanf(" %c", &c);

            resultado = gMACtria(c);
            printf("A gMACtria de '%c' eh %d\n", c, resultado);           
        }

        else if(f == 2){
            printf("Digite uma palavra: ");
            scanf("%s", texto);

            n = Numetrica(texto, seqnum);
            printf("A numetria de %s eh %d\n", texto, seqnum[0]);
        }

        else if(f == 3){
            printf("Digite um texto com ateh 1000 letras: ");
            scanf(" %[^\n]", texto);

            n = Numetrica(texto, seqnum);
            printf("Sequencia numetrica com codigos das %d palavras: \n", n);
            for(i = 0; i < n; i++){
                printf("%d ", seqnum[i]);
            }
            printf("\n");
        }

        else if(f == 4){
            printf("Digite N e uma sequencia com N inteiros/numetrias: ");
            scanf("%d", &n);
            
            for(i = 0; i < n; i++){
                scanf("%d",&seqnum[i]);
            }

            printf("Sequencia com %d numeros armazenada\n", n);
        }

        else if(f == 5){
            m = Tabula(seqnum, n, tabela, m);
            printf("A sequencia tabulada possui %d pares de numetrias e contadores: \n", m);
            for(i = 0; i < m; i++){
                printf("%4d %4d\n", tabela[i][0],tabela[i][1]);
            }
        }

        else if(f == 6){
            printf("Digite inteiro a ser procurado na primeira coluna da tabela: ");
            scanf("%d", &numetria);

            printf("A posicao encontrada eh %d\n", Busca(tabela, m, numetria));
        }

        else if(f == 7){
            printf("Tchau.\n");
            break;
        }
    }

    return 0;
}

int gMACtria(char c){
    
    if(c >= 'a' && c <= 'z'){
        c = c - 32;
    }

    if(c >= 'A' && c <= 'Z'){
        return codificacao[c-'A'];
    }
    else
        return 0;
}

int Numetrica(char texto[], int seqnum[]){
    int i,j = 0;
    for(i = 0; i < MAX; i++){
        seqnum[i] = 0;
    }
    for(i = 0; texto[i] != '\0'; i++){
        if(texto[i] != ' ' && texto[i] != '\'')
            seqnum[j] = seqnum[j] + gMACtria(texto[i]);
        else
            j++;
    }
    return j+1;
}

int Busca(int tabela[][COLS], int n, int numetria){
    int i;
    for(i = 0; i < n; i++){
        if(tabela[i][0] == numetria){
            return i;
        }
    }
    return -1;
}
int Tabula(int seqnum[], int n, int tabela[][COLS], int m){
    int i, j, novo_num;

    for(i = 0; i < m; i++){
        tabela[i][0] = 0;
        tabela[i][1] = 0;
        m = 0;
    }

    for(i = 0; i < n; i++){
        novo_num = 1;

        for(j = 0; j < m && novo_num; j++){
            if(tabela[j][0] == seqnum[i]){
                tabela[j][1]++;
                novo_num = 0;
            }
        }

        if(novo_num){
            tabela[m][0] = seqnum[i];
            tabela[m][1] = 1;
            m++;
        }
    }
    return m;
}