import java.util.Scanner;
public class Exercise2and3{
  public static void main(String []args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Input Month: ");
    String month = sc.nextLine();
    System.out.print("Input Year: ");
    int year = sc.nextInt();
    boolean isLeap = false;
    if ((year % 4 == 0 & year %100 != 0) | year % 400 ==0){
      isLeap = true;
      System.out.println(year+" is a leap year.");
    }
    else{
      isLeap = false;
      System.out.println(year+" isn't a leap year.");
    }
    switch(month){
      case "January","March","May","July","August","October","December":
        System.out.println(month+" in "+year+" have "+"31 days");
        break;
      case "April","June","September","November":
        System.out.println(month+" in "+year+" have "+"30 days");
        break;
      case "February":
        if (isLeap){
          System.out.println(month+" in "+year+" have "+"28 days");
        }
        else{
          System.out.println(month+" in "+year+" have "+"29 days");
        }
        break;
      default:
        System.out.println("Invalid Input.");
    }
    
    sc.close();
  }
}
