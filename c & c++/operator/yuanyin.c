#include <stdio.h>

int main() {
    char letter;
    printf("Enter a letter: ");
    scanf("%c", &letter);



switch (letter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    printf("%c is vowel.\n", letter);
    break;
    default:
    printf("%c is consonant.\n", letter);
    }}