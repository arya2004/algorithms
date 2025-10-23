def find_nth_min_max(list1, n):
    # Check if n is valid
    if n <= 0 or n > len(list1):
        return f"There are not enough elements for the {n}th min/max."

    min_value = float('inf')  # Start with positive infinity for min
    max_value = float('-inf')  # Start with negative infinity for max

    # Find nth minimum
    for _ in range(n):  # Loop for nth minimum
        min_value = float('inf')  # Reset to positive infinity for each loop
        for num in list1:
            if num < min_value:
                min_value = num
        list1.remove(min_value)  # Remove the smallest number after finding it

    # Find nth maximum
    for _ in range(n):  # Loop for nth maximum
        max_value = float('-inf')  # Reset to negative infinity for each loop
        for num in list1:
            if num > max_value:
                max_value = num
        list1.remove(max_value)  # Remove the largest number after finding it

    return min_value, max_value


# Example usage with user input:
list1 = [1, 2, 3, 66, 56, 45, 4, 404, 45]
n = int(input("Enter the value of n (for nth min and nth max): "))  # Take n as input

nth_min, nth_max = find_nth_min_max(list1, n)
print(f"The {n}th minimum value is: {nth_min}")
print(f"The {n}th maximum value is: {nth_max}")
