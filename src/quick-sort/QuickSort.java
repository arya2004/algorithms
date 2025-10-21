/**
 * Quick Sort implementation in Java
 * 
 * This class provides both functional and in-place implementations of Quick Sort algorithm.
 * 
 * @author IOE Algorithms
 * @version 1.0
 */
public class QuickSort {
    
    /**
     * Functional Quick Sort implementation
     * 
     * @param arr Array of integers to be sorted
     * @return Sorted array
     */
    public static int[] quickSort(int[] arr) {
        // Base case: arrays with 0 or 1 element are already sorted
        if (arr.length <= 1) {
            return arr.clone();
        }
        
        // Choose pivot (middle element)
        int pivot = arr[arr.length / 2];
        
        // Count elements for each partition
        int leftCount = 0, middleCount = 0, rightCount = 0;
        for (int element : arr) {
            if (element < pivot) leftCount++;
            else if (element == pivot) middleCount++;
            else rightCount++;
        }
        
        // Create partition arrays
        int[] left = new int[leftCount];
        int[] middle = new int[middleCount];
        int[] right = new int[rightCount];
        
        // Fill partition arrays
        int leftIndex = 0, middleIndex = 0, rightIndex = 0;
        for (int element : arr) {
            if (element < pivot) {
                left[leftIndex++] = element;
            } else if (element == pivot) {
                middle[middleIndex++] = element;
            } else {
                right[rightIndex++] = element;
            }
        }
        
        // Recursively sort left and right partitions
        int[] sortedLeft = quickSort(left);
        int[] sortedRight = quickSort(right);
        
        // Combine results
        int[] result = new int[arr.length];
        System.arraycopy(sortedLeft, 0, result, 0, sortedLeft.length);
        System.arraycopy(middle, 0, result, sortedLeft.length, middle.length);
        System.arraycopy(sortedRight, 0, result, sortedLeft.length + middle.length, sortedRight.length);
        
        return result;
    }
    
    /**
     * In-place Quick Sort implementation
     * 
     * @param arr Array to sort
     * @param low Starting index
     * @param high Ending index
     */
    public static void quickSortInPlace(int[] arr, int low, int high) {
        if (low < high) {
            // Partition the array
            int pivotIndex = partition(arr, low, high);
            
            // Recursively sort elements before and after partition
            quickSortInPlace(arr, low, pivotIndex - 1);
            quickSortInPlace(arr, pivotIndex + 1, high);
        }
    }
    
    /**
     * Overloaded method for in-place quick sort with default parameters
     * 
     * @param arr Array to sort
     */
    public static void quickSortInPlace(int[] arr) {
        if (arr.length > 1) {
            quickSortInPlace(arr, 0, arr.length - 1);
        }
    }
    
    /**
     * Partition function for in-place quick sort
     * 
     * @param arr Array to partition
     * @param low Starting index
     * @param high Ending index
     * @return Index of pivot after partitioning
     */
    private static int partition(int[] arr, int low, int high) {
        // Choose rightmost element as pivot
        int pivot = arr[high];
        
        // Index of smaller element (indicates right position of pivot)
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        
        // Place pivot in correct position
        swap(arr, i + 1, high);
        return i + 1;
    }
    
    /**
     * Utility method to swap two elements in an array
     * 
     * @param arr Array containing elements to swap
     * @param i Index of first element
     * @param j Index of second element
     */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    /**
     * Utility method to print an array
     * 
     * @param arr Array to print
     * @param message Message to display before array
     */
    public static void printArray(int[] arr, String message) {
        System.out.print(message + ": [");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
    
    /**
     * Test method for quick sort implementations
     */
    public static void testQuickSort() {
        // Test data
        int[] testArray = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
        printArray(testArray, "Original array");
        
        // Test functional approach
        int[] sortedArray = quickSort(testArray);
        printArray(sortedArray, "Sorted array (functional)");
        
        // Test in-place approach
        int[] inPlaceArray = testArray.clone();
        quickSortInPlace(inPlaceArray);
        printArray(inPlaceArray, "Sorted array (in-place)");
        
        // Test with edge cases
        int[][] edgeCases = {
            {}, // Empty array
            {1}, // Single element
            {3, 1, 2}, // Three elements
            {5, 4, 3, 2, 1}, // Reverse sorted
            {1, 1, 1, 1}, // All same elements
            {1, 2, 3, 4, 5} // Already sorted
        };
        
        System.out.println("\nTesting edge cases:");
        for (int i = 0; i < edgeCases.length; i++) {
            int[] result = quickSort(edgeCases[i]);
            printArray(result, "Case " + (i + 1));
        }
    }
    
    /**
     * Performance test method
     */
    public static void performanceTest() {
        int[] sizes = {100, 1000, 10000};
        
        for (int size : sizes) {
            int[] arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = (int) (Math.random() * 1000);
            }
            
            System.out.println("\nTesting with " + size + " elements:");
            
            // Test functional approach
            long start1 = System.nanoTime();
            quickSort(arr);
            long end1 = System.nanoTime();
            System.out.println("Functional approach: " + (end1 - start1) / 1_000_000.0 + "ms");
            
            // Test in-place approach
            long start2 = System.nanoTime();
            quickSortInPlace(arr.clone());
            long end2 = System.nanoTime();
            System.out.println("In-place approach: " + (end2 - start2) / 1_000_000.0 + "ms");
        }
    }
    
    /**
     * Main method to run the program
     * 
     * @param args Command line arguments
     */
    public static void main(String[] args) {
        System.out.println("=== Quick Sort Implementation in Java ===");
        testQuickSort();
        performanceTest();
    }
}
