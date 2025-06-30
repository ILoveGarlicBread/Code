package test;

import util.*;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class HTMLCompareImplTest {

  private HTMLCompareImpl comparator = new HTMLCompareImpl();

  @Test
  void testHasChanged_identicalStrings() {
    assertFalse(comparator.hasChanged("hello world", "hello world"),
        "False for identical strings");
  }

  @Test
  void testHasChanged_differentContent() {
    assertTrue(comparator.hasChanged("hello world", "goodbye world"),
        "True for different content");
  }

  @Test
  void testHasChanged_differentCase() {
    assertTrue(comparator.hasChanged("Hello World", "hello world"),
        "True for strings differing only in case");
  }

}
