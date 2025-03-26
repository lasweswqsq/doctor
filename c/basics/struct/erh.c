#include <stdio.h>

int main(void) {
    char str[] = "Hello_CS100";
    printf("%s\n", str);      // (1)
    printf("%s\n", str + 7);  // (2)
    str[5] = 0;          
    printf("%s\n", str);      // (3)
    const char *fstr = "%s/\\\n";
    printf(fstr, str+1);      // (4)
}