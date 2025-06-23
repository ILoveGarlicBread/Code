import jakarta.jms.*;
import javax.naming.*;
import java.util.*;
import model.*;

public class Server implements MessageListener {
  private Map<String, Machine> machines;
  private TopicSession session;
  private TopicPublisher publisher;

  public Server(Map<String, Machine> machines, TopicSession session, TopicPublisher publisher) {
    this.machines = machines;
    this.session = session;
    this.publisher = publisher;
  }

  @Override
  public void onMessage(Message message) {
    System.out.println("onMessage called!");
    try {
      if (message instanceof TextMessage) {
        String testtext = ((TextMessage) message).getText();
        System.out.println("Received message text: " + testtext);
        String[] text = ((TextMessage) message).getText().split(" ");
        String command = text[0];
        String machineName = text[1];
        String reply = "";
        if (machines.containsKey(machineName)) {
          Machine machine = machines.get(machineName);
          switch (command) {
            case "add":
              String partName = text[2];
              int partNumber = Integer.parseInt(text[3]);
              int partPrice = Integer.parseInt(text[4]);
              machine.addPart(partName, partNumber, partPrice);
              reply = "Part added successfully.";
              break;
            case "query":
              reply = machine.queryPartNames();
              break;
            case "search":
              partName = text[2];
              Part foundPart = machine.searchPart(partName);
              String foundPartNum = String.valueOf(foundPart.getNumber());
              String foundPartPrice = String.valueOf(foundPart.getPrice());
              reply = "Part Number: " + foundPartNum + "\n" + "Part Price: " + foundPartPrice;
              break;

          }
          System.out.println("Sending: " + reply);
          TextMessage textMessage = session.createTextMessage(reply);
          publisher.publish(textMessage);

        }
      }
    } catch (JMSException e) {
      e.printStackTrace();
    }
  }

  public static void main(String argv[]) throws Exception {
    System.out.println("Server running");
    Machine car = new Machine("Car");
    Machine boat = new Machine("Boat");
    HashMap<String, Machine> machines = new HashMap<>();
    machines.put("Car", car);
    machines.put("Boat", boat);
    Hashtable<String, String> properties = new Hashtable<String, String>();
    properties.put(Context.INITIAL_CONTEXT_FACTORY, "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
    properties.put(Context.PROVIDER_URL, "tcp://localhost:61616");
    Context context = new InitialContext(properties);
    TopicConnectionFactory connFactory = (TopicConnectionFactory) context.lookup("ConnectionFactory");
    TopicConnection conn = connFactory.createTopicConnection();
    conn.start();
    TopicSession session = conn.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);
    Topic clientRequest = (Topic) context.lookup("dynamicTopics/clientRequest");
    Topic serverReply = (Topic) context.lookup("dynamicTopics/serverReply");
    TopicSubscriber subscriber = session.createSubscriber(clientRequest);
    TopicPublisher publisher = session.createPublisher(serverReply);
    Server server = new Server(machines, session, publisher);
    subscriber.setMessageListener(server);
    // TextMessage message = (TextMessage) subscriber.receive();
    // System.out.println("Message Receive: " + message.getText());

    synchronized (Server.class) {
      Server.class.wait();
    }
    session.close();
    conn.close();
  }
}
