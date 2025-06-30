package test;

import util.*;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class SizeCompareImplTest {

  private SizeCompareImpl comparator = new SizeCompareImpl();

  @Test
  void testHasChanged_sameLengthSameContent() {
    assertFalse(comparator.hasChanged("apple", "apple"),
        "False for strings with the same length ");
  }

  @Test
  void testHasChanged_sameLengthDifferentContent() {
    assertFalse(comparator.hasChanged("apple", "grape"),
        "False for strings with the same length but different content.");
  }

  @Test
  void testHasChanged_differentLengths() {
    assertTrue(comparator.hasChanged("apple", "apples"),
        "True for strings with different lengths.");
  }

}
