
#include <stdio.h>
int main(void) {
    double x, y;
    char op;
    scanf("%lf %c %lf", &x, &op, &y);
    if (op == '+')
        printf("%lf\n", x + y);
    else if (op == '-')
        printf("%lf\n", x - y);
    else if (op == '*')
        printf("%lf\n", x * y);
    else if (op == '/')
        printf("%lf\n", x / y);
    else
        printf("Invalid operator.\n");
    return 0;
}
