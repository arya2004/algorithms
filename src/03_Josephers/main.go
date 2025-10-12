package main

import (
    "fmt"
)

// Function to solve Josephus problem
func josephus(n, k int) int {
    if n == 1 {
        return 1
    }
    return (josephus(n-1, k) + k - 1) % n + 1
}

func main() {
    var n, k int
    fmt.Print("Enter number of people (n): ")
    fmt.Scan(&n)
    fmt.Print("Enter step count (k): ")
    fmt.Scan(&k)

    safePosition := josephus(n, k)
    fmt.Println("Safe position is:", safePosition)
}
