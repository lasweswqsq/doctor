#include <stdio.h>
int main(void) {
    long long x = 1;
    while (1) {
        printf("%lld\n", x);
        x *= 2; // x = x * 2
        getchar();
    }
}
