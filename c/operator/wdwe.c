#include<stdio.h>
int operator_postfix_inc(int x) { // We must use a C++ notation here.
    int old = x;
    x += 1;
    printf("%d\n%d\n",old,x);
    return old;
    }
    
int compare(int a , int b,int c){
    if (a>b || b>c){
        printf("well done\n");
    }
    else{
        printf("not good\n");
    }
    return 0;
}

int main(){
    int x = 3;
    int a = 22,b =16,c=12129;
    compare(a,b,c);
    printf("Before increment: %d\n", x);
    int lep = operator_postfix_inc(x);
    printf("After increment: %d\n %d\n", x , lep);
    return 0;
}