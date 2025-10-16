#!/usr/bin/env python3
"""
Josephus problem: returns 1-based index of the survivor.
Usage:
  python josephus.py 7 3      -> 4
  echo "7 3" | python josephus.py
"""
import sys
from math import log2

def josephus(n: int, k: int) -> int:
    if k == 2:  # fast path
        p = 1 << int(log2(n))
        return 2 * (n - p) + 1
    res = 0  # 0-based
    for i in range(2, n + 1):
        res = (res + k) % i
    return res + 1  # 1-based

def main():
    if len(sys.argv) >= 3:
        n, k = int(sys.argv[1]), int(sys.argv[2])
    else:
        data = sys.stdin.read().strip().split()
        if len(data) != 2:
            print("Provide n k (e.g., '7 3') via args or stdin.", file=sys.stderr)
            sys.exit(1)
        n, k = map(int, data)
    if n <= 0 or k <= 0:
        print("n and k must be positive.", file=sys.stderr); sys.exit(1)
    print(josephus(n, k))

if __name__ == "__main__":
    main()
