import java.util.*;

public class SortAlgorithms {

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            }
        }
        int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
        return i + 1;
    }

    public static void mergeSort(int[] arr) {
        if (arr.length < 2) return;
        int mid = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);
        mergeSort(left);
        mergeSort(right);
        merge(arr, left, right);
    }

    private static void merge(int[] arr, int[] left, int[] right) {
        int i=0, j=0, k=0;
        while (i < left.length && j < right.length)
            arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        while (i < left.length) arr[k++] = left[i++];
        while (j < right.length) arr[k++] = right[j++];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter numbers separated by space:");
        String[] parts = sc.nextLine().split("\\s+");
        int[] arr = Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();

        int[] qArr = Arrays.copyOf(arr, arr.length);
        quickSort(qArr, 0, qArr.length - 1);
        System.out.println("Quick Sort: " + Arrays.toString(qArr));

        int[] mArr = Arrays.copyOf(arr, arr.length);
        mergeSort(mArr);
        System.out.println("Merge Sort: " + Arrays.toString(mArr));
    }
}
