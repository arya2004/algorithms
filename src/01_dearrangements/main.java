import java.util.Scanner;

public class Derangement {
    // Function to calculate derangement using recursion
    public static long derangement(int n) {
        if (n == 0) return 1;
        if (n == 1) return 0;
        return (n - 1) * (derangement(n - 1) + derangement(n - 2));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = sc.nextInt();

        long result = derangement(n);
        System.out.println("Number of derangements for " + n + " elements is: " + result);
    }
}
