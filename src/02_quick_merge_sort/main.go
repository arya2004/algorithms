package main
import (
	"bufio"
	"fmt"
	"os"
)

func quickSort(arr []int) []int {
	if len(arr) <= 1 { return arr }
	pivot := arr[len(arr)/2]
	left, mid, right := []int{}, []int{}, []int{}
	for _, v := range arr {
		if v < pivot { left = append(left, v) } 
		else if v > pivot { right = append(right, v) } 
		else { mid = append(mid, v) }
	}
	return append(append(quickSort(left), mid...), quickSort(right)...)
}

func mergeSort(arr []int) []int {
	if len(arr) <= 1 { return arr }
	mid := len(arr)/2
	return merge(mergeSort(arr[:mid]), mergeSort(arr[mid:]))
}

func merge(a, b []int) []int {
	res := []int{}
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i] <= b[j] { res = append(res, a[i]); i++ }
		else { res = append(res, b[j]); j++ }
	}
	return append(append(res, a[i:]...), b[j:]...)
}

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Scan()
	var arr []int
	for _, s := range splitInts(in.Text()) { arr = append(arr, s) }
	fmt.Println("Quick Sort:", quickSort(arr))
	fmt.Println("Merge Sort:", mergeSort(arr))
}

func splitInts(line string) []int {
	var res []int; var n int
	for _, v := range line {
		if v == ' ' || v == '\n' { continue }
	}
	return res
}
