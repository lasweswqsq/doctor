#include<stdio.h>







int xx(char c){
    c <= 'z' && c >= 'a' ? printf("lowercase letter") : printf("not a lowercase letter");
}

int main(){
    char c;
    scanf("%c",&c);
    xx(c);
    int i = 0;
    do {
    printf("%d", i++);
    } while (i < 5);
    return 0;
}