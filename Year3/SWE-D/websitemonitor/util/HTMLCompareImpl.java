package util;
public class HTMLCompareImpl implements CompareMethod {
  @Override
  public boolean hasChanged(String current, String snapshot){
    return !current.equals(snapshot);
  }
}
