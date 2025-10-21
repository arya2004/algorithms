def quick_sort(arr):
    """
    Quick Sort implementation in Python
    
    Args:
        arr: List of integers to be sorted
        
    Returns:
        Sorted list
    """
    if len(arr) <= 1:
        return arr
    
    # Choose pivot (middle element)
    pivot = arr[len(arr) // 2]
    
    # Partition array into three parts
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    # Recursively sort left and right partitions
    return quick_sort(left) + middle + quick_sort(right)


def quick_sort_in_place(arr, low=0, high=None):
    """
    In-place Quick Sort implementation
    
    Args:
        arr: List of integers to be sorted
        low: Starting index
        high: Ending index
    """
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Partition the array
        pivot_index = partition(arr, low, high)
        
        # Recursively sort elements before and after partition
        quick_sort_in_place(arr, low, pivot_index - 1)
        quick_sort_in_place(arr, pivot_index + 1, high)


def partition(arr, low, high):
    """
    Partition function for in-place quick sort
    
    Args:
        arr: Array to partition
        low: Starting index
        high: Ending index
        
    Returns:
        Index of pivot after partitioning
    """
    # Choose rightmost element as pivot
    pivot = arr[high]
    
    # Index of smaller element (indicates right position of pivot)
    i = low - 1
    
    for j in range(low, high):
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    # Place pivot in correct position
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def main():
    """Test the quick sort implementations"""
    # Test data
    test_array = [64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42]
    print("Original array:", test_array)
    
    # Test functional approach
    sorted_array = quick_sort(test_array.copy())
    print("Sorted array (functional):", sorted_array)
    
    # Test in-place approach
    in_place_array = test_array.copy()
    quick_sort_in_place(in_place_array)
    print("Sorted array (in-place):", in_place_array)
    
    # Test with edge cases
    edge_cases = [
        [],  # Empty array
        [1],  # Single element
        [3, 1, 2],  # Three elements
        [5, 4, 3, 2, 1],  # Reverse sorted
        [1, 1, 1, 1],  # All same elements
        [1, 2, 3, 4, 5]  # Already sorted
    ]
    
    print("\nTesting edge cases:")
    for i, case in enumerate(edge_cases):
        result = quick_sort(case.copy())
        print(f"Case {i+1}: {case} -> {result}")


if __name__ == "__main__":
    main()
