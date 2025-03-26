#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    double x1,x2,delta;
    scanf("%d%d%d",&a,&b,&c);
    if (a != 0){
        delta = b*b - 4*a*c;
        if (delta >= 0){
            x1 = (-b + sqrt(delta)) / (2*a);
            x2 = (-b - sqrt(delta)) / (2*a);
            if(x1 == x2){
                printf("x1 = x2 = %.3lf",x1);
            }
            else if (x1 > x2){
                printf("x1 = %.3lf, x2 = %.3lf",x2,x1);
            }
            else{
                printf("x1 = %.3lf, x2 = %.3lf",x1,x2);
            }
        }
        else printf("No solution.");
    }
    else{
        if (b != 0){
            x1 = -1.0*c / b;
            printf("x = %.3lf",x1);
        }
        if (b == 0 && c != 0){
            printf("No solution.");
        }
        if (b == 0 && c == 0){
            printf("x\\in\\mathbb{R}");  
        }
    }
}