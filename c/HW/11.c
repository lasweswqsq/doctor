#include<stdio.h>
#include<string.h>
int main(){
    char str1[] = "Hello Worldeqrfwrg";
    char str2[] = "Hello W1rld324";
    int result = strcmp(str1, str2);
    printf("The result of strcmp is: %d\n", result);
    return 0;
}