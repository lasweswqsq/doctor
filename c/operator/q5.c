#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a != 0) {
        double delta = b * b - 4.0 * a * c;
        if (delta > 0.0) { // 6
            double
                p = (double) (- b - pow(delta, 0.5)) / 2.0 / a,
                q = (double) (- b + pow(delta, 0.5)) / 2.0 / a;
            printf(
                "x1 = %.3lf, x2 = %.3lf\n",
                p < q ? p : q,
                p > q ? p : q
            );
        }
        else if (delta < 0.0) printf("No solution.\n"); // 9, 10
        else printf("x1 = x2 = %.3lf\n", -b / 2.0 / a); // 8
    }
    else {
        if (b != 0.0) printf("x = %.3lf\n", -c / b);
        else if (c != 0.0) printf("No solution.\n");
        else printf("x\\in\\mathbb{R}\n");
    }
    return 0;
}