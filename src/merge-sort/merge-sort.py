# Quick Merge Sort implementation in Python
def quick_merge_sort(arr):
    if len(arr) <= 1:
        return arr
    # Quick sort partition
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    # Recursively sort left and right, then merge
    return merge(quick_merge_sort(left), middle, quick_merge_sort(right))

def merge(left, middle, right):
    # Merge left, middle, and right lists
    return left + middle + right

if __name__ == "__main__":
    arr = [38, 27, 43, 3, 9, 82, 10]
    print("Original array:", arr)
    sorted_arr = quick_merge_sort(arr)
    print("Sorted array:", sorted_arr)
def merge(left, right):
    merged = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged


def quick_merge_sort(arr, threshold=10):
    if len(arr) <= 1:
        return arr

    
    if len(arr) <= threshold:
        mid = len(arr) // 2
        left = quick_merge_sort(arr[:mid], threshold)
        right = quick_merge_sort(arr[mid:], threshold)
        return merge(left, right)

    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_merge_sort(left, threshold) + middle + quick_merge_sort(right, threshold)


if __name__ == "__main__":
    data = [34, 7, 23, 32, 5, 62, 32, 23, 12]
    print("Original:", data)
    sorted_data = quick_merge_sort(data)
    print("Sorted:  ", sorted_data)
