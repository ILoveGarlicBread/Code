package test;

import util.*;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class HTMLCompareImplTest {

  private HTMLCompareImpl comparator = new HTMLCompareImpl();

  @Test
  void testHasChanged_identicalStrings() {
    assertFalse(comparator.hasChanged("hello world", "hello world"),
        "Should return false for identical strings.");
  }

  @Test
  void testHasChanged_differentContent() {
    assertTrue(comparator.hasChanged("hello world", "goodbye world"),
        "Should return true for different content.");
  }

  @Test
  void testHasChanged_differentCase() {
    assertTrue(comparator.hasChanged("Hello World", "hello world"),
        "Should return true for strings differing only in case.");
  }

  @Test
  void testHasChanged_differentLeadingTrailingWhitespace() {
    assertTrue(comparator.hasChanged(" hello world ", "hello world"),
        "Should return true for strings differing in leading/trailing whitespace.");
  }

  @Test
  void testHasChanged_differentInternalWhitespace() {
    assertTrue(comparator.hasChanged("hello\tworld", "hello world"),
        "Should return true for strings differing in internal whitespace.");
    assertTrue(comparator.hasChanged("hello\nworld", "hello world"),
        "Should return true for strings differing in internal newline characters.");
  }

  @Test
  void testHasChanged_oneStringEmptyOtherNotEmpty() {
    assertTrue(comparator.hasChanged("", "some content"),
        "Should return true when current is empty and snapshot is not.");
    assertTrue(comparator.hasChanged("some content", ""),
        "Should return true when snapshot is empty and current is not.");
  }

  @Test
  void testHasChanged_bothStringsEmpty() {
    assertFalse(comparator.hasChanged("", ""),
        "Should return false when both strings are empty.");
  }

  @Test
  void testHasChanged_currentIsNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged(null, "some content"),
        "Should throw NullPointerException if current string is null.");
  }

  @Test
  void testHasChanged_snapshotIsNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged("some content", null),
        "Should throw NullPointerException if snapshot string is null.");
  }

  @Test
  void testHasChanged_bothStringsAreNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged(null, null),
        "Should throw NullPointerException if both strings are null.");
  }
}
