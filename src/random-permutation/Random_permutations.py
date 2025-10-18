import random
from typing import List, Optional, Iterable

def random_permutation(n: int, one_based: bool = True, rng: Optional[random.Random] = None) -> List[int]:
    """
    Return a uniformly random permutation of 1..n (if one_based=True)
    or 0..n-1 (if one_based=False), using the Fisher–Yates shuffle.

    Parameters
    ----------
    n : int
        Number of items (must be >= 0).
    one_based : bool
        If True (default), return permutation of 1..n; otherwise 0..n-1.
    rng : Optional[random.Random]
        Optional random.Random instance for reproducible results. If None,
        uses the module-level random.

    Returns
    -------
    List[int]
        A list containing a random permutation.
    """
    if n < 0:
        raise ValueError("n must be non-negative")

    # choose source list
    start = 1 if one_based else 0
    arr = [start + i for i in range(n)]

    if rng is None:
        rng = random

    # Fisher–Yates shuffle: for i from n-1 down to 1, swap arr[i] with arr[j] where j in [0..i]
    for i in range(n - 1, 0, -1):
        j = rng.randrange(i + 1)  # uniform integer in [0, i]
        arr[i], arr[j] = arr[j], arr[i]

    return arr

# ---- Example usage ----
if __name__ == "__main__":
    # Example: random permutation of 1..10
    print("Random permutation 1..10:", random_permutation(10))

    # Example: reproducible permutation using a seeded RNG
    seed_rng = random.Random(42)
    print("Reproducible 1..10:", random_permutation(10, rng=seed_rng))

    # Example: permutation of 0..4 (one_based=False)
    print("0-based permutation 0..4:", random_permutation(5, one_based=False))
