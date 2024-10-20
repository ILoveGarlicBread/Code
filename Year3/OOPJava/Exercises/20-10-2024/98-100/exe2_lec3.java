import java.util.Scanner;

public class ReplaceSubstring {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the main string (s): ");
        String s = scanner.nextLine();

        System.out.print("Enter the substring to be replaced (s1): ");
        String s1 = scanner.nextLine();

        System.out.print("Enter the substring to replace with (s2): ");
        String s2 = scanner.nextLine();

        String modifiedString = s.replace(s1, s2);

        System.out.println("The modified string is: " + modifiedString);

        scanner.close();
    }
}
