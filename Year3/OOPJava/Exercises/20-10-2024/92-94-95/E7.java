import java.util.Scanner;

public class E7 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        System.out.print("Enter an integer n: ");
        int n = sc.nextInt();

        int[] fibonacci = new int[n];

        if (n >= 1) fibonacci[0] = 0;
        if (n >= 2) fibonacci[1] = 1;

        for (int i = 2; i < n; i++) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }

        System.out.print("Fibonacci series: ");
        for (int num : fibonacci) {
            System.out.print(num + " ");
        }
    sc.close();
    }
}

