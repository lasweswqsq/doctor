
#include <stdio.h>

int max(int a,int b) {
    if(a>b)
        return a;
    else
        return b;
}

int main(void) {
    int x,y;
    scanf("%d %d",&x,&y);
    printf("Sum = %d\n",x+y);
    printf("big = %d\n",max(x,y));
    puts("Hello, World!\n");
    double z = 3.14;
    printf("x = %f\n",z);
    return 0;
}


