#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    const int b = a;
    double c[31];
    for (int i=0;i<=b;i++){
        scanf("%lf",c + i);
    }
    int d;
    scanf("%d",&d);
    double sum = 0.0;
    double m = 0.0;
    for (int i=1;i<=d;i++){
        scanf("%lf",&m);
        double p = 1.0;
        for (int j=0;j<=b;j++){
            sum += c[j] * p;
            p *= m;
        }
        printf("%.3lf\n",sum);
        sum = 0.0;
    }
    return 0;
}

