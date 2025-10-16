#include <iostream>
using namespace std;

// Brute force modular exponentiation (safe for small numbers)
long long bruteForce(long long a, long long b, long long m) {
    long long res = 1;
    for (long long i = 0; i < b; i++) {
        res = (res * a) % m;
    }
    return res;
}

// Fast modular exponentiation (binary exponentiation)
long long fastExponentiation(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m; // reduce base initially
    while (b > 0) {
        if (b & 1) res = (res * a) % m; // multiply if odd
        a = (a * a) % m;                // square the base
        b >>= 1;                         // divide exponent by 2
    }
    return res;
}

int main() {
    long long a = 2;
    long long b = 3;
    long long m = 5;

    cout << "Brute Force: " << bruteForce(a, b, m) << endl;
    cout << "Fast Exponentiation: " << fastExponentiation(a, b, m) << endl;

    return 0;
}
