package util;

public class HTMLCompareImpl implements CompareMethod {
  @Override
  public boolean hasChanged(String current, String snapshot) {
    if (snapshot == null) {
      throw new NullPointerException("Snapshot string cannot be null for HTML comparison");
    }
    return !current.equals(snapshot);
  }
}
