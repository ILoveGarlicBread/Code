import java.util.LinkedHashSet;
import java.util.Scanner;

public class RemoveDuplicates {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the string (s): ");
        String s = scanner.nextLine();

        String result = removeDuplicates(s);

        System.out.println("String after removing duplicates: " + result);
        
        scanner.close();
    }

    public static String removeDuplicates(String s) {
        LinkedHashSet<Character> set = new LinkedHashSet<>();

        for (char c : s.toCharArray()) {
            set.add(c);
        }

        StringBuilder result = new StringBuilder();
        for (char c : set) {
            result.append(c);
        }

        return result.toString();
    }
}
