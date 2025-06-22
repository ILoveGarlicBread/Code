package model;

import java.io.IOException;
import java.util.Random;
import util.*;
import observer.*;
import java.util.ArrayList;
import java.util.List;

public class Website implements Subject {
    private String name;
    private String url;
    private final List<Observer> observers = new ArrayList<Observer>();

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
        CompareMethod method = new HTMLCompareImpl();
        try {
            boolean updated = webUtils.compareWebPageContent(method);
            Notify("Content changed.");
            return updated;
        } catch (InterruptedException | IOException e) {
            System.out.println("Error " + e);
        }
        return false;
    }

    public void attachObserver(Observer o) {
        this.observers.add(o);
    }

    public void detachObserver(Observer o) {
        this.observers.remove(o);
    }

    public void Notify(String message) {
        for (Observer o : observers) {
            o.update(name, message);
        }
    }

    public String getUrl() {
        return url;
    }
}
