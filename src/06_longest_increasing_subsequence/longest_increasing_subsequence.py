# src/06_longest_increasing_subsequence/longest_increasing_subsequence.py

def longest_increasing_subsequence(nums):
    """
    Find the length of the longest increasing subsequence.
    
    Args:
        nums (List[int]): A list of integers.

    Returns:
        int: Length of the longest increasing subsequence.
    """
    if not nums:
        return 0

    tails = []  # stores smallest tail of increasing subsequences

    for num in nums:
        # Binary search manually
        left, right = 0, len(tails) - 1
        while left <= right:
            mid = (left + right) // 2
            if tails[mid] < num:
                left = mid + 1
            else:
                right = mid - 1

        # If left == len(tails), append new element
        if left == len(tails):
            tails.append(num)
        else:
            tails[left] = num

    return len(tails)


if __name__ == "__main__":
    # Example usage:
    arr = [10, 9, 2, 5, 3, 7, 101, 18]
    print("Input:", arr)
    print("Length of LIS:", longest_increasing_subsequence(arr))
