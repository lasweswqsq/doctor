#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int num;
    scanf("%d",&num);
    for (int i=0;i<num;i++){
        unsigned int len;
        scanf("%u",&len);
        char *str = (char*)malloc((len+1)*sizeof(char));
        scanf("%s",str);
        int flag=1;
        for (unsigned int j=0;j<len;j++){
            if (str[j]!=str[len-j-1]){
                flag=0;
                break;
            }
        }
        if (flag==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        free(str);
    }
}