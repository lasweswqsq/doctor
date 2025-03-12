#include <stdio.h>

enum {
    add = 0,
    sub = 1,
    mul = 2,
    div = 3,
    let = 4,
    out = 5
};

int main() {
    int count;
    scanf("%d", &count);
    unsigned int op, rx, ry, im;
    int registers[] = { 0, 0, 0, 0, 0, 0 };
    do {
        scanf("%x", &op);
        rx = (op >> 10) & 7;
        ry = (op >> 7) & 7;
        im = op & 0x7f;
        op = (op >> 13) & 7;
        switch (op) {
            case add:
                if (rx) registers[rx] += registers[ry];
                break;
            case sub:
                if (rx) registers[rx] -= registers[ry];
                break;
            case mul:
                if (rx) registers[rx] *= registers[ry];
                break;
            case div:
                if (rx) registers[rx] /= registers[ry];
                break;
            case let:
                if (rx) registers[rx] = im;
                break;
            case out:
                printf("x%d = %d\n", rx, registers[rx]);
                break;
            default:
                __builtin_unreachable();
                break;
        }
    } while (--count);
    return 0;
}