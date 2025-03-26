#include <stdlib.h>
#include <stdio.h>
double divide(int a, int b) {
    if (b == 0) {
    fprintf(stderr, "Division by zero!\n");
    exit(EXIT_FAILURE);
    }
    return 1.0 * a / b;
}

int main(void) {
    int x, y; scanf("%d%d", &x, &y);
    double result = divide(x, y);
    printf("%lf\n", result);
// ...
}