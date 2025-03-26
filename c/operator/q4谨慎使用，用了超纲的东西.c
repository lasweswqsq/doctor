#include <stdbool.h>
#include <stdio.h>

int main() {
    double a, b, r;
    char c;
    while (true) {
        scanf("%lf %c %lf\n", &a, &c, &b);
        switch (c) {
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case '*': r = a * b; break;
            case '/': r = a / b; break;
            default:
                printf("Unknown operator!\n");
                goto check;
        }
        printf("%lf %c %lf == %lf\n", a, c, b, r);
        check:
        printf("Do you want to continue? (y/n)\n");
        scanf("%c", &c);
        if (c == 'y') continue;
        else break;
    }
    return 0;
}