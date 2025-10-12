function derangement(n) {
    if (n === 0) return 1;
    if (n === 1) return 0;
    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}

// Example usage:
const n = parseInt(prompt("Enter n:"));
const result = derangement(n);
console.log(`Number of derangements for ${n} elements is: ${result}`);
