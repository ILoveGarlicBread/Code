import jakarta.jms.*;
import javax.naming.*;
import java.util.*;

public class Client {
  public static void main(String argv[]) throws Exception {

    // Set Up
    StringBuilder sb = new StringBuilder();
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
    TopicSubscriber subscriber = session.createSubscriber(serverReply);
    TopicPublisher publisher = session.createPublisher(clientRequest);

    // Create String from Terminal
    for (int i = 0; i < argv.length; i++) {
      sb.append(argv[i]);
      if (i < argv.length - 1) {
        sb.append(" ");
      }
    }
    String input = sb.toString();
    System.out.println("Receive from CLI: " + input);
    TextMessage request = session.createTextMessage(input);

    System.out.println("Sending: " + request.getText());
    publisher.publish(request);
    TextMessage reply = (TextMessage) subscriber.receive();
    System.out.println("Received: " + reply.getText());
    session.close();
    conn.close();

  }
}
