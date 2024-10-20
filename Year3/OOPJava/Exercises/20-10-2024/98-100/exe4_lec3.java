import java.util.Scanner;

public class StringDivider 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter an integer n: ");
        int n = scanner.nextInt();
        scanner.nextLine(); 

        System.out.print("Enter the string (s): ");
        String s = scanner.nextLine();


        divideIntoEqualParts(s, n);


        divideIntoNCharSubstrings(s, n);


        scanner.close();
    }

    // Task a: Method to divide the string into n equal parts
    public static void divideIntoEqualParts(String s, int n) 
    {
        int strLength = s.length();
        if (strLength % n != 0) 
        {
            System.out.println("The string cannot be divided into " + n + " equal parts.");
        } 
        else 
        {
            int partLength = strLength / n;
            System.out.println("The string divided into " + n + " equal parts:");
            
            for (int i = 0; i < strLength; i += partLength) 
            {
                System.out.println(s.substring(i, i + partLength));
            }
        }
    }

    // Task b: Method to divide the string into substrings of n characters
    public static void divideIntoNCharSubstrings(String s, int n) 
    {
        System.out.println("The string divided into substrings of " + n + " characters:");
        int strLength = s.length();
        
        for (int i = 0; i < strLength; i += n) 
        {
            if (i + n <= strLength) 
            {
                System.out.println(s.substring(i, i + n));
            } 
            else 
            {
                System.out.println(s.substring(i));
            }
        }
    }
}
