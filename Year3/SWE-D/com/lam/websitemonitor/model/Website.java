package model;

import java.util.Random;
import util.*;

public class Website {
    private String name;
    private String url;
    private String lastSnapshot = "";

    public Website(String name, String url) {
        this.url = url;
        this.name = name;
        WebsitesUtils.downloadWebPageContent(name, url);
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
