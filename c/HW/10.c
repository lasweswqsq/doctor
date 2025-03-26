#include<stdio.h>
int hw3_islower(int c){
    return c>='a'&&c<='z';
}
int hw3_isupper(int c){
    return c>='A'&&c<='Z';
}
int hw3_isalpha(int c){
    return (hw3_islower(c) || hw3_isupper(c));
}
int hw3_isdigit(int c){
    return c>='0'&&c<='9';
}
int hw3_tolower(int c){
    return hw3_isupper(c) ? c+32:c;
}
int hw3_toupper(int c){
    return hw3_islower(c) ? c-32:c;
}
size_t hw3_strlen(const char *str){
    if (str==NULL){
        return 0;
    } 
    size_t len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}
char *hw3_strchr(const char *str, int ch){
    if (str==NULL) {
        return NULL;
    }
    size_t len=0;
    while(str[len]!='\0'){
        if (str[len]==ch) {
            return (char*)str+len;
        }
        len++;
    }
    if (ch=='\0'){
        return (char*)str+len;
    }
    return NULL;
}
char *hw3_strcpy(char *dest, const char *src){
    if (dest==NULL || src==NULL){
        return NULL;
    }
    size_t len=0;
    while(src[len]!='\0'){
        dest[len]=src[len];
        len++;
    }
    dest[len]='\0';
    return dest;
}
char *hw3_strcat(char *dest, const char *src){
    if (src==NULL){
        return NULL;
    }
    int j = 0;
    while(dest[j]!='\0')  {
        j++;
    }
    int i = 0;
    while(src[i]!='\0'){
        dest[j+i]=src[i];
        i++;
    }
    dest[j+i]='\0';
    return dest;
}
int hw3_strcmp(const char *lhs, const char *rhs){
    if (lhs==NULL || rhs==NULL){
        return 0;
    }
    int i=0;
    while(*lhs!='\0' && *rhs!='\0'){
        if (*lhs!=*rhs){
            return *lhs-*rhs;
        }
        lhs++;
        rhs++;
        i++;
    }
    if (*lhs=='\0' && *rhs=='\0'){
        return 0;
    }
    else if (*lhs=='\0'){
        return -1;
    }
    else{
        return 1;
    }
}


