package observer;

import java.util.ArrayList;
import java.util.List;

public interface Subject {
  void attachObserver(Observer o);

  void detachObserver(Observer o);

  void Notify(String message);
}
