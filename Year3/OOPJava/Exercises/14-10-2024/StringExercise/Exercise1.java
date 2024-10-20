import java.util.Scanner;

public class Exercise1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Input string s: ");
    String s = sc.nextLine();
    System.out.println("Input string s1: ");
    String s1 = sc.nextLine();
    if (s.contains(s1)) {
      System.out.println("s contains s1.");
    } else {
      System.out.println("s does not contain s1.");

    }
    sc.close();
  }

}
