import jakarta.jms.*;
import javax.naming.*;
import java.util.*;
import model.*;
import java.lang.Thread;

public class Server implements MessageListener {
  private TopicSession session;
  private TopicPublisher publisher;
  private Map<String, Machine> machines;

  public Server(TopicSession session, TopicPublisher publisher, Map<String, Machine> machines) {
    this.session = session;
    this.publisher = publisher;
    this.machines = machines;
  }

  @Override
  public void onMessage(Message message) {
    try {
      TextMessage textMessage = (TextMessage) message;
      System.out.println("Incoming message: " + textMessage.getText());
      String reply = "";
      String[] input = textMessage.getText().split(" ");
      String action = input[0];
      String machineName = input[1];
      if (machines.containsKey(machineName)) {
        Machine machine = machines.get(machineName);
        switch (action) {
          case "add":
            String partName = input[2];
            int partNumber = Integer.parseInt(input[3]);
            int partPrice = Integer.parseInt(input[4]);
            machine.addPart(partName, partNumber, partPrice);
            reply = "Part named " + partName + " added successfully";
            break;
          case "query":
            reply = "All part names: nothing currently";
            break;
          case "search":
            partName = input[2];
            Part foundPart = machine.searchPart(partName);
            reply = "Part number: " + (String) foundPart.getName() + "\nPart price: "
                + String.valueOf(foundPart.getPrice());
            break;

        }
        System.out.println("Replying with message: " + reply);
        TextMessage replyMessage = session.createTextMessage(reply);
        publisher.publish(replyMessage);

      }

    } catch (Throwable e) {
      e.printStackTrace();
    }

  }

  public static void main(String argv[]) throws Exception {
    Map<String, Machine> machines = new HashMap<>();
    Machine car = new Machine("Car");
    Machine boat = new Machine("Boat");
    machines.put("Car", car);
    machines.put("Boat", boat);
    Hashtable<String, String> properties = new Hashtable<String, String>();
    properties.put(Context.INITIAL_CONTEXT_FACTORY, "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
    properties.put(Context.PROVIDER_URL, "tcp://localhost:61616");
    Context context = new InitialContext(properties);
    TopicConnectionFactory connFactory = (TopicConnectionFactory) context.lookup("ConnectionFactory");
    TopicConnection conn = connFactory.createTopicConnection();
    TopicSession session = conn.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);
    Topic clientRequest = (Topic) context.lookup("dynamicTopics/clientRequest");
    Topic serverReply = (Topic) context.lookup("dynamicTopics/serverReply");
    TopicSubscriber subscriber = session.createSubscriber(clientRequest);
    TopicPublisher publisher = session.createPublisher(serverReply);
    conn.start();
    System.out.println("Server Running...");
    Server server = new Server(session, publisher, machines);
    subscriber.setMessageListener(server);
    // while (true) {
    // Thread.sleep(50);
    // }

    // session.close();
    // conn.close();

  }
}
