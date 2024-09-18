import static java.lang.Math.sqrt;
import static java.lang.Math.pow;
import java.util.Scanner;

public class Exercise8 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Input a and b: ");
    double a = sc.nextDouble();
    double b = sc.nextDouble();
    double c = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
    System.out.println("Hypotenuse length: " + c);
    sc.close();
  }
}
