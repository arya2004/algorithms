# Searching Algorithms Implementation in Python
# 1️⃣ Linear Search
def linear_search(arr, target):
    """
    Returns the index of the target if found, else -1.
    Time Complexity: O(n)
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


# 2️⃣ Binary Search (Iterative)
def binary_search_iterative(arr, target):
    """
    Works only on sorted arrays.
    Time Complexity: O(log n)
    """
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


# 3️⃣ Binary Search (Recursive)
def binary_search_recursive(arr, target, low=0, high=None):
    """
    Recursive version of binary search.
    Time Complexity: O(log n)
    """
    if high is None:
        high = len(arr) - 1

    if low > high:
        return -1

    mid = (low + high) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, high)
    else:
        return binary_search_recursive(arr, target, low, mid - 1)


# 4️⃣ Jump Search
import math
def jump_search(arr, target):
    """
    Works only on sorted arrays.
    Time Complexity: O(√n)
    """
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0

    while prev < n and arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    while prev < n and arr[prev] < target:
        prev += 1
        if prev == min(step, n):
            return -1

    if prev < n and arr[prev] == target:
        return prev
    return -1


# 5️⃣ Interpolation Search
def interpolation_search(arr, target):
    """
    Works well for uniformly distributed sorted arrays.
    Time Complexity: O(log log n) on average.
    """
    low, high = 0, len(arr) - 1
    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            return low if arr[low] == target else -1

        pos = low + ((high - low) * (target - arr[low])) // (arr[high] - arr[low])
        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1
    return -1


# 6️⃣ Exponential Search
def exponential_search(arr, target):
    """
    Works only on sorted arrays.
    Time Complexity: O(log n)
    """
    if arr[0] == target:
        return 0

    i = 1
    while i < len(arr) and arr[i] <= target:
        i *= 2

    return binary_search_recursive(arr, target, i // 2, min(i, len(arr) - 1))


# 🧪 Example Run
if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 13

    print("Linear Search:", linear_search(arr, target))
    print("Binary Search (Iterative):", binary_search_iterative(arr, target))
    print("Binary Search (Recursive):", binary_search_recursive(arr, target))
    print("Jump Search:", jump_search(arr, target))
    print("Interpolation Search:", interpolation_search(arr, target))
    print("Exponential Search:", exponential_search(arr, target))
