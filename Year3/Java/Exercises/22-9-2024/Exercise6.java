import java.util.Scanner;
import static java.lang.Math.PI;
import static java.lang.Math.pow;
public class Exercise6 {
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Input diameter: ");
    double diameter = sc.nextDouble();
    double area = PI * Math.pow(diameter/2, 2);
    double circumference = 2* PI *(diameter/2);
    System.out.println("Area: "+area);
    System.out.println("Circumference: "+circumference);

    sc.close();
  }
}
