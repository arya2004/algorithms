/**
 * Quick Sort implementation in JavaScript
 * 
 * @param {number[]} arr - Array of numbers to be sorted
 * @returns {number[]} - Sorted array
 */
function quickSort(arr) {
    // Base case: arrays with 0 or 1 element are already sorted
    if (arr.length <= 1) {
        return arr;
    }
    
    // Choose pivot (middle element)
    const pivot = arr[Math.floor(arr.length / 2)];
    
    // Partition array into three parts
    const left = arr.filter(x => x < pivot);
    const middle = arr.filter(x => x === pivot);
    const right = arr.filter(x => x > pivot);
    
    // Recursively sort left and right partitions
    return [...quickSort(left), ...middle, ...quickSort(right)];
}

/**
 * In-place Quick Sort implementation
 * 
 * @param {number[]} arr - Array to sort
 * @param {number} low - Starting index
 * @param {number} high - Ending index
 */
function quickSortInPlace(arr, low = 0, high = arr.length - 1) {
    if (low < high) {
        // Partition the array
        const pivotIndex = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSortInPlace(arr, low, pivotIndex - 1);
        quickSortInPlace(arr, pivotIndex + 1, high);
    }
}

/**
 * Partition function for in-place quick sort
 * 
 * @param {number[]} arr - Array to partition
 * @param {number} low - Starting index
 * @param {number} high - Ending index
 * @returns {number} - Index of pivot after partitioning
 */
function partition(arr, low, high) {
    // Choose rightmost element as pivot
    const pivot = arr[high];
    
    // Index of smaller element (indicates right position of pivot)
    let i = low - 1;
    
    for (let j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            [arr[i], arr[j]] = [arr[j], arr[i]]; // Swap elements
        }
    }
    
    // Place pivot in correct position
    [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
    return i + 1;
}

/**
 * Utility function to test quick sort implementations
 */
function testQuickSort() {
    // Test data
    const testArray = [64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42];
    console.log("Original array:", testArray);
    
    // Test functional approach
    const sortedArray = quickSort([...testArray]);
    console.log("Sorted array (functional):", sortedArray);
    
    // Test in-place approach
    const inPlaceArray = [...testArray];
    quickSortInPlace(inPlaceArray);
    console.log("Sorted array (in-place):", inPlaceArray);
    
    // Test with edge cases
    const edgeCases = [
        [], // Empty array
        [1], // Single element
        [3, 1, 2], // Three elements
        [5, 4, 3, 2, 1], // Reverse sorted
        [1, 1, 1, 1], // All same elements
        [1, 2, 3, 4, 5] // Already sorted
    ];
    
    console.log("\nTesting edge cases:");
    edgeCases.forEach((testCase, index) => {
        const result = quickSort([...testCase]);
        console.log(`Case ${index + 1}: [${testCase}] -> [${result}]`);
    });
}

// Performance test function
function performanceTest() {
    const sizes = [100, 1000, 10000];
    
    sizes.forEach(size => {
        const arr = Array.from({ length: size }, () => Math.floor(Math.random() * 1000));
        
        console.log(`\nTesting with ${size} elements:`);
        
        // Test functional approach
        const start1 = performance.now();
        quickSort([...arr]);
        const end1 = performance.now();
        console.log(`Functional approach: ${(end1 - start1).toFixed(2)}ms`);
        
        // Test in-place approach
        const start2 = performance.now();
        quickSortInPlace([...arr]);
        const end2 = performance.now();
        console.log(`In-place approach: ${(end2 - start2).toFixed(2)}ms`);
    });
}

// Run tests if this file is executed directly
if (typeof require !== 'undefined' && require.main === module) {
    testQuickSort();
    performanceTest();
} else if (typeof window !== 'undefined') {
    // Browser environment
    console.log("Quick Sort JavaScript implementation loaded");
    console.log("Run testQuickSort() to test the implementation");
}

// Export functions for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        quickSort,
        quickSortInPlace,
        partition,
        testQuickSort,
        performanceTest
    };
}
