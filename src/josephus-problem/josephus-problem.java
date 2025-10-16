import java.util.Scanner;

public class JosephusProblem {
    // Function to solve Josephus problem
    public static int josephus(int n, int k) {
        if (n == 1) {
            return 1;
        } else {
            // Recursion formula: (josephus(n-1, k) + k - 1) % n + 1
            return (josephus(n - 1, k) + k - 1) % n + 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of people (n): ");
        int n = sc.nextInt();
        System.out.print("Enter step count (k): ");
        int k = sc.nextInt();

        int safePosition = josephus(n, k);
        System.out.println("Safe position is: " + safePosition);
    }
}
