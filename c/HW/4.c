#include<stdio.h>
int main(void){
    double a,b;
    char c,d = 'y';
    while(d=='y'){
        scanf("%lf %c %lf\n",&a,&c,&b);
        if (c=='+'){
            printf("%.6lf + %.6lf == %.6lf\n",a,b,a+b);
        }
        else if (c=='-'){
            printf("%.6lf - %.6lf == %.6lf\n",a,b,a-b);
        }
        else if (c=='*'){
            printf("%.6lf * %.6lf == %.6lf\n",a,b,a*b);
        }
        else if (c=='/'){
                        printf("%.6lf / %.6lf == %.6lf\n",a,b,a/b);
                    }
        else printf("Unknown operator!\n");
        printf("Do you want to continue? (y/n)\n");
        scanf("%c",&d);
    }
    return 0;
}

    