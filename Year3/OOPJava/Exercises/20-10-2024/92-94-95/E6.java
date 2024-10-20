import java.util.Arrays;
import java.util.Scanner;

public class E6 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = sc.nextInt();
        int[] A = new int[n];

        System.out.println("Enter " + n + " integers:");
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }

        System.out.println("Array A: " + Arrays.toString(A));

        Arrays.sort(A);
        System.out.println("Sorted A (Ascending): " + Arrays.toString(A));

        Integer[] A_desc = Arrays.stream(A).boxed().toArray(Integer[]::new);
        Arrays.sort(A_desc, (a, b) -> b - a);
        System.out.println("Sorted A (Descending): " + Arrays.toString(A_desc));

        System.out.print("Prime numbers in A: ");
        for (int num : A) {
            if (isPrime(num)) {
                System.out.print(num + " ");
            }
        }
        System.out.println();

        int evenCount = 0, oddCount = 0;
        for (int num : A) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }

        int[] A1 = new int[evenCount];
        int[] A2 = new int[oddCount];
        evenCount = 0;
        oddCount = 0;

        for (int num : A) {
            if (num % 2 == 0) A1[evenCount++] = num;
            else A2[oddCount++] = num;
        }

        System.out.println("Sub array A1 (Even numbers): " + Arrays.toString(A1));
        System.out.println("Sub array A2 (Odd numbers): " + Arrays.toString(A2));
    sc.close();
    }

    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}

