fn quick_sort(mut arr: Vec<i32>) -> Vec<i32> {
    if arr.len() <= 1 { return arr; }
    let pivot = arr[arr.len()/2];
    let left: Vec<i32> = arr.iter().cloned().filter(|&x| x < pivot).collect();
    let mid: Vec<i32> = arr.iter().cloned().filter(|&x| x == pivot).collect();
    let right: Vec<i32> = arr.iter().cloned().filter(|&x| x > pivot).collect();
    [quick_sort(left), mid, quick_sort(right)].concat()
}

fn merge_sort(arr: Vec<i32>) -> Vec<i32> {
    if arr.len() <= 1 { return arr; }
    let mid = arr.len()/2;
    let left = merge_sort(arr[..mid].to_vec());
    let right = merge_sort(arr[mid..].to_vec());
    merge(left, right)
}

fn merge(mut left: Vec<i32>, mut right: Vec<i32>) -> Vec<i32> {
    let mut res = Vec::new();
    while !left.is_empty() && !right.is_empty() {
        if left[0] <= right[0] { res.push(left.remove(0)); }
        else { res.push(right.remove(0)); }
    }
    res.extend(left); res.extend(right);
    res
}

fn main() {
    let nums: Vec<i32> = std::env::args().skip(1)
        .filter_map(|s| s.parse::<i32>().ok()).collect();
    println!("Quick Sort: {:?}", quick_sort(nums.clone()));
    println!("Merge Sort: {:?}", merge_sort(nums));
}
