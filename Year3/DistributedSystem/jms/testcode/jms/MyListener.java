import jakarta.jms.*;

public class MyListener implements MessageListener {
  @Override
  public void onMessage(Message message) {
    try {
      if (message instanceof TextMessage) {
        String text = ((TextMessage) message).getText();
        System.out.println("Received: " + text);
        // Process the message (e.g., invoke method, send reply)
      }
    } catch (JMSException e) {
      e.printStackTrace();
    }
  }
}
