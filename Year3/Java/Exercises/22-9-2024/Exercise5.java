import java.util.Scanner;
public class Exercise5 {
  public static void main( String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Input a, b, h: ");
    float a = sc.nextFloat();
    float b = sc.nextFloat();
    float h = sc.nextFloat();
    System.out.println("Area: "+(a+b)/ 2 * h);
    sc.close();
  }
}
