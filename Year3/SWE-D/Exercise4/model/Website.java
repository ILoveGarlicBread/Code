package model;

import java.util.Random;

public class Website {
    private String url;
    private String lastSnapshot;

    public Website(String url) {
        this.url = url;
    }

    public boolean checkForUpdate() {
        boolean updated = new Random().nextBoolean();
        if (updated) {
            lastSnapshot = String.valueOf(System.currentTimeMillis());
        }
        return updated;
    }

    public String getUrl() {
        return url;
    }
}
