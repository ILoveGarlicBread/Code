import java.util.Scanner;
public class Exercise1 {
  public static void main( String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Input a, b, c: ");
    double a = sc.nextDouble();
    double b = sc.nextDouble();
    double c = sc.nextDouble();
    double condition = Math.pow(b,2)-4*a*c;
    if (condition == 0){
      System.out.println("x = "+((-b)/(a*c)));
    }
    else if(condition > 0) {
      double result1 = (-b + Math.sqrt(Math.pow(b,2)-4*a*c))/(2*a);
      double result2 = (-b - Math.sqrt(Math.pow(b,2)-4*a*c))/(2*a);
      System.out.println("x = "+result1);
      System.out.println("x = "+result2);
    }
    else {
      System.out.println("Not real");
    }
    sc.close();
  }
}
