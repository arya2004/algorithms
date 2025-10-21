package main

import "fmt"

// Brute force modular exponentiation
func bruteForce(a, b, m int64) int64 {
	res := int64(1)
	for i := int64(0); i < b; i++ {
		res = (res * a) % m
	}
	return res
}

// Fast modular exponentiation (binary exponentiation)
func fastExponentiation(a, b, m int64) int64 {
	res := int64(1)
	a = a % m
	for b > 0 {
		if b&1 == 1 {
			res = (res * a) % m
		}
		a = (a * a) % m
		b >>= 1
	}
	return res
}

func main() {
	a, b, m := int64(2), int64(3), int64(5)
	fmt.Println("Brute Force:", bruteForce(a, b, m))
	fmt.Println("Fast Exponentiation:", fastExponentiation(a, b, m))
}
