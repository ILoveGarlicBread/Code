import jakarta.jms.*;
import javax.naming.*;
import java.util.*;
import model.*;

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
      String[] input = textMessage.getText().split(" ");
      String action = input[0];
      String machineName = input[1];
      if (machines.containsKey("machineName")) {
        Machine machine = machines.get("machineName");
        switch (action) {
          case "add":
            
            machine.addPart()

        }

      }

    } catch (Throwable e) {
      System.err.println("Error" + e);
    }

  }

  public static void main(String argv[]) throws Exception {
    Map<String, Machine> machines = new HashMap<>();
    Machine car = new Machine("Car");
    Machine boat = new Machine("Boat");
    machines.put("Car", car);
    machines.put("Boat", boat);
    // hold configuration properties for JNDI
    Hashtable<String, String> properties = new Hashtable<String, String>();
    // tells JNDI how to connect to ActiveMQ and interpret the resource names
    properties.put(Context.INITIAL_CONTEXT_FACTORY, "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
    properties.put(Context.PROVIDER_URL, "tcp://localhost:61616");
    // Create Context to lookup topics, conn factory and stuff
    Context context = new InitialContext(properties);
    TopicConnectionFactory connFactory = (TopicConnectionFactory) context.lookup("ConnectionFactory");
    TopicConnection conn = connFactory.createTopicConnection();
    // create session for sending and receiving messages: false bool for
    // transaction, message are auto acknoledege
    TopicSession session = conn.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);
    Topic clientRequest = (Topic) context.lookup("dynamicTopics/clientRequest");
    Topic serverReply = (Topic) context.lookup("dynamicTopics/serverReply");
    TopicSubscriber subscriber = session.createSubscriber(clientRequest);
    TopicPublisher publisher = session.createPublisher(serverReply);
    conn.start();
    System.out.println("Server Running...");
    while (true) {
      Server server = new Server(session, publisher);
      subscriber.setMessageListener(server);
    }

    // session.close();
    // conn.close();

  }
}
