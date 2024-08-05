#include <stdio.h>
#include <math.h>

#define COLOR_CFG "\033[%dm"
#define COLOR_STD "\033[49m"
#define COLOR_TEXT "\033[39m"

char chessBoard[8][8][2] = {
    {{'T',30}, {'C',30}, {'B',30}, {'R',30}, {'D',30}, {'B',30}, {'C',30}, {'T',30}},
    {{'P',30}, {'P',30}, {'P',30}, {'P',30}, {'P',30}, {'P',30}, {'P',30}, {'P',30}},
    {{' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}},
    {{' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}},
    {{' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}},
    {{' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}, {' ',30}},
    {{'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}},
    {{'T',37}, {'C',37}, {'B',37}, {'R',37}, {'D',37}, {'B',37}, {'C',37}, {'T',37}}
};
int i, j;
int Xinicial, Yinicial, Xfinal, Yfinal;
int color, foundPath;
int posicao[2];

int resetSpaceColor(){
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(chessBoard[i][j][0] == ' ')
                chessBoard[i][j][1] = 30;
        }
    }
    return 0;
}

int outputChessBoard(){
    printf("y");
    for(i = 0; i <= 8; i++){
    printf("\n");

        if(i < 8)
            printf("%d ", i+1);
        else
            printf("  ");

        for(j = 0; j < 8; j++){

            if(i < 8){
                if(j % 2){
                    if(i % 2)
                        color = 47;
                    else
                        color = 49;
                }
                else{
                    if(i % 2)
                        color = 49;
                    else
                        color = 47;
                }
                printf(COLOR_CFG, color);
                printf(COLOR_CFG " %c " COLOR_TEXT, chessBoard[i][j][1], chessBoard[i][j][0]);
                printf(COLOR_STD);
            }

            else{
                printf(" %d ", j+1);
            }
        }
    }
    printf(" x\n");
    return 0;
}

int findPath(int x, int y, int *Xf, int *Yf){
    int validPos = 0;
    int Xreal = x-1;
    int Yreal = y-1;
    char arg1, arg2;
    foundPath = 1;
    if(chessBoard[Yreal][Xreal][0] == 'T'){
        for(i = Xreal+1; i < 8; i++){
            if (chessBoard[Yreal][i][0] == ' ')
                chessBoard[Yreal][i][1] = 42;
            else break;
        }
        for(i = Yreal+1; i < 8; i++){
            if (chessBoard[i][Xreal][0] == ' ')
                chessBoard[i][Xreal][1] = 42;
            else break;
        }
        for(i = Xreal-1; i >= 0; i--){
            if (chessBoard[Yreal][i][0] == ' ')
                chessBoard[Yreal][i][1] = 42;
            else break;
        }
        for(i = Yreal-1; i >= 0; i--){
            if (chessBoard[i][Xreal][0] == ' ')
                chessBoard[i][Xreal][1] = 42;
            else break;
        }
    }
    else if(chessBoard[Yreal][Xreal][0] == 'C'){
        for(i = -2; i <= 2; i += 4){
            if(Yreal + i >= 0 && chessBoard[Yreal+i][Xreal+1][0] == ' ')
                chessBoard[Yreal+i][Xreal+1][1] = 42;
            if(Yreal + i >= 0 && chessBoard[Yreal+i][Xreal-1][0] == ' ')
                chessBoard[Yreal+i][Xreal-1][1] = 42;
            if(Xreal + i >= 0 && chessBoard[Yreal+1][Xreal+i][0] == ' ')
                chessBoard[Yreal+1][Xreal+i][1] = 42;
            if(Xreal + i >= 0 && chessBoard[Yreal-1][Xreal+i][0] == ' ')
                chessBoard[Yreal-1][Xreal+i][1] = 42;
        }
    }
    else if(chessBoard[Yreal][Xreal][0] == 'B'){
        for(i = 1; i < 8; i++){
            if(Xreal+i < 8 && Yreal+i < 8 && chessBoard[Yreal+i][Xreal+i][0] == ' ')
                chessBoard[Yreal+i][Xreal+i][1] = 42;
            else break;
        }
        for(i = 1; i < 8; i++){
            if(Xreal-i >= 0 && Yreal+i < 8 && chessBoard[Yreal+i][Xreal-i][0] == ' ')
                chessBoard[Yreal+i][Xreal-i][1] = 42;
            else break;
        }
        for(i = 1; i < 8; i++){
            if(Xreal+i < 8 && Yreal-i >= 0 && chessBoard[Yreal-i][Xreal+i][0] == ' ')
                chessBoard[Yreal-i][Xreal+i][1] = 42;
            else break;
        }
        for(i = 1; i < 8; i++){
            if(Xreal-i >= 0 && Yreal-i >= 0 && chessBoard[Yreal-i][Xreal-i][0] == ' ')
                chessBoard[Yreal-i][Xreal-i][1] = 42;
            else break;
        }
    }
    else if(chessBoard[Yreal][Xreal][0] == 'R'){
        for(i = Xreal-1; i <= Xreal+1; i++){
            for(j = Yreal-1; j <= Yreal+1; j++){
                if(i >= 0 && i < 8 && j >= 0 && j < 8 && chessBoard[j][i][0] == ' ')
                    chessBoard[j][i][1] = 42;
            }
        }

    }
    else if(chessBoard[Yreal][Xreal][0] == 'D'){
        for(i = 1; i < 8; i++){
            if(Xreal+i < 8 && Yreal+i < 8 && chessBoard[Yreal+i][Xreal+i][0] == ' ')
                chessBoard[Yreal+i][Xreal+i][1] = 42;
            else break;
        }
        for(i = 1; i < 8; i++){
            if(Xreal-i >= 0 && Yreal+i < 8 && chessBoard[Yreal+i][Xreal-i][0] == ' ')
                chessBoard[Yreal+i][Xreal-i][1] = 42;
            else break;
        }
        for(i = 1; i < 8; i++){
            if(Xreal+i < 8 && Yreal-i >= 0 && chessBoard[Yreal-i][Xreal+i][0] == ' ')
                chessBoard[Yreal-i][Xreal+i][1] = 42;
            else break;
        }
        for(i = 1; i < 8; i++){
            if(Xreal-i >= 0 && Yreal-i >= 0 && chessBoard[Yreal-i][Xreal-i][0] == ' ')
                chessBoard[Yreal-i][Xreal-i][1] = 42;
            else break;
        }

        for(i = Xreal+1; i < 8; i++){
            if (chessBoard[Yreal][i][0] == ' ')
                chessBoard[Yreal][i][1] = 42;
            else break;
        }
        for(i = Yreal+1; i < 8; i++){
            if (chessBoard[i][Xreal][0] == ' ')
                chessBoard[i][Xreal][1] = 42;
            else break;
        }
        for(i = Xreal-1; i >= 0; i--){
            if (chessBoard[Yreal][i][0] == ' ')
                chessBoard[Yreal][i][1] = 42;
            else break;
        }
        for(i = Yreal-1; i >= 0; i--){
            if (chessBoard[i][Xreal][0] == ' ')
                chessBoard[i][Xreal][1] = 42;
            else break;
        }
    }
    else if(chessBoard[Yreal][Xreal][0] == 'P'){
        if(Yreal == 1 && chessBoard[Yreal][Xreal][1] == 30){
            for(i = Yreal+1; i <= Yreal+2; i++){
                if(chessBoard[i][Xreal][0] == ' '){
                    chessBoard[i][Xreal][1] = 42;
                }
            else 
                break;
            }
        }
        else if(Yreal == 6 && chessBoard[Yreal][Xreal][1] == 37){
            for(i = Yreal-1; i >= Yreal-2; i--){
                if(chessBoard[i][Xreal][0] == ' '){
                    chessBoard[i][Xreal][1] = 42;
                }
            else 
                break;
            }
        }
        else{
            if(chessBoard[Yreal][Xreal][1] == 30){
                if(chessBoard[y][Xreal][0] == ' '){
                    chessBoard[y][Xreal][1] = 42;
                }
            }
            else{
                if(chessBoard[Yreal-1][Xreal][0] == ' '){
                    chessBoard[Yreal-1][Xreal][1] = 42;
                }
            }
        }
    }
    else{ 
        printf("Nao ha uma peca nessa posicao. ");
        foundPath = 0;
    }   
    while(!validPos && foundPath){
            outputChessBoard();
            printf("Digite a posicao para a qual voce deseja mudar a peca(digite c para cancelar): \n");
            scanf(" %c", &arg1);
            if (arg1 == 'c'){
                foundPath = 0;
                break;
            }
            else{
                scanf(" %c", &arg2);
                *Xf = arg1 - '0' - 1;
                *Yf = arg2 - '0' - 1;
                if(chessBoard[*Yf][*Xf][1] == 42){
                    validPos = 1;
                }
                else{
                    printf("A posicao eh invalida.\n");
                }
            }
        }
    resetSpaceColor();

    return foundPath;
}

int main(){
    while(1){
        outputChessBoard();

        while (!foundPath){
            printf("Digite a posição do branco a mudar(Xi Yi): ");
            scanf("%d %d", &Xinicial, &Yinicial);
            foundPath = findPath(Xinicial, Yinicial, &Xfinal, &Yfinal);
        }
        for (i = 0; i < 2; i++){
            chessBoard[Yfinal][Xfinal][i] = chessBoard[Yinicial-1][Xinicial-1][i];
        }
        chessBoard[Yinicial-1][Xinicial-1][0] = ' ';
        chessBoard[Yinicial-1][Xinicial-1][1] = 30;
        foundPath = 0;
        
        outputChessBoard();

        while (!foundPath){
            printf("Digite a posição do preto a mudar(Xi Yi): ");
            scanf("%d %d", &Xinicial, &Yinicial);
            foundPath = findPath(Xinicial, Yinicial, &Xfinal, &Yfinal);
        }
        for (i = 0; i < 2; i++){
            chessBoard[Yfinal][Xfinal][i] = chessBoard[Yinicial-1][Xinicial-1][i];
        }
        chessBoard[Yinicial-1][Xinicial-1][0] = ' ';
        chessBoard[Yinicial-1][Xinicial-1][1] = 30;
        foundPath = 0;
    }
    return 0;
}