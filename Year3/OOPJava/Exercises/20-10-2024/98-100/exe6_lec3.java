import java.util.ArrayList;
import java.util.Scanner;

public class FindSubstrings {
    public static void main(String[] args) {
        String[] M = {"AAG", "TAC", "CAT", "TGA", "TAG"};

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the string (s): ");
        String s = scanner.nextLine();

        ArrayList<String> foundSubstrings = findSubstringsInM(s, M);

        if (foundSubstrings.isEmpty()) {
            System.out.println("No substrings in M found in the input string.");
        } else {
            System.out.println("Substrings in M found in the input string: " + foundSubstrings);
        }

        scanner.close();
    }

    public static ArrayList<String> findSubstringsInM(String s, String[] M) {
        ArrayList<String> foundSubstrings = new ArrayList<>();

        for (int i = 0; i <= s.length() - 3; i++) {
            String substring = s.substring(i, i + 3); 

            // Check if the substring is in M
            for (String element : M) {
                if (substring.equals(element)) {
                    foundSubstrings.add(substring); 
                }
            }
        }

        return foundSubstrings;
    }
}
