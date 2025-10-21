fn brute_force(a: u64, b: u64, m: u64) -> u64 {
    let mut res = 1;
    for _ in 0..b {
        res = (res * a) % m;
    }
    res
}

fn fast_exponentiation(mut a: u64, mut b: u64, m: u64) -> u64 {
    let mut res = 1;
    a %= m;
    while b > 0 {
        if b & 1 == 1 {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    res
}

fn main() {
    let (a, b, m) = (2, 3, 5);
    println!("Brute Force: {}", brute_force(a, b, m));
    println!("Fast Exponentiation: {}", fast_exponentiation(a, b, m));
}
