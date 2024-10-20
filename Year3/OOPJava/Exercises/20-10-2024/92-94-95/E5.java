import java.util.Scanner;
public class E5{
  static void array_input(int [][] array, int row, int column){
    Scanner sc = new Scanner(System.in);
    for(int i= 0; i<row; i++){
      for(int j=0; j<column; j++){
        System.out.println("Input element " + i + " " + j);
        array[i][j]= sc.nextInt();
      }
      
    }
  }
    static void array_display(int [][] array, int row, int column){
    for(int i= 0; i<row; i++){
      for(int j=0; j<column; j++){
        System.out.print(array[i][j]+ " ");
      }
      System.out.println();
      
    }
  }

public static void main(String[] args){

    Scanner sc= new Scanner(System.in);
    System.out.println("Input array row size: ");
    int row = sc.nextInt();
    System.out.println("Input array column size: ");
    int column = sc.nextInt();
    int [][] ArrayA= new int[row][column];
    int [][] ArrayB= new int[row][column];
    int [][] ArrayAdd= new int[row][column];
    int [][] ArraySub= new int[row][column];
    
    System.out.println("Input elements for array A");
    array_input(ArrayA, row, column);
    System.out.println("Input elements for array B");
    array_input(ArrayB, row, column);
    for( int i = 0; i<row;i++){
      for( int j = 0; j<column;j++){
        ArrayAdd[i][j]= ArrayA[i][j]+ArrayB[i][j];
      }
    }
    for( int i = 0; i<row;i++){
      for( int j = 0; j<column;j++){
        ArraySub[i][j]= ArrayA[i][j]-ArrayB[i][j];
      }
    }
    array_display(ArrayAdd, row, column);
    array_display(ArraySub, row, column);
    sc.close();
  }
}
