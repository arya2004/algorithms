package main

import (
    "fmt"
)

// Function to calculate derangement
func derangement(n int) int {
    if n == 0 {
        return 1
    }
    if n == 1 {
        return 0
    }
    return (n - 1) * (derangement(n-1) + derangement(n-2))
}

func main() {
    var n int
    fmt.Print("Enter n: ")
    fmt.Scan(&n)

    result := derangement(n)
    fmt.Println("Number of derangements for", n, "elements is:", result)
}
