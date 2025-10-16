function derangementIterative(n) {
    if (n === 0) return 1;
    if (n === 1) return 0;
    let dp = [1, 0];
    for (let i = 2; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

const n = parseInt(prompt("Enter n:"));
const result = derangementIterative(n);
console.log(`Number of derangements for ${n} elements is: ${result}`);
