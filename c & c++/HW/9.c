#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,Q;
    scanf("%d %d",&n,&Q);
    unsigned int world[1001];
    int world_id[4001];
    int transport_id[4001];
    for (int i = 1; i <= n; i++){
        scanf("%u",&world[i]);
    }
    for (int i = 1; i <= Q; i++){
        scanf("%d %d",&world_id[i],&transport_id[i]);
    }
    for (int i = 1; i <= Q; i++){
        //world[world_id[i]]=transport_id[i];
        int jingguode[1001]={0};
        int cishu = 0;
        unsigned int s_now = world[world_id[i]];
        int now = transport_id[i];
        while(1){
            cishu++;
            int next = world[now];
            if (next == now || jingguode[next] == 1){
                printf("break");
                break;
            }
            jingguode[next] = 1;
            int k = cishu%32;
            unsigned int shifted_s = (s_now << k) | (s_now  >> (32 - k));
            world[next] ^= shifted_s;
            now = next;
            printf("1");
        }   
    }
    unsigned int min_transport = world[1];
    int min_world = 1;
    for (int x = 2; x <= n; x++) {
        if (world[x] < min_transport || (world[x] == min_transport && x < min_world)) {
            min_transport = world[x];
            min_world = x;
        }
    }
    
    printf("%d\n%u\n", min_world, min_transport);
    
    return 0;
}