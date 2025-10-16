#!/usr/bin/env python3
import sys, random

def fisher_yates(a, rng=random):
    # In-place, unbiased
    for i in range(len(a) - 1, 0, -1):
        j = rng.randrange(i + 1)   # 0..i inclusive
        a[i], a[j] = a[j], a[i]
    return a

def main():
    # Usage:
    #   python shuffle.py 1 2 3 4 5
    #   echo "1 2 3 4 5" | python shuffle.py
    data = sys.argv[1:] or sys.stdin.read().split()
    # optional: SEED=123 python shuffle.py ...
    seed = int(sys.environ.get("SEED")) if "SEED" in sys.environ else None
    if seed is not None:
        random.seed(seed)
    print(*fisher_yates([int(x) if x.lstrip("-").isdigit() else x for x in data]))

if __name__ == "__main__":
    main()
