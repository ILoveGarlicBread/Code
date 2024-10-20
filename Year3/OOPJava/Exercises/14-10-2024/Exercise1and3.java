import java.util.Scanner;

public class Exercise1and3 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Input array size: ");
    int n = sc.nextInt();
    int[] arrayA = new int[n];
    int[] arrayB = new int[n];
    for (int i = 0; i < n; i++) {
      System.out.println("Input array element for array A: ");
      arrayA[i] = sc.nextInt();
    }

    for (int i = 0; i < n; i++) {
      System.out.println("Input array element for array B: ");
      arrayB[i] = sc.nextInt();
    }
    int[] arrayC = new int[n];
    for (int i = 0; i < n; i++) {
      arrayC[i] = arrayA[i] + arrayB[i];
    }

    System.out.println("Array C: ");
    for (int i = 0; i < n; i++) {
      System.out.print(arrayC[i] + " ");
    }
    sc.close();
  }
}
