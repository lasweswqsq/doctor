#include<stdio.h>
int main()
{
    double a,b,c;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("The sum of the three numbers is: %.2lf",a+b+c);
    return 0;
}