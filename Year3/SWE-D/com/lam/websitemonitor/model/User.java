package model;

import java.util.*;

public class User {
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
}
