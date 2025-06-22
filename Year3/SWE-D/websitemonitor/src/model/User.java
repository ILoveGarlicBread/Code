package model;

import java.util.*;
import observer.*;
import observer.Observer;
import java.time.LocalDateTime;

public class User implements Observer {
  private String userId, name, email, phoneNumber;
  private List<Subscription> subscriptions = new ArrayList<>();

  public User(String userId, String name, String email, String phoneNumber) {
    this.userId = userId;
    this.name = name;
    this.email = email;
    this.phoneNumber = phoneNumber;
  }

  public void addSubscription(Subscription s) {
    subscriptions.add(s);
  }

  public List<Subscription> getSubscriptions() {
    return subscriptions;
  }

  @Override
  public void update(String websiteName, String message) {
    System.out.println("[" + LocalDateTime.now() + "]:" + message + websiteName);

  }
}
