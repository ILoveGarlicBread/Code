import jakarta.jms.*;
import javax.naming.*;
import java.util.Hashtable;

public class ReceiverP {
   public static void main(String argv[]) throws Exception {

      Hashtable<String, String> properties = new Hashtable<String, String>();
	  properties.put(Context.INITIAL_CONTEXT_FACTORY, 
	                     "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
	  properties.put(Context.PROVIDER_URL, "tcp://localhost:61616");

      Context context = new InitialContext(properties);

      QueueConnectionFactory connFactory = 
          (QueueConnectionFactory)context.lookup("ConnectionFactory");
      
      QueueConnection conn = connFactory.createQueueConnection();
      QueueSession session = conn.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
      Queue q = (Queue) context.lookup("dynamicQueues/queue1");

 
      QueueReceiver receiver = session.createReceiver(q);
      conn.start();
      Message m = receiver.receive();
      if(m instanceof TextMessage) {
         TextMessage txt = (TextMessage) m;
         System.out.println("Message Received: "+txt.getText());
      }
      session.close();
      conn.close();
   }
}