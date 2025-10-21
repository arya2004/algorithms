public class ModularExponentiation {
    // Brute force modular exponentiation
    static long bruteForce(long a, long b, long m) {
        long res = 1;
        for (long i = 0; i < b; i++) {
            res = (res * a) % m;
        }
        return res;
    }

    // Fast modular exponentiation
    static long fastExponentiation(long a, long b, long m) {
        long res = 1;
        a = a % m;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
        long a = 2, b = 3, m = 5;
        System.out.println("Brute Force: " + bruteForce(a, b, m));
        System.out.println("Fast Exponentiation: " + fastExponentiation(a, b, m));
    }
}
