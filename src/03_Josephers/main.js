function josephus(n, k) {
    if (n === 1) {
        return 1;
    } else {
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
}

// Example usage:
const n = parseInt(prompt("Enter number of people (n):"));
const k = parseInt(prompt("Enter step count (k):"));

const safePosition = josephus(n, k);
console.log("Safe position is:", safePosition);
alert("Safe position is: " + safePosition);