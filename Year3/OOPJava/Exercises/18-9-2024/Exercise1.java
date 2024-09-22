import java.util.Scanner;
public class Exercise1{
  public static void main(String []args){
    int a = 0;
    Scanner sc = new Scanner(System.in);
    while(a<1){
      System.out.print("Input a > 1: ");
      a = sc.nextInt();
    } 
    System.out.print("Input n: ");
    int n = sc.nextInt();
    int result = a>>n;
    System.out.print("Result: "+result);
    sc.close();
  }
}
