#include <stdio.h>

unsigned int clshift(const unsigned int val) { return (val << 1) | (val >> 31); }

int main() {
    int worlds, events;
    scanf("%d %d", &worlds, &events);
    unsigned int world[1001];
    short p[1001];
    short lastChange[1001];
    for (int i = 1; i <= worlds; ++i) scanf("%u", world + i);
    for (int i = 0; i < 1001; ++i) p[i] = i, lastChange[i] = -1;
    for (int i = 0; i < events; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[x] = y;
        int current = y;
        unsigned int sin = world[x];
        while (current != x && lastChange[current] != i) {
            sin = clshift(sin);
            world[current] ^= sin;
            lastChange[current] = i;
            current = p[current];
        }
    }
    unsigned int minSin = world[1];
    int minWorld = 1;
    for (int i = 1; i <= worlds; ++i) if (world[i] < minSin) minSin = world[i], minWorld = i;
    printf("%d\n%u", minWorld, minSin);
    return 0;
}