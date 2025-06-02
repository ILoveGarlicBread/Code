package model;

import java.time.LocalDateTime;

public class Subscription {
  private Website website;
  private int frequency; // minutes
  private NotificationChannel channel;
  private User user;

  enum NotificationChannel {
    EMAIL,
    SMS,
  }

  public Subscription(User user, Website website) {
    this.user = user;
    this.website = website;
    website.attachObserver(this.user);
  }

  public void cancel() {
    website.detachObserver(user);
  }

  // public Subscription(Website website, int frequency, String channelStr) {
  // this.website = website;
  // this.frequency = frequency;
  // this.channel = NotificationChannel.valueOf(channelStr);
  // }

  public Website getWebsite() {
    return website;
  }

  public NotificationChannel getChannel() {
    return channel;
  }
}
