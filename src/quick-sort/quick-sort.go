package main

import (
	"fmt"
	"math/rand"
	"time"
)

// QuickSort functional implementation
// Returns a new sorted slice without modifying the original
func QuickSort(arr []int) []int {
	// Base case: slices with 0 or 1 element are already sorted
	if len(arr) <= 1 {
		return arr
	}

	// Choose pivot (middle element)
	pivot := arr[len(arr)/2]

	// Partition slice into three parts
	var left, middle, right []int
	for _, element := range arr {
		switch {
		case element < pivot:
			left = append(left, element)
		case element == pivot:
			middle = append(middle, element)
		default:
			right = append(right, element)
		}
	}

	// Recursively sort left and right partitions
	sortedLeft := QuickSort(left)
	sortedRight := QuickSort(right)

	// Combine results
	result := make([]int, 0, len(arr))
	result = append(result, sortedLeft...)
	result = append(result, middle...)
	result = append(result, sortedRight...)

	return result
}

// QuickSortInPlace in-place implementation
// Modifies the original slice
func QuickSortInPlace(arr []int) {
	if len(arr) > 1 {
		quickSortInPlace(arr, 0, len(arr)-1)
	}
}

// Internal recursive function for in-place quick sort
func quickSortInPlace(arr []int, low, high int) {
	if low < high {
		// Partition the slice
		pivotIndex := partition(arr, low, high)

		// Recursively sort elements before and after partition
		quickSortInPlace(arr, low, pivotIndex-1)
		quickSortInPlace(arr, pivotIndex+1, high)
	}
}

// Partition function for in-place quick sort
func partition(arr []int, low, high int) int {
	// Choose rightmost element as pivot
	pivot := arr[high]

	// Index of smaller element (indicates right position of pivot)
	i := low - 1

	for j := low; j < high; j++ {
		// If current element is smaller than or equal to pivot
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i] // Swap elements
		}
	}

	// Place pivot in correct position
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

// Utility function to print a slice
func printSlice(arr []int, message string) {
	fmt.Printf("%s: %v\n", message, arr)
}

// Utility function to create a copy of a slice
func copySlice(arr []int) []int {
	result := make([]int, len(arr))
	copy(result, arr)
	return result
}

// Test function for quick sort implementations
func testQuickSort() {
	// Test data
	testArray := []int{64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42}
	printSlice(testArray, "Original array")

	// Test functional approach
	sortedArray := QuickSort(testArray)
	printSlice(sortedArray, "Sorted array (functional)")

	// Test in-place approach
	inPlaceArray := copySlice(testArray)
	QuickSortInPlace(inPlaceArray)
	printSlice(inPlaceArray, "Sorted array (in-place)")

	// Test with edge cases
	edgeCases := [][]int{
		{},                    // Empty slice
		{1},                   // Single element
		{3, 1, 2},            // Three elements
		{5, 4, 3, 2, 1},      // Reverse sorted
		{1, 1, 1, 1},         // All same elements
		{1, 2, 3, 4, 5},      // Already sorted
	}

	fmt.Println("\nTesting edge cases:")
	for i, testCase := range edgeCases {
		result := QuickSort(testCase)
		fmt.Printf("Case %d: %v -> %v\n", i+1, testCase, result)
	}
}

// Performance test function
func performanceTest() {
	sizes := []int{100, 1000, 10000}

	for _, size := range sizes {
		// Generate random array
		arr := make([]int, size)
		for i := range arr {
			arr[i] = rand.Intn(1000)
		}

		fmt.Printf("\nTesting with %d elements:\n", size)

		// Test functional approach
		start1 := time.Now()
		QuickSort(arr)
		duration1 := time.Since(start1)
		fmt.Printf("Functional approach: %.2fms\n", float64(duration1.Nanoseconds())/1e6)

		// Test in-place approach
		start2 := time.Now()
		QuickSortInPlace(copySlice(arr))
		duration2 := time.Since(start2)
		fmt.Printf("In-place approach: %.2fms\n", float64(duration2.Nanoseconds())/1e6)
	}
}

// Benchmark function for performance testing
func benchmarkQuickSort() {
	fmt.Println("\n=== Benchmark Results ===")
	
	// Test with different array sizes
	sizes := []int{100, 1000, 10000, 100000}
	
	for _, size := range sizes {
		arr := make([]int, size)
		for i := range arr {
			arr[i] = rand.Intn(1000)
		}
		
		fmt.Printf("\nArray size: %d\n", size)
		
		// Benchmark functional approach
		start := time.Now()
		for i := 0; i < 10; i++ {
			QuickSort(copySlice(arr))
		}
		avgTime := time.Since(start) / 10
		fmt.Printf("Functional (avg of 10 runs): %v\n", avgTime)
		
		// Benchmark in-place approach
		start = time.Now()
		for i := 0; i < 10; i++ {
			QuickSortInPlace(copySlice(arr))
		}
		avgTime = time.Since(start) / 10
		fmt.Printf("In-place (avg of 10 runs): %v\n", avgTime)
	}
}

// Main function
func main() {
	// Seed random number generator
	rand.Seed(time.Now().UnixNano())
	
	fmt.Println("=== Quick Sort Implementation in Go ===")
	testQuickSort()
	performanceTest()
	benchmarkQuickSort()
}
