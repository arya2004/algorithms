// Brute force modular exponentiation (safe for small numbers)
function bruteForce(a, b, m) {
    let res = 1n;
    a = BigInt(a);
    b = BigInt(b);
    m = BigInt(m);
    for (let i = 0n; i < b; i++) {
        res = (res * a) % m;
    }
    return res;
}

// Fast modular exponentiation (binary exponentiation)
function fastExponentiation(a, b, m) {
    let res = 1n;
    a = BigInt(a) % BigInt(m);
    b = BigInt(b);
    m = BigInt(m);

    while (b > 0n) {
        if (b & 1n) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1n;
    }
    return res;
}

const a = 2n, b = 3n, m = 5n;
console.log("Brute Force:", bruteForce(a, b, m).toString());
console.log("Fast Exponentiation:", fastExponentiation(a, b, m).toString());
