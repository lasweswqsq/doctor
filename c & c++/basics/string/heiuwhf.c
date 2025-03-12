#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n =2, m = 3;
    int **p = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
        p[i] = malloc(sizeof(int) * m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; ++i)
        free(p[i]);
    free(p);
    return 0;
}

