package util;

public class SizeCompareImpl implements CompareMethod {
  @Override
  public boolean hasChanged(String current, String snapshot) {
    return !(current.length() == snapshot.length());
  }
}
