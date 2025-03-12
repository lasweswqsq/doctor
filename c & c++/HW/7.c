#include <stdio.h>
int main() {
    int num,x[6] ={0,0,0,0,0,0};
    scanf("%d", &num);
    for (int j = 0;j<num;j++){
        unsigned int rt;
        scanf("%x", &rt);
        //printf("%x\n", rt);
        unsigned int list[16];
        for (int i = 0; i < 16; i++) {
            list[i] = (rt >> (15 - i)) & 1;
            //printf ("%d", list[i]);
        }
        int sign = list[0]*4 + list[1]*2 + list[2]*1;
        int im1 = list[3]*4 + list[4]*2 + list[5]*1;
        int im2 = list[6]*4 + list[7]*2 + list[8]*1;
        int im3 = list[9]*64 + list[10]*32 + list[11]*16 + list[12]*8 + list[13]*4 + list[14]*2 + list[15]*1;
        if (sign == 0){
            if(im1 != 0){
            x[im1] += x[im2];}
        }
        else if (sign == 1){
            if (im1 != 0){
            x[im1] -= x[im2];}
        }
        else if (sign == 2){
            if (im1 != 0){
            x[im1] *= x[im2];}
        }
        else if (sign == 3){
            if (im1 != 0){
            x[im1] /= x[im2];}
        }
        else if(sign == 4){
            if (im1 != 0){
            x[im1] = im3;}
        }
        else if(sign == 5){
            if(im1 == 0){printf("x0 = %d\n", x[im1]);}
            else if(im1 == 1){printf("x1 = %d\n", x[im1]);}
            else if(im1 == 2){printf("x2 = %d\n", x[im1]);}
            else if(im1 == 3){printf("x3 = %d\n", x[im1]);}
            else if(im1 == 4){printf("x4 = %d\n", x[im1]);}
            else if(im1 == 5){printf("x5 = %d\n", x[im1]);}
        }
    }
    return 0;
}