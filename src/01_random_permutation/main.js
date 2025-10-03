// Function to generate a random permutation of numbers 1..63
function randomVector() {
    const v = [];
    for (let i = 1; i < 64; i++) {
        v.push(i);
    }

    // Shuffle the array using Fisher–Yates algorithm
    for (let i = v.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [v[i], v[j]] = [v[j], v[i]];
    }

    return v;
}

// Function to calculate maxUpdates
function maxUpdates(arr) {
    let count = 0;
    let max = arr[0];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
            count++;
        }
    }
    return count;
}

// Main simulation
async function main() {
    const itr = 100000;
    let cnt = 0;

    for (let i = 0; i < itr; i++) {
        const v = randomVector();
        const c = maxUpdates(v);
        cnt += c;
    }

    console.log("Average:", cnt / itr);
}

main();