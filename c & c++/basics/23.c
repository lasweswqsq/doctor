#include<stdio.h>

int fur(int a){
    int list[10];
    for (int i=1;i<=a;i++){
        list[i-1]=i;
    }
    return list[a-1];
}

int main()
{
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && a>c)
        printf("%d is the largest number",a);
    else if(b>a && b>c)
        printf("%d is the largest number",b);
    else
        printf("%d is the largest number",c);
    return 0;
}