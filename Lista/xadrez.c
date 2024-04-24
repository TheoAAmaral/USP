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
int Xinicial, Yinicial, Xfinal, Yfinal;
int color, foundPath;

int resetSpaceColor(){
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(chessBoard[i][j][0] = ' ')
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

int findPath(int x, int y){
    int Xf, Yf, validPos = 0;
    int pos[2];
    x--;
    y--;    
    if(chessBoard[y][x][0] == 'T'){
        for(i = y+1; i < 8; i++){
            if(chessBoard[y][x][0] == chessBoard[i][x][0]);
            else{
                if(chessBoard[i][x][0] != ' ')
                    break;
                else{
                    chessBoard[i][x][1] = 42; 
                }
            }
        }
        for(i = x+1; i < 8; i++){
            if(chessBoard[y][x][0] == chessBoard[y][i][0]);
            else{
                if(chessBoard[y][i][0] != ' ')
                    break;
                else{
                    chessBoard[y][i][1] = 42;
                }
            }
        }
        for(i = y-1; i > 0; i--){
            if(chessBoard[y][x][0] == chessBoard[y][i][0]);
            else{
                if(chessBoard[i][x][0] != ' ')
                    break;
                else{
                    chessBoard[i][x][1] = 42;
                }
            }
        }

        for(i = x-1; i < 8; i--){
            if(chessBoard[y][x][0] == chessBoard[y][i][0]);
            else{
                if(chessBoard[y][i][0] != ' ')
                    break;
                else{
                    chessBoard[y][i][1] = 42;
                }
            }
        }
        while(!validPos){
            printf("Digite a posicao para a qual voce deseja mudar a peca(digite c para cancelar): ");
            scanf("%d", &Xf);
            if (Xf == 'c'){
                foundPath = 0;
            }
            else{
                scanf("%d", &Yf);
                if(chessBoard[Yf][Xf][1] == 42){
                    validPos = 1;
                }
                else{
                    printf("A posicao eh invalida. ");
                    foundPath = 0;
                }
            }
        }
    }
    else if(chessBoard[y][x][0] == 'C'){

    }
    else if(chessBoard[y][x][0] == 'B'){

    }
    else if(chessBoard[y][x][0] == 'R'){

    }
    else if(chessBoard[y][x][0] == 'D'){

    }
    else if(chessBoard[y][x][0] == 'P'){
        if(y == 1 && chessBoard[y][x][1] == 30){
            for(i = y+1; i <= y+2; i++){
                if(chessBoard[i][x][0] == ' '){
                    chessBoard[i][x][1] = 42;
                }
            else 
                break;
            }
        }
        else if(y == 6 && chessBoard[y][x][1] == 37){
            for(i = y-1; i >= y-2; i--){
                if(chessBoard[i][x][0] == ' '){
                    chessBoard[i][x][1] = 42;
                }
            else 
                break;
            }
        }
        else{
            if(chessBoard[y][x][1] == 30){
                if(chessBoard[y+1][x][0] == ' '){
                    chessBoard[y+1][x][1] = 42;
                }
            }
            else{
                if(chessBoard[y-1][x][0] == ' '){
                    chessBoard[y-1][x][1] = 42;
                }
            }
        }

    }
    else{ 
        printf("Nao ha uma peca nessa posicao. ");
        foundPath = 0;
    }   
    resetSpaceColor();
    pos[0] = Xf;
    pos[1] = Yf;
    return pos;
}

int main(){
    while(1){
        outputChessBoard();

        while (!foundPath){
            printf("Digite a posição do branco a mudar(Xi Yi): ");
            scanf("%d %d", &Xinicial, &Yinicial);
            Xfinal, Yfinal = findPath(Xinicial, Yinicial);
        }
        for (i = 0; i < 2; i++){
            chessBoard[Yfinal-1][Xfinal-1][i] = chessBoard[Yinicial-1][Xinicial-1][i];
        }
        chessBoard[Yinicial-1][Xinicial-1][0] = ' ';
        chessBoard[Yinicial-1][Xinicial-1][1] = 30;
        
        outputChessBoard();

        printf("Digite a posição do preto a mudar(Xi Yi Xf Yf): ");
        scanf("%d %d", &Xinicial, &Yinicial);

        Xfinal, Yfinal = findPath(Xinicial, Yinicial);
        for (i = 0; i < 2; i++){
            chessBoard[Yfinal-1][Xfinal-1][i] = chessBoard[Yinicial-1][Xinicial-1][i];
        }
        chessBoard[Yinicial-1][Xinicial-1][0] = ' ';
        chessBoard[Yinicial-1][Xinicial-1][1] = 30;
    }
    return 0;
}