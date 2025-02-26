#include<stdio.h>
int plus(int a,int b){
    return a+b;
}
int minus(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int divide(int a,int b){
    return a/b;
}
int main(void){
    int a,b;
    char c;
    scanf("%d %c %d",&a,&c,&b);
    if (c=='+'){
        printf("%d",plus(a,b));
    }
    else if (c=='-'){
        printf("%d",minus(a,b));
    }
    else if (c=='*'){
        printf("%d",multiply(a,b));
    }
    else if (c=='/'){
        printf("%d",divide(a,b));
    }
    return 0;
} 