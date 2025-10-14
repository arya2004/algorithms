def quick_merge_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    left_sorted = quick_merge_sort(left)
    right_sorted = quick_merge_sort(right)
    return merge(left_sorted + middle, right_sorted)
def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result
if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    print("Original:", arr)
    print("Sorted:", quick_merge_sort(arr))
