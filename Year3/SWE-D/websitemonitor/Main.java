import controller.Controller;
import java.util.concurrent.TimeUnit;

public class Main {
  public static void main(String[] args) {
    Controller controller = new Controller();

    controller.registerUser("U001", "Lam", "luongbaolam1303@gmai.com", "1234567890");
    controller.subscribe("U001", "weather", "https://www.accuweather.com", 15, "EMAIL");
    controller.subscribe("U001", "youtube", "https://www.youtube.com", 15, "SMS");
    while (true) {
      controller.checkWebsites();
      try {

        TimeUnit.SECONDS.sleep(2);
      } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
      }
    }
  }
}
