import java.util.HashSet;
import java.util.Iterator;

public class JavaExercise3 {
  public static void main(String[] args) {
    if (args.length == 0) {
      System.out.println("No string received");
    } else {
      HashSet<String> cmdString = new HashSet<String>();
      for (int i = 0; i < args.length; i++) {
        cmdString.add(args[i]);
      }
      Iterator<String> output = cmdString.iterator();

      while (output.hasNext()) {
        System.out.println(output.next());
      }
    }

  }
}
