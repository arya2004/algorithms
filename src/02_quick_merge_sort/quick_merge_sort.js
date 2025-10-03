function merge(left, right) {
    const merged = [];
    let i = 0, j = 0;

    while (i < left.length && j < right.length) {
        if (left[i] <= right[j]) {
            merged.push(left[i]);
            i++;
        } else {
            merged.push(right[j]);
            j++;
        }
    }

    while (i < left.length) {
        merged.push(left[i]);
        i++;
    }

    while (j < right.length) {
        merged.push(right[j]);
        j++;
    }

    return merged;
}

function quickMergeSort(arr, threshold = 10) {
    if (arr.length <= 1) {
        return arr;
    }

    if (arr.length <= threshold) {
        const mid = Math.floor(arr.length / 2);
        const left = quickMergeSort(arr.slice(0, mid), threshold);
        const right = quickMergeSort(arr.slice(mid), threshold);
        return merge(left, right);
    }

    const pivot = arr[Math.floor(arr.length / 2)];
    const left = arr.filter(x => x < pivot);
    const middle = arr.filter(x => x === pivot);
    const right = arr.filter(x => x > pivot);

    return [
        ...quickMergeSort(left, threshold),
        ...middle,
        ...quickMergeSort(right, threshold)
    ];
}

if (require.main === module) {
    const data = [34, 7, 23, 32, 5, 62, 32, 23, 12];
    console.log("Original:", data);
    console.log("Sorted:  ", quickMergeSort(data));
}