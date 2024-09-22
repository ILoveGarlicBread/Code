import java.util.Scanner;
public class Exercise2 {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Input a number of days: ");
    int days = sc.nextInt();
    int lightSpeed = 186000;
    System.out.println("Light will travel "+days*lightSpeed+" miles");
    
    sc.close();
  }
}
