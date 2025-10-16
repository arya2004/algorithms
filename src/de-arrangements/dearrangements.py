import math
from itertools import permutations

def count_derangements(n):
    if n <= 1:
        return 0 if n == 1 else 1
    
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 0
    
    for i in range(2, n + 1):
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])
    
    return dp[n]

def is_derangement(perm):
    for i in range(len(perm)):
        if perm[i] == i + 1:
            return False
    return True

def generate_derangements(n):
    elements = list(range(1, n + 1))
    result = []
    for perm in permutations(elements):
        if is_derangement(perm):
            result.append(list(perm))
    return result

n = 4
derangements = generate_derangements(n)
count = count_derangements(n)

print(f"Derangements for n={n}:")
for d in derangements:
    print(d)
print(f"Count: {count}")
print(f"Probability: {count/math.factorial(n):.6f}")