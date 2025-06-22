package util;

import org.jsoup.Jsoup;

public class TextCompareImpl implements CompareMethod {
  public boolean hasChanged(String current, String snapshot) {
    String currentText = Jsoup.parse(current).text().trim();
    String savedText = Jsoup.parse(snapshot).text().trim();
    return !currentText.equals(savedText);
  }
}
