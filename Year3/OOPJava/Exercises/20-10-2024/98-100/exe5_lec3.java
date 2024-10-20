import java.util.Scanner;

public class ReverseWords {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = scanner.nextLine();

        String reversedString = reverseWordsInString(s);

        System.out.println("String with reversed words: " + reversedString);

        scanner.close();
    }

    public static String reverseWordsInString(String s) {
        String[] words = s.split("\\s+");

        StringBuilder reversed = new StringBuilder();

        for (int i = words.length - 1; i >= 0; i--) {
            reversed.append(words[i]);

            if (i != 0) {
                reversed.append(" ");
            }
        }

        return reversed.toString();
    }
}
