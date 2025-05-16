package model;

import java.time.LocalDateTime;

public class Notification {
  private Subscription subscription;
  private String message;
  private LocalDateTime timestamp;

  public Notification(Subscription subscription, String message) {
    this.subscription = subscription;
    this.message = message;
    this.timestamp = LocalDateTime.now();
  }

  public void send() {
    System.out.println("[" + timestamp + "] Notification (" +
        subscription.getChannel() + "): " + message +
        " for " + subscription.getWebsite().getUrl());
  }
}
