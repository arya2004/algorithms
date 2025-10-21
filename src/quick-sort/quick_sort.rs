use std::time::Instant;
use rand::Rng;

/// Quick Sort functional implementation
/// Returns a new sorted vector without modifying the original
pub fn quick_sort(arr: &[i32]) -> Vec<i32> {
    // Base case: slices with 0 or 1 element are already sorted
    if arr.len() <= 1 {
        return arr.to_vec();
    }

    // Choose pivot (middle element)
    let pivot = arr[arr.len() / 2];

    // Partition slice into three parts
    let mut left = Vec::new();
    let mut middle = Vec::new();
    let mut right = Vec::new();

    for &element in arr {
        match element.cmp(&pivot) {
            std::cmp::Ordering::Less => left.push(element),
            std::cmp::Ordering::Equal => middle.push(element),
            std::cmp::Ordering::Greater => right.push(element),
        }
    }

    // Recursively sort left and right partitions
    let sorted_left = quick_sort(&left);
    let sorted_right = quick_sort(&right);

    // Combine results
    let mut result = Vec::with_capacity(arr.len());
    result.extend(sorted_left);
    result.extend(middle);
    result.extend(sorted_right);

    result
}

/// In-place Quick Sort implementation
/// Modifies the original vector
pub fn quick_sort_in_place(arr: &mut [i32]) {
    if arr.len() > 1 {
        quick_sort_in_place_recursive(arr, 0, arr.len() - 1);
    }
}

/// Internal recursive function for in-place quick sort
fn quick_sort_in_place_recursive(arr: &mut [i32], low: usize, high: usize) {
    if low < high {
        // Partition the slice
        let pivot_index = partition(arr, low, high);

        // Recursively sort elements before and after partition
        if pivot_index > 0 {
            quick_sort_in_place_recursive(arr, low, pivot_index - 1);
        }
        if pivot_index < high {
            quick_sort_in_place_recursive(arr, pivot_index + 1, high);
        }
    }
}

/// Partition function for in-place quick sort
fn partition(arr: &mut [i32], low: usize, high: usize) -> usize {
    // Choose rightmost element as pivot
    let pivot = arr[high];

    // Index of smaller element (indicates right position of pivot)
    let mut i = low.saturating_sub(1);

    for j in low..high {
        // If current element is smaller than or equal to pivot
        if arr[j] <= pivot {
            i += 1;
            arr.swap(i, j);
        }
    }

    // Place pivot in correct position
    arr.swap(i + 1, high);
    i + 1
}

/// Utility function to print a vector
fn print_vector(arr: &[i32], message: &str) {
    println!("{}: {:?}", message, arr);
}

/// Test function for quick sort implementations
fn test_quick_sort() {
    // Test data
    let test_array = vec![64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42];
    print_vector(&test_array, "Original array");

    // Test functional approach
    let sorted_array = quick_sort(&test_array);
    print_vector(&sorted_array, "Sorted array (functional)");

    // Test in-place approach
    let mut in_place_array = test_array.clone();
    quick_sort_in_place(&mut in_place_array);
    print_vector(&in_place_array, "Sorted array (in-place)");

    // Test with edge cases
    let edge_cases = vec![
        vec![],                    // Empty vector
        vec![1],                   // Single element
        vec![3, 1, 2],            // Three elements
        vec![5, 4, 3, 2, 1],      // Reverse sorted
        vec![1, 1, 1, 1],         // All same elements
        vec![1, 2, 3, 4, 5],      // Already sorted
    ];

    println!("\nTesting edge cases:");
    for (i, test_case) in edge_cases.iter().enumerate() {
        let result = quick_sort(test_case);
        println!("Case {}: {:?} -> {:?}", i + 1, test_case, result);
    }
}

