#include<stdio.h>
int main(){
    int x = 42;
    printf("%d/n" , x++);
    printf("%d/n" , ++x);
    int y = ++x;
    return 0;
}