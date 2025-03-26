#include <stdio.h>
#include <string.h>

int main() {
    char str[1000001];
    const char s[2] = " "; 
    char *token;
    scanf("%s", str);
 
    
    token = strtok(str, s);
    printf("%s\n", token);
 
    // 循环获取剩余的子字符串
    while (token != NULL) {
        printf("%s\n", token);
        
        token = strtok(str, s); // 继续获取下一个子字符串
    }
 
    return 0;
}