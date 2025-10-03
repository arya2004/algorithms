#include <bits/stdc++.h>
using namespace std;

// Fast modular exponentiation: computes (base^exp) % mod
long long solution(long long base, long long exp, long long mod) {
    long long res = 1 % mod;  // in case mod = 1
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {

    long long base, exp, mod;
    cout << "Enter base, exponent, modulus: ";
    cin >> base >> exp >> mod;

    cout << "Answer: " << solution(base, exp, mod) << "\n";
    return 0;
}
