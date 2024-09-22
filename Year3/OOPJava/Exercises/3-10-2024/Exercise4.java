import java.util.Scanner;
public class Exercise4{
  public static void main(String [] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Input an integer: ");
    int weekint = sc.nextInt();
    switch(weekint){
      case 2:
        System.out.println("Monday");
        break;
      case 3:
        System.out.println("Tuesday");
        break;
      case 4:
        System.out.println("Wednesday");
        break;
      case 5:
        System.out.println("Thursday");
        break;
      case 6:
        System.out.println("Friday");
        break;
      case 7:
        System.out.println("Saturday");
        break;
      case 8:
        System.out.println("Sunday");
        break;
      default:
        System.out.println("Error.");
        break;
    }
    sc.close();
  }
}
