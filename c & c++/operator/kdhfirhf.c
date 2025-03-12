#include<stdio.h>
int main(void){
    char s[10] = "abcde"; // s = {'a', 'b', 'c', 'd', 'e', '\0'}
printf("%s\n", s); // prints abcde
printf("%s\n", s + 1); // prints bcde
s[2] = ';'; // s = "ab;de"
printf("%s\n", s); // prints ab;de
s[2] = '\0';
printf("%s\n", s); // prints ab
}