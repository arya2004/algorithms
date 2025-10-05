#include <stdio.h>
#include <stdlib.h>

static long long josephus(long long n, long long k) {
    long long res = 0;
    for (long long i = 1; i <= n; ++i) res = (res + k) % i;
    return res + 1; /* 1-based position */
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n> >0 <k> >0\n", argv[0]);
        return 1;
    }
    long long n = atoll(argv[1]);
    long long k = atoll(argv[2]);
    if (n <= 0 || k <= 0) {
        fprintf(stderr, "n and k must be positive\n");
        return 1;
    }
    printf("%lld\n", josephus(n, k));
    return 0;
}