package model;

import java.io.IOException;
import java.util.Random;
import util.*;

public class Website {
    private String name;
    private String url;

    public Website(String name, String url) {
        this.url = url;
        this.name = name;
        try {
            WebsitesUtils webUtils = new WebsitesUtils(name, url);
            webUtils.downloadWebPageContent();
        } catch (InterruptedException | IOException e) {
            System.out.println("Error: " + e);
        }
    }

    public boolean checkForUpdate() {
        WebsitesUtils webUtils = new WebsitesUtils(name, url);
        boolean updated = webUtils.compareWebPageContent();
        return updated;
    }

    public String getUrl() {
        return url;
    }
}
