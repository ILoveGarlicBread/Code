
import java.util.Scanner;
public class Exercise4 {
  public static void main ( String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Input Farenheit: ");
    int farenheit = sc.nextInt();
    int celcius = (farenheit - 32) * 5 / 9;
    System.out.println("Celcius is: "+celcius);
    sc.close();
  }
}
