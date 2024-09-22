import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Input a string: ");
    String s = sc.nextLine();
    System.out.println("You entered string " + s);
    System.out.println("Input a integer: ");
    int i = sc.nextInt();
    System.out.println("You entered integer " + i);
    System.out.println("Input a float: ");
    float f = sc.nextFloat();
    System.out.println("You entered float " + f);
    sc.close();
  }
}
