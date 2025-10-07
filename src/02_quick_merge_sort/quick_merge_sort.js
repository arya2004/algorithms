#!/usr/bin/env node

function quickSort(arr) {
  if (arr.length <= 1) return arr;
  const pivot = arr[Math.floor(arr.length / 2)];
  const left = arr.filter(x => x < pivot);
  const mid = arr.filter(x => x === pivot);
  const right = arr.filter(x => x > pivot);
  return [...quickSort(left), ...mid, ...quickSort(right)];
}

function mergeSort(arr) {
  if (arr.length <= 1) return arr;
  const mid = Math.floor(arr.length / 2);
  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));
  return merge(left, right);
}

function merge(left, right) {
  const result = [];
  while (left.length && right.length)
    result.push(left[0] <= right[0] ? left.shift() : right.shift());
  return result.concat(left, right);
}

const nums = process.argv.slice(2).map(Number);
if (nums.length === 0) {
  console.error("Usage: node sort.js 5 2 9 1");
  process.exit(1);
}
console.log("Quick Sort:", quickSort(nums));
console.log("Merge Sort:", mergeSort(nums));
