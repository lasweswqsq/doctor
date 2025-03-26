#include<stdio.h>
#include<string.h>

int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    const char *ptr1 = "111342234123";    
    if(strcmp(str1, str2) == 0)
        printf("The strings are equal.\n");
    else
        printf("The strings are not equal.\n");
    printf("%lld",strlen(ptr1));
    return 0;
}