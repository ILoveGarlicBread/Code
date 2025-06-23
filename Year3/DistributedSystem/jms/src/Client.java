import jakarta.jms.*;
import javax.naming.*;
import java.util.*;

public class Client {
  public static void main(String argv[]) throws Exception {
    Hashtable<String, String> properties = new Hashtable<String, String>();
    properties.put(Context.INITIAL_CONTEXT_FACTORY, "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
    properties.put(Context.PROVIDER_URL, "tcp://localhost:61616");
    Context context = new InitialContext(properties);
    TopicConnectionFactory connFactory = (TopicConnectionFactory) context.lookup("ConnectionFactory");
    TopicConnection conn = connFactory.createTopicConnection();
    TopicSession session = conn.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);
    Topic clientRequest = (Topic) context.lookup("dynamicTopics/clientRequest");
    Topic serverReply = (Topic) context.lookup("dynamicTopics/serverReply");
    TopicPublisher publisher = session.createPublisher(clientRequest);
    TopicSubscriber subscriber = session.createSubscriber(serverReply);
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < argv.length; i++) {
      sb.append(argv[i]);
      if (i < argv.length - 1)
        sb.append(" ");
    }
    conn.start();
    String messageToSend = sb.toString();
    TextMessage message = session.createTextMessage(messageToSend);
    System.out.println("Sending Message: " + message.getText());
    publisher.publish(message);
    TextMessage receiveMessage = (TextMessage) subscriber.receive(5000);
    System.out.println("Message Receive: " + receiveMessage.getText());

    session.close();
    conn.close();
  }
}
