#include <stdint.h>
#include <string.h>

#define M (UINT8_MAX + 1)

uint8_t table_max(int n, uint8_t *x) {
    uint8_t v[M];

    memset(v, 0, M);

    for (int i = 0; i < n; i++)
        v[x[i]] = 1;

    for (int i = M-1; i >= 0; i--)
        if (v[i])
            return i;

    // only if n = 0
    return 0;
}

uint8_t pair_max(int n, uint8_t *x) {
    uint8_t max = x[0];

    if (n % 2 == 0 && x[1] > max)
        max = x[1];

    //  technically unrolling by 2
    for (int i = 2 - (n % 2); i < n; i += 2) {
        uint8_t p = x[i] > x[i+1] ? x[i] : x[i+1];
        if (max < p)
            max = p;
    }

    return max;
}

uint8_t baseline_max(int n, uint8_t *x) {
    uint8_t max = *x++;

    for (int i = 1; i < n; i++) {
        if (max < *x)
            max = *x;

        x++;
    }

    return max;
}
