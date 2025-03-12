#include<stdio.h>

int check(char a[15][17]){
    for(int i=0;i<11;i++){
        for(int j=0;j<15;j++){
            if(a[i][j]=='X' && a[i+1][j]=='X' && a[i+2][j]=='X' && a[i+3][j]=='X' && a[i+4][j]=='X'){
                return 1;
            }
            else if(a[i][j]=='O' && a[i+1][j]=='O' && a[i+2][j]=='O' && a[i+3][j]=='O' && a[i+4][j]=='O'){
                return 1;
            }
        }
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<11;j++){
            if(a[i][j]=='X' && a[i][j+1]=='X' && a[i][j+2]=='X' && a[i][j+3]=='X' && a[i][j+4]=='X'){
            
                return 1;
            }
            else if(a[i][j]=='O' && a[i][j+1]=='O' && a[i][j+2]=='O' && a[i][j+3]=='O' && a[i][j+4]=='O'){
                return 1;
            }
        }
    }

    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(a[i][j]=='X' && a[i+1][j+1]=='X' && a[i+2][j+2]=='X' && a[i+3][j+3]=='X' && a[i+4][j+4]=='X'){
                return 1;
            }
            else if(a[i][j]=='O' && a[i+1][j+1]=='O' && a[i+2][j+2]=='O' && a[i+3][j+3]=='O' && a[i+4][j+4]=='O'){
                return 1;
            }
        }
    }
    for(int i=0;i<11;i++){
        for(int j=4;j<15;j++){
            if(a[i][j]=='X' && a[i+1][j-1]=='X' && a[i+2][j-2]=='X' && a[i+3][j-3]=='X' && a[i+4][j-4]=='X'){
                return 1;
            }
            else if(a[i][j]=='O' && a[i+1][j-1]=='O' && a[i+2][j-2]=='O' && a[i+3][j-3]=='O' && a[i+4][j-4]=='O'){
                return 1;
            }
        }
    }
    return 0;
}

void whitecheck(char a[15][17]){
    for(int k=0;k<15;k++){
        for(int l=0;l<15;l++){
            if(a[k][l] == '.'){
                a[k][l] = 'O';
                for(int i=0;i<11;i++){
                    for(int j=0;j<15;j++){
                        if(a[i][j]=='O' && a[i+1][j]=='O' && a[i+2][j]=='O' && a[i+3][j]=='O' && a[i+4][j]=='O'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
                for(int i=0;i<15;i++){
                    for(int j=0;j<11;j++){
                        if(a[i][j]=='O' && a[i][j+1]=='O' && a[i][j+2]=='O' && a[i][j+3]=='O' && a[i][j+4]=='O'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
            
                for(int i=0;i<11;i++){
                    for(int j=0;j<11;j++){
                        if(a[i][j]=='O' && a[i+1][j+1]=='O' && a[i+2][j+2]=='O' && a[i+3][j+3]=='O' && a[i+4][j+4]=='O'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
                for(int i=0;i<11;i++){
                    for(int j=4;j<15;j++){
                        if(a[i][j]=='O' && a[i+1][j-1]=='O' && a[i+2][j-2]=='O' && a[i+3][j-3]=='O' && a[i+4][j-4]=='O'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
                a[k][l] = '.';
            }
        }
    }
    printf("CannotWin!\n");
    return;
}

void blackcheck(char a[15][17]){
    for(int k=0;k<15;k++){
        for(int l=0;l<15;l++){
            if(a[k][l] == '.'){
                a[k][l] = 'X';
                for(int i=0;i<11;i++){
                    for(int j=0;j<15;j++){
                        //printf("1");
                        if(a[i][j]=='X' && a[i+1][j]=='X' && a[i+2][j]=='X' && a[i+3][j]=='X' && a[i+4][j]=='X'){
                            //printf("2");
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
                for(int i=0;i<15;i++){
                    for(int j=0;j<11;j++){
                        if(a[i][j]=='X' && a[i][j+1]=='X' && a[i][j+2]=='X' && a[i][j+3]=='X' && a[i][j+4]=='X'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
            
                for(int i=0;i<11;i++){
                    for(int j=0;j<11;j++){
                        if(a[i][j]=='X' && a[i+1][j+1]=='X' && a[i+2][j+2]=='X' && a[i+3][j+3]=='X' && a[i+4][j+4]=='X'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
                for(int i=0;i<11;i++){
                    for(int j=4;j<15;j++){
                        if(a[i][j]=='X' && a[i+1][j-1]=='X' && a[i+2][j-2]=='X' && a[i+3][j-3]=='X' && a[i+4][j-4]=='X'){
                            printf("Win!\n");
                            printf("%d %d\n",l+1,k+1);
                            return;
                        }
                    }
                }
                a[k][l] = '.';
            }
        }
    }
    printf("CannotWin!\n");
    return;
}


int main(){
    char board[226];
    char a[15][17];
    int whites=0,blacks=0;
    for (int i = 0; i < 15; ++i) {scanf("%15s", board + i * 15);}
    for (int i = 0; i < 225; ++i){
        if(board[i]=='O'){
            a[i/15][i%15] = 'O';
            whites++;
        }
        else if(board[i]=='X'){
            a[i/15][i%15] = 'X';
            blacks++;
        }
        else{
            a[i/15][i%15] = '.';
        }
    }

    int c = check(a);   
    if(c == 1){
        printf("AlreadyWin!\n");
    }
    else{
        if(whites>=blacks){
            blackcheck(a);
        }
        else if(blacks>whites){
            whitecheck(a);
        }
    }
    return 0;
}