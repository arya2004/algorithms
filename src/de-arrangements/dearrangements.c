#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

static unsigned long long derange_exact(unsigned n) {
    if (n == 0) return 1ULL;
    if (n == 1) return 0ULL;
    unsigned long long d0 = 1ULL;
    unsigned long long d1 = 0ULL;
    for (unsigned i = 2; i <= n; ++i) {
        unsigned long long next = (unsigned long long)(i - 1) * (d0 + d1);
        d0 = d1;
        d1 = next;
    }
    return d1;
}

static unsigned long long derange_mod(unsigned n, unsigned long long m) {
    if (m == 0ULL) return 0ULL;
    if (n == 0) return 1ULL % m;
    if (n == 1) return 0ULL;
    unsigned long long d0 = 1ULL % m;
    unsigned long long d1 = 0ULL;
    for (unsigned i = 2; i <= n; ++i) {
        unsigned long long next = ((i - 1) % m) * ((d0 + d1) % m) % m;
        d0 = d1 % m;
        d1 = next;
    }
    return d1 % m;
}

static int usage(const char *prog) {
    fprintf(stderr, "Usage: %s <n>=0 [mod>0]\n", prog);
    fprintf(stderr, "  (Exact for n<=20 without mod; use [mod] for large n.)\n");
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 3) return usage(argv[0]);

    char *end = NULL;
    errno = 0;
    long long nll = strtoll(argv[1], &end, 10);
    if (errno || *end != '\0' || nll < 0) return usage(argv[0]);
    unsigned n = (unsigned)nll;

    if (argc == 3) {
        errno = 0;
        unsigned long long mod = strtoull(argv[2], &end, 10);
        if (errno || *end != '\0' || mod == 0ULL) return usage(argv[0]);
        printf("%llu\n", derange_mod(n, mod));
        return 0;
    }

    if (n > 20) {
        fprintf(stderr, "n too large for exact 64-bit result (max 20). Use the 'mod' form.\n");
        return 1;
    }
    printf("%llu\n", derange_exact(n));
    return 0;
}