/// Performance test function
fn performance_test() {
    let sizes = vec![100, 1000, 10000];
    let mut rng = rand::thread_rng();

    for size in sizes {
        // Generate random array
        let arr: Vec<i32> = (0..size).map(|_| rng.gen_range(0..1000)).collect();

        println!("\nTesting with {} elements:", size);

        // Test functional approach
        let start1 = Instant::now();
        let _ = quick_sort(&arr);
        let duration1 = start1.elapsed();
        println!("Functional approach: {:.2}ms", duration1.as_secs_f64() * 1000.0);

        // Test in-place approach
        let start2 = Instant::now();
        let mut arr_copy = arr.clone();
        quick_sort_in_place(&mut arr_copy);
        let duration2 = start2.elapsed();
        println!("In-place approach: {:.2}ms", duration2.as_secs_f64() * 1000.0);
    }
}

/// Benchmark function for performance testing
fn benchmark_quick_sort() {
    println!("\n=== Benchmark Results ===");
    
    let sizes = vec![100, 1000, 10000, 100000];
    let mut rng = rand::thread_rng();
    
    for size in sizes {
        let arr: Vec<i32> = (0..size).map(|_| rng.gen_range(0..1000)).collect();
        
        println!("\nArray size: {}", size);
        
        // Benchmark functional approach
        let start = Instant::now();
        for _ in 0..10 {
            let _ = quick_sort(&arr);
        }
        let avg_time = start.elapsed() / 10;
        println!("Functional (avg of 10 runs): {:?}", avg_time);
        
        // Benchmark in-place approach
        let start = Instant::now();
        for _ in 0..10 {
            let mut arr_copy = arr.clone();
            quick_sort_in_place(&mut arr_copy);
        }
        let avg_time = start.elapsed() / 10;
        println!("In-place (avg of 10 runs): {:?}", avg_time);
    }
}

/// Additional utility functions for Rust-specific features
pub mod utils {
    use super::*;

    /// Quick sort with custom comparison function
    pub fn quick_sort_by<F>(arr: &[i32], compare: F) -> Vec<i32>
    where
        F: Fn(&i32, &i32) -> std::cmp::Ordering,
    {
        if arr.len() <= 1 {
            return arr.to_vec();
        }

        let pivot = arr[arr.len() / 2];
        let mut left = Vec::new();
        let mut middle = Vec::new();
        let mut right = Vec::new();

        for &element in arr {
            match compare(&element, &pivot) {
                std::cmp::Ordering::Less => left.push(element),
                std::cmp::Ordering::Equal => middle.push(element),
                std::cmp::Ordering::Greater => right.push(element),
            }
        }

        let sorted_left = quick_sort_by(&left, &compare);
        let sorted_right = quick_sort_by(&right, &compare);

        let mut result = Vec::with_capacity(arr.len());
        result.extend(sorted_left);
        result.extend(middle);
        result.extend(sorted_right);

        result
    }

    /// Quick sort for generic types that implement Ord
    pub fn quick_sort_generic<T: Ord + Clone>(arr: &[T]) -> Vec<T> {
        if arr.len() <= 1 {
            return arr.to_vec();
        }

        let pivot = arr[arr.len() / 2].clone();
        let mut left = Vec::new();
        let mut middle = Vec::new();
        let mut right = Vec::new();

        for element in arr {
            match element.cmp(&pivot) {
                std::cmp::Ordering::Less => left.push(element.clone()),
                std::cmp::Ordering::Equal => middle.push(element.clone()),
                std::cmp::Ordering::Greater => right.push(element.clone()),
            }
        }

        let sorted_left = quick_sort_generic(&left);
        let sorted_right = quick_sort_generic(&right);

        let mut result = Vec::with_capacity(arr.len());
        result.extend(sorted_left);
        result.extend(middle);
        result.extend(sorted_right);

        result
    }
}

/// Main function
fn main() {
    println!("=== Quick Sort Implementation in Rust ===");
    test_quick_sort();
    performance_test();
    benchmark_quick_sort();
    
    // Demonstrate generic quick sort
    println!("\n=== Generic Quick Sort Demo ===");
    let numbers = vec![3, 1, 4, 1, 5, 9, 2, 6];
    let sorted_numbers = utils::quick_sort_generic(&numbers);
    println!("Numbers: {:?} -> {:?}", numbers, sorted_numbers);
    
    let strings = vec!["banana", "apple", "cherry", "date"];
    let sorted_strings = utils::quick_sort_generic(&strings);
    println!("Strings: {:?} -> {:?}", strings, sorted_strings);
}
