public class JavaExercise4 {
  public class printer extends Thread {
    private final int num;

    public printer(int inputNum) {
      this.num = inputNum;
    }

    public void run() {
      for (int i = 0; i < 5; i++) {
        if (i == 2 || i == 5) {
          Thread.sleep(3000);
        }
      }
    }
  }
}
