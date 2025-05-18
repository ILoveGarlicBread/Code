package model;

import java.time.LocalDateTime;

public class Subscription {
  private static int counter = 0;
  private final String subscriptionId;
  private Website website;
  private int frequency; // minutes
  private NotificationChannel channel;

  enum NotificationChannel {
    EMAIL,
    SMS,
  }

  private LocalDateTime lastChecked;

  public Subscription(Website website, int frequency, String channelStr) {
    this.subscriptionId = "" + (++counter);
    this.website = website;
    this.frequency = frequency;
    this.channel = NotificationChannel.valueOf(channelStr);
    this.lastChecked = LocalDateTime.now();
  }

  public Website getWebsite() {
    return website;
  }

  public NotificationChannel getChannel() {
    return channel;
  }
}
