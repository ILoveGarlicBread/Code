package test;

import util.*;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class SizeCompareImplTest {

  private SizeCompareImpl comparator = new SizeCompareImpl();

  @Test
  void testHasChanged_sameLengthSameContent() {
    assertFalse(comparator.hasChanged("apple", "apple"),
        "Should return false for strings with the same length (identical content).");
  }

  @Test
  void testHasChanged_sameLengthDifferentContent() {
    assertFalse(comparator.hasChanged("apple", "grape"),
        "Should return false for strings with the same length but different content.");
  }

  @Test
  void testHasChanged_differentLengths() {
    assertTrue(comparator.hasChanged("apple", "apples"),
        "Should return true for strings with different lengths.");
    assertTrue(comparator.hasChanged("apples", "apple"),
        "Should return true for strings with different lengths (reversed).");
  }

  @Test
  void testHasChanged_oneStringEmptyOtherNotEmpty() {
    assertTrue(comparator.hasChanged("", "a"),
        "Should return true when current is empty and snapshot is not.");
    assertTrue(comparator.hasChanged("a", ""),
        "Should return true when snapshot is empty and current is not.");
  }

  @Test
  void testHasChanged_bothStringsEmpty() {
    assertFalse(comparator.hasChanged("", ""),
        "Should return false when both strings are empty.");
  }

  @Test
  void testHasChanged_currentIsNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged(null, "abc"),
        "Should throw NullPointerException if current string is null.");
  }

  @Test
  void testHasChanged_snapshotIsNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged("abc", null),
        "Should throw NullPointerException if snapshot string is null.");
  }

  @Test
  void testHasChanged_bothStringsAreNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged(null, null),
        "Should throw NullPointerException if both strings are null.");
  }
}
