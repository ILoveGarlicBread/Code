public class JavaExercise1 {
  public static int factorial(int n) {
    if (n <= 2) {
      return n;

    }
    return n * factorial(n - 1);
  }

  public static void main(String[] args) {
    int n = 5;
    int result = factorial(n);
    System.out.println(result);

  }
}
