#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

static void usage(const char *argv0){
    fprintf(stderr, "Usage: %s <base> <exp>=nonneg <mod> (>0)\n", argv0);
}

static long long mod_norm(long long a, long long m){
    long long r = a % m;
    return (r < 0) ? r + m : r;
}

static long long modmul(long long a, long long b, long long m){
    __int128 x = ( __int128) a * ( __int128) b;
    x %= m;
    if (x < 0) x += m;
    return (long long)x;
}

static long long modpow(long long base, unsigned long long exp, long long mod){
    long long res = 1 % mod;
    long long b = mod_norm(base, mod);
    while (exp){
        if (exp & 1) res = modmul(res, b, mod);
        b = modmul(b, b, mod);
        exp >>= 1;
    }
    return res;
}

int main(int argc, char **argv){
    if (argc != 4){ usage(argv[0]); return 1; }

    char *e1=NULL, *e2=NULL, *e3=NULL;
    long long base = strtoll(argv[1], &e1, 10);
    unsigned long long exp = strtoull(argv[2], &e2, 10);
    long long mod = strtoll(argv[3], &e3, 10);

    if (*argv[2] == '-') { usage(argv[0]); return 1; }      // exp must be non-negative
    if (!*argv[1] || *e1 || !*argv[2] || *e2 || !*argv[3] || *e3 || mod <= 0){
        usage(argv[0]); return 1;
    }

    printf("%lld\n", modpow(base, exp, mod));
    return 0;
}
