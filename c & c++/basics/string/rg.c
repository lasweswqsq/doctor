#include <stdio.h>
#include <stdlib.h>



int main() {
    int n, Q;
    unsigned int world[1001];
    int portal[4001];
    scanf("%d %d", &n, &Q);
    for (int i = 1; i <= n; i++) {
        scanf("%u", &world[i]);
    }
    for (int i = 1; i <= n; i++) {
        portal[i] = i;
    }
    for (int q = 0; q < Q; q++) {
        int world_id, portal_id;
        scanf("%d %d", &world_id, &portal_id);
        portal[world_id] = portal_id;
        int i = 1;
        int now = world_id;
        unsigned int s_current = world[world_id];
        int jingguode[1001] = {0};
        while (1) {
            int next = portal[now];
            if (next != world_id && jingguode[next] == 0) {
                jingguode[next] = 1;
                int k = i % 32;
                unsigned int shifted_s = (s_current << k) | (s_current >> (32 - k));
                world[next] ^= shifted_s;
                now = next;
                i++;
            }
            else {
                break;
            }
        }
    }
    unsigned int min_s = world[1];
    int min_x = 1;
    for (int x = 2; x <= n; x++) {
        if (world[x] < min_s || (world[x] == min_s && x < min_x)) {
            min_s = world[x];
            min_x = x;
        }
    }
    printf("%d\n%u\n", min_x, min_s);
    return 0;
}