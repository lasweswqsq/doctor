#include<stdio.h>
int sum(int *a,int n){
    int fin = 0;
    for (int i=0;i<n;i++){
        fin = fin + a[i];
    }
    return fin;
}


int main(){
    const char c= 'fef';
    int list[30] = {1,2,3,4,5,6,7,8,9,10};
    int ans = sum(list,10);
    printf("%d",ans);
    return 0;
}