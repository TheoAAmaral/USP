#include <stdio.h>

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
    {{'T',37}, {'C',37}, {'B',37}, {'R',37}, {'D',37}, {'B',37}, {'C',37}, {'T',37}},
    {{'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}, {'P',37}}
};
int i, j;
int Xi, Yi, Xf, Yf;
int color;

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
                if (chessBoard[i][j][0] == ' ')
                    printf("   ");
                else
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

int

int main(){
    while(1){
        outputChessBoard();
        printf("Digite a posição do branco a mudar(Xi Yi Xf Yf): ");
        scanf("%d %d %d %d", &Xi, &Yi, &Xf, &Yf);
        for (i = 0; i < 2; i++){
            chessBoard[Yf-1][Xf-1][i] = chessBoard[Yi-1][Xi-1][i];
        }
        chessBoard[Yi-1][Xi-1][0] = ' ';
        chessBoard[Yi-1][Xi-1][1] = ' ';
        
        outputChessBoard();

        printf("Digite a posição do preto a mudar(Xi Yi Xf Yf): ");
        scanf("%d %d %d %d", &Xi, &Yi, &Xf, &Yf);

        for (i = 0; i < 2; i++){
            chessBoard[Yf-1][Xf-1][i] = chessBoard[Yi-1][Xi-1][i];
        }
        chessBoard[Yi-1][Xi-1][0] = ' ';
        chessBoard[Yi-1][Xi-1][1] = ' ';
    }
    return 0;
}