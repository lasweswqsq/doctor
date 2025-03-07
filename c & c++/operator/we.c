#include<stdio.h>

int change(int *ptra, int *ptrb)
{
    int temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;
    return 0;
}

int main()
{
    int a = 10, b = 5;
    int *ptra = &a, *ptrb = &b;
    change(ptra, ptrb);
    printf("a = %d, b = %d", a, b);
    return 0;
}