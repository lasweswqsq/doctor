#include<stdio.h>
#include<stdlib.h>
void print1(unsigned x) {
    if (x >= 10)
    print1(x / 10);
    putchar(x % 10 + '0');
    }
    
int main(){
    print1(12345);
    return 0;
}