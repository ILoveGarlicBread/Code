package controller;

import model.*;

import java.util.*;

public class Controller {
  private Map<String, User> users = new HashMap<>();

  public void registerUser(String id, String name, String email, String phone) {
    users.put(id, new User(id, name, email, phone));
  }

  public void subscribe(String userId, String url, int frequency, String channelStr) {
    User user = users.get(userId);
    if (user == null)
      return;

    Website website = new Website(url);
    Subscription subscription = new Subscription(website, frequency, channelStr);
    user.addSubscription(subscription);
  }

  public void checkWebsites() {
    for (User user : users.values()) {
      for (Subscription s : user.getSubscriptions()) {
        if (s.getWebsite().checkForUpdate()) {
          Notification notification = new Notification(s, "Website Updated!");
          notification.send();
        }
      }
    }
  }
}
