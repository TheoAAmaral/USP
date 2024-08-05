#include <stdio.h>

#define NUM 0
#define CONT 1
#define COLS 2
#define MAX 1000

int Maiuscula(char c){
    int dif;
    dif = 'a' - 'A';
    if(c<='z' && c>='a')
        c = c - dif;

    return c;
}

int gMACtria( char c ){
    int valor, unidade, cont;
    cont = 0;

    valor = Maiuscula(c);
    unidade = valor - 'A' + 1;
    if(valor<='I' && valor>='A'){
        valor = unidade;
        cont++;
    }
    else if(valor<='R' && valor>='J'){
        unidade = unidade - 9;
        valor = 10*unidade;
        cont++;
    }
    else if(valor<='Z' && valor>='S'){
        unidade = unidade - 18;
        valor = 100*unidade;
        cont++;
    }

    if(cont == 0)
        valor = 0;

    return valor;
}

int Numetrica( char texto[], int seqnum[]){
    int i, j, valor;

    for(i = 0; i < MAX;i++)
        seqnum[i] = 0;

    i = 0;

    for(j = 0; j < MAX && texto[j] != '\0'; j++){
        valor = gMACtria(texto[j]);
        seqnum[i] = seqnum[i] + valor;
        if(valor == 0 && texto[j] != ',' && texto[j] != '.' && texto[j] != '!')
            i++;
    }


    return i;
}

int Tabula( int seqnum[], int n, int tabela[][COLS], int m){
    int i, j, vezes;

    for(m = 0; m < MAX; m++){
        tabela[m][NUM] = 0;
        tabela[m][CONT] = 0;
    }

    m = 0;
    for(j = 0; j < n; j++){
        vezes = 0;
        for(i = 0; i < n && vezes == 0; i++){
            if(seqnum[j] == seqnum[j-i] && i>0 && j-i>= 0)
                vezes = 1;
            if(seqnum[j] == seqnum[j+i] && j+i<= n)
                tabela[j][CONT] = tabela[j][CONT] + 1;
        }
        if(vezes == 0){
            tabela[m][NUM] = seqnum[j];
            m++;
        }
    }

    return m;
}

int Busca(int tabela[][COLS], int n, int numetria){
    int i, posicao;

    posicao = -1;
    for(i = 0; i < n;i++){
        if(tabela[i][NUM] == numetria)
            posicao = i;
    }

    return posicao;
}

int main(){
    int f, codigo, seq[MAX], i, n, M, tabela[MAX][COLS], numetria;
    char letra, palavra[MAX];
    f = 0;

    while(f != 7){
        printf("Selecione a funcionalidade f do programa (1-7): ");
        scanf("%d", &f);

        if(f == 1){
            printf("Digite um caractere: ");
            scanf(" %c", &letra);

            codigo = gMACtria(letra);
            printf("A gMACtria de '%c' eh %d\n", letra, codigo);
        }

        if(f == 2){
            printf("Digite uma palavra: ");
            scanf(" %[^\n]", palavra);

            Numetrica(palavra, seq);
            printf("A numetria de %s eh %d\n", palavra, seq[0]);
        }

        if(f == 3){
            printf("Digite um texto com ateh 1000 letras: ");
            scanf(" %[^\n]", palavra);

            n = Numetrica(palavra, seq) + 1;
            printf("\nSequencia numetrica com codigos das %d palavras: \n", n);

            for(i = 0; i < n ; i++)
                printf("%d ", seq[i]);

            printf("\n");
        }

        if(f == 4){
            printf("Digite N e uma sequencia com N inteiros/numetrias: ");
            scanf("%d", &n);
            for(i = 0; i < n; i++)
                scanf("%d", &seq[i]);

            printf("Sequencia com %d numeros armazenada\n", n);
        }

        if(f == 5){
            M = Tabula(seq, n, tabela, M);

            printf("A sequencia tabulada possui %d pares de numetrias e contadores:\n", M);
            for(i = 0; i < M; i++)
                printf("%4d %4d\n", tabela[i][NUM], tabela[i][CONT]);
        }

        if(f == 6){
            printf("Digite inteiro a ser procurado na primeira coluna da tabela: ");
            scanf("%d", &numetria);

            codigo = Busca(tabela, M, numetria);
            printf("A posicao encontrada eh %d\n", codigo);
        }
        if(f == 7)
                printf("Tchau.");
    }
    return 0;
}