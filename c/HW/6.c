#include<stdio.h>
int main(){
    int num,a;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        scanf("%d",&a);
        if(a>=10000){
            printf("%d contains more than 4 digits.\n",a);
        }
        if(a>=1000 && a<10000){
            int z1 = a/1000,z2=(a%1000)/100,z3=(a%100)/10,z4=a%10;
            if(z1==z2 && z2==z3 && z3==z4){
                printf("%d is a repdigit.\n",a);
            }
            else{
                while(a != 6174){
                    z1=a/1000;
                    z2=(a%1000)/100;
                    z3=(a%100)/10;
                    z4=a%10;
                    int *x1 = &z1, *x2 = &z2, *x3 = &z3, *x4 = &z4;
                    if (*x1 > *x2) {int temp = *x1; *x1 = *x2; *x2 = temp; }
                    if (*x1 > *x3) {int temp = *x1; *x1 = *x3; *x3 = temp; }
                    if (*x1 > *x4) {int temp = *x1; *x1 = *x4; *x4 = temp; }
                    if (*x2 > *x3) {int temp = *x2; *x2 = *x3; *x3 = temp; }
                    if (*x2 > *x4) {int temp = *x2; *x2 = *x4; *x4 = temp; }
                    if (*x3 > *x4) {int temp = *x3; *x3 = *x4; *x4 = temp; }
                    int b = z1*1000 + z2*100 + z3*10 + z4;
                    int c = z4*1000 + z3*100 + z2*10 + z1;
                    printf("%d - %d = %d\n",c,b,c-b);
                    a = c-b;
                }
            }
        }
        if(a>=100 && a<1000){
            int z1=a/100,z2=(a%100)/10,z3=a%10,z4=0;
            if(z1>0){
                while(a != 6174){
                    int *x1 = &z1, *x2 = &z2, *x3 = &z3, *x4 = &z4;
                    if (*x1 > *x2) {int temp = *x1; *x1 = *x2; *x2 = temp; }
                    if (*x1 > *x3) {int temp = *x1; *x1 = *x3; *x3 = temp; }
                    if (*x1 > *x4) {int temp = *x1; *x1 = *x4; *x4 = temp; }
                    if (*x2 > *x3) {int temp = *x2; *x2 = *x3; *x3 = temp; }
                    if (*x2 > *x4) {int temp = *x2; *x2 = *x4; *x4 = temp; }
                    if (*x3 > *x4) {int temp = *x3; *x3 = *x4; *x4 = temp; }
                    int b = z1*1000 + z2*100 + z3*10 + z4;
                    int c = z4*1000 + z3*100 + z2*10 + z1;
                    printf("%d - %d = %d\n",c,b,c-b);
                    a = c-b;
                    z1=a/1000;
                    z2=(a%1000)/100;
                    z3=(a%100)/10;
                    z4=a%10;
                }
            }
        }
        if(a>=10 && a<100){
            int z1=a/10,z2=a%10,z3=0,z4=0;
            if(z1>0){
                while(a != 6174){
                    int *x1 = &z1, *x2 = &z2, *x3 = &z3, *x4 = &z4;
                    if (*x1 > *x2) {int temp = *x1; *x1 = *x2; *x2 = temp; }
                    if (*x1 > *x3) {int temp = *x1; *x1 = *x3; *x3 = temp; }
                    if (*x1 > *x4) {int temp = *x1; *x1 = *x4; *x4 = temp; }
                    if (*x2 > *x3) {int temp = *x2; *x2 = *x3; *x3 = temp; }
                    if (*x2 > *x4) {int temp = *x2; *x2 = *x4; *x4 = temp; }
                    if (*x3 > *x4) {int temp = *x3; *x3 = *x4; *x4 = temp; }
                    int b = z1*1000 + z2*100 + z3*10 + z4;
                    int c = z4*1000 + z3*100 + z2*10 + z1;
                    printf("%d - %d = %d\n",c,b,c-b);
                    a = c-b;
                    z1=a/1000;
                    z2=(a%1000)/100;
                    z3=(a%100)/10;
                    z4=a%10;
                }
            }
        }
        if(a>=1 && a<10){
            int z1=a,z2=0,z3=0,z4=0;
            if(z1>0){
                while(a != 6174){
                    int *x1 = &z1, *x2 = &z2, *x3 = &z3, *x4 = &z4;
                    if (*x1 > *x2) {int temp = *x1; *x1 = *x2; *x2 = temp; }
                    if (*x1 > *x3) {int temp = *x1; *x1 = *x3; *x3 = temp; }
                    if (*x1 > *x4) {int temp = *x1; *x1 = *x4; *x4 = temp; }
                    if (*x2 > *x3) {int temp = *x2; *x2 = *x3; *x3 = temp; }
                    if (*x2 > *x4) {int temp = *x2; *x2 = *x4; *x4 = temp; }
                    if (*x3 > *x4) {int temp = *x3; *x3 = *x4; *x4 = temp; }
                    int b = z1*1000 + z2*100 + z3*10 + z4;
                    int c = z4*1000 + z3*100 + z2*10 + z1;
                    printf("%d - %d = %d\n",c,b,c-b);
                    a = c-b;
                    z1=a/1000;
                    z2=(a%1000)/100;
                    z3=(a%100)/10;
                    z4=a%10;
                }
            }
        }
        if(a==0){
            printf("0 is a repdigit.\n");
        }
    }
    return 0;
}
            




    