import java.util.Scanner;
public class Exercise3 {
  public static void main ( String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Input Celcius: ");
    int celcius = sc.nextInt();
    int farenheit = (celcius * 9 / 5) + 32;
    System.out.println("Farenheit is: "+farenheit);
    sc.close();
  }
}
