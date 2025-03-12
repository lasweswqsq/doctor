#include <stdio.h>
#include <stdlib.h>
 
int main() {
    unsigned int num = 0x8401; // 十六进制数
    int binArray[32]; // 存储每个二进制位的数组
    int i;
 
    // 直接将每个位存储到数组中
    for (i = 0; i < 32; i++) {
        binArray[i] = (num >> (31 - i)) & 1; // 获取每一位并存储到数组中
    }
 
    // 打印结果，验证存储的二进制位
    printf("Binary array: ");
    for (i = 0; i < 32; i++) {
        printf("%d ", binArray[i]);
    }
    printf("\n");
 
    return 0;
}