import java.util.Scanner;

public class Exercise7 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Input x, y , z: ");
    double x = sc.nextDouble();
    double y = sc.nextDouble();
    double z = sc.nextDouble();
    System.out.println(
        (x == y & x == z & y == z) ? "Is Equilateral" : (x == y | x == z | y == z) ? "Is Isosceles" : "Is nothing");
    sc.close();
  }
}
