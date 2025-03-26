#include<stdio.h>
int main()
{
    int input;
    scanf("%d",&input);
    int max = input , sum = input;
    while(1){
        scanf("%d",&input);
        if (input == 0){break;}
        sum += input;
        if (input > max){max = input;}
    }
    printf("sum: %d\n",sum);
    printf("maximum: %d\n",max);
    return 0;
}