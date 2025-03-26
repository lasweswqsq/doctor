#include <stdio.h>

int main(void){  
    char op;
    double a, b;
    scanf("%lf %c %lf", &a, &op, &b);
    switch (op) {
        case '+':
        printf("%.10lf\n", a + b); break;
        case '-':
        printf("%.10lf\n", a - b); break;
        case '*':
        printf("%.10lf\n", a * b); break;
        case '/':
        printf("%.10lf\n", a / b); break
        default:
        printf("Invalid operator!\n");
        break;
        }
    return 0;
    }
    