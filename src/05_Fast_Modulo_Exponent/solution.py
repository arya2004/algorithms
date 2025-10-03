def fast_modulo_exponent(base, exp, mod):
    result = 1 % mod
    base %= mod
    while exp > 0:
        if exp & 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp >>= 1
    return result

base = int(input("Enter base: "))
exp = int(input("Enter exponent: "))
mod = int(input("Enter modulus: "))

answer = fast_modulo_exponent(base, exp, mod)
print(f"Answer: {answer}")