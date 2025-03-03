#include <stdio.h>
#include <stdbool.h>


    int main(void) {
        int num = 3;
printf("num = %d\n", *&num);
        num++;
printf("num = %d\n", num);
        ++num;    }


