package test;

import util.*;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TextCompareImplTest {

  private TextCompareImpl comparator = new TextCompareImpl();

  @Test
  void testHasChanged_identicalTextContentHTML() {
    assertFalse(comparator.hasChanged("<html><body>Hello World</body></html>", "<html><body>Hello World</body></html>"),
        "Should return false for identical HTML leading to identical trimmed text.");
  }

  @Test
  void testHasChanged_differentTextContentHTML() {
    assertTrue(comparator.hasChanged("<html><body>New Content</body></html>", "<html><body>Old Content</body></html>"),
        "Should return true for HTML with different visible text content.");
  }

  @Test
  void testHasChanged_htmlStructureChangeSameText() {
    assertFalse(comparator.hasChanged("<div><span>Hello</span></div>", "<p>Hello</p>"),
        "Should return false if HTML structure changes but extracted text is the same.");
    assertFalse(comparator.hasChanged("<h1>Title</h1><p>Content</p>", "<div><h2>Title</h2><span>Content</span></div>"),
        "Should return false for complex HTML structure changes with same text.");
  }

  @Test
  void testHasChanged_whitespaceLineBreakDifferencesSameText() {
    assertFalse(
        comparator.hasChanged("<html><body>Hello \n World </body></html>", "<html><body>Hello World</body></html>"),
        "Should return false for HTML differing only in whitespace/line breaks that yield same trimmed text.");
    assertFalse(comparator.hasChanged(" <p>  Text  </p> ", "<p>Text</p>"),
        "Should return false for differing external/internal whitespace within tags.");
  }

  @Test
  void testHasChanged_differentCaseInTextContent() {
    assertTrue(comparator.hasChanged("<html><body>HELLO</body></html>", "<html><body>hello</body></html>"),
        "Should return true if only the case of the text content differs.");
  }

  @Test
  void testHasChanged_oneHtmlEmptyOtherWithText() {
    assertTrue(comparator.hasChanged("<html><body></body></html>", "<html><body>Text</body></html>"),
        "Should return true when one HTML is empty and other has text.");
    assertTrue(comparator.hasChanged("<html><body>Text</body></html>", "<html><body></body></html>"),
        "Should return true when one HTML has text and other is empty.");
  }

  @Test
  void testHasChanged_bothHtmlEmptyNoText() {
    assertFalse(comparator.hasChanged("<html><body></body></html>", "<div></div>"),
        "Should return false when both HTML strings have no extractable text.");
    assertFalse(comparator.hasChanged("<html></html>", ""), // Jsoup.parse("") -> document with no body text
        "Should return false when one is empty HTML and other is empty string.");
  }

  @Test
  void testHasChanged_plainTextInput() {
    assertFalse(comparator.hasChanged("Just plain text", "Just plain text"),
        "Should return false for identical plain text input.");
    assertTrue(comparator.hasChanged("Different text", "Original text"),
        "Should return true for different plain text input.");
  }

  @Test
  void testHasChanged_malformedHtml() {
    assertFalse(comparator.hasChanged("<html><body>Missing div", "<html><body>Missing div"),
        "Should handle malformed HTML without throwing an error if text content is same.");
    assertTrue(comparator.hasChanged("<html><body>Content1", "<html><body>Content2"),
        "Should handle malformed HTML and detect text change.");
  }

  @Test
  void testHasChanged_currentIsNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged(null, "<html><body>Content</body></html>"),
        "Should throw NullPointerException if current string is null.");
  }

  @Test
  void testHasChanged_snapshotIsNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged("<html><body>Content</body></html>", null),
        "Should throw NullPointerException if snapshot string is null.");
  }

  @Test
  void testHasChanged_bothStringsAreNull() {
    assertThrows(NullPointerException.class, () -> comparator.hasChanged(null, null),
        "Should throw NullPointerException if both strings are null.");
  }
}
