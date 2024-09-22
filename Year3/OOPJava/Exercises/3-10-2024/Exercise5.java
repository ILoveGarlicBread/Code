import java.util.Scanner;
public class Exercise5{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Input day and month: ");
    int day = sc.nextInt();
    int month=sc.nextInt();

    switch (day){
      case 1: System.out.print("The first");break;
      case 2: System.out.print("The second");break;
      case 3: System.out.print("The third");break;
      case 4: System.out.print("The fourth");break;
      case 5: System.out.print("The fifth");break;
      case 6: System.out.print("The sixth");break;
      case 7: System.out.print("The seventh");break;
      case 8: System.out.print("The eighth");break;
      case 9: System.out.print("The ninth");break;
      case 10: System.out.print("The tenth");break;
      case 11: System.out.print("The eleventh");break;
      case 12: System.out.print("The twelth");break;
      case 13: System.out.print("The thirteenth");break;
      case 14: System.out.print("The fourteenth");break;
      case 15: System.out.print("The fifteenth");break;
      case 16: System.out.print("The sixteenth");break;
      case 17: System.out.print("The seventeenth");break;
      case 18: System.out.print("The eighteenth");break;
      case 19: System.out.print("The nineteenth");break;
      case 20: System.out.print("The twenty");break;
      case 21: System.out.print("The twenty first");break;
      case 22: System.out.print("The twenty second");break;
      case 23: System.out.print("The twenty third");break;
      case 24: System.out.print("The twenty fourth");break;
      case 25: System.out.print("The twenty fifth");break;
      case 26: System.out.print("The twenty sixth");break;
      case 27: System.out.print("The twenty seventh");break;
      case 28: System.out.print("The twenty eighth");break;
      case 29: System.out.print("The twenty ninth");break;
      case 30: System.out.print("The thirty");break;
      case 31: System.out.print("The thirty first");break;
      default: System.out.println("Invalid date");break;
    }

    switch(month){
      case 1: System.out.print(" of January");break;
      case 2: System.out.print(" of February");break;
      case 3: System.out.print(" of March");break;
      case 4: System.out.print(" of April");break;
      case 5: System.out.print(" of May");break;
      case 6: System.out.print(" of June");break;
      case 7: System.out.print(" of July");break;
      case 8: System.out.print(" of August");break;
      case 9: System.out.print(" of September");break;
      case 10: System.out.print(" of October");break;
      case 11: System.out.print(" of November");break;
      case 12: System.out.print(" of December");break;
      default: System.out.println("Invalid month");break;
    }
    sc.close();
  }
}
