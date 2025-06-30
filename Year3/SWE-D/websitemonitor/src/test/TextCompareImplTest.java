package test;

import util.*;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TextCompareImplTest {

  private TextCompareImpl comparator = new TextCompareImpl();

  @Test
  void testHasChanged_identicalTextContentHTML() {
    assertFalse(comparator.hasChanged("<html><body>Hello World</body></html>", "<html><body>Hello World</body></html>"),
        "False for identical HTML leading to identical trimmed text");
  }

  @Test
  void testHasChanged_differentTextContentHTML() {
    assertTrue(comparator.hasChanged("<html><body>New Content</body></html>", "<html><body>Old Content</body></html>"),
        "True for HTML with different visible text content");
  }

  @Test
  void testHasChanged_htmlStructureChangeSameText() {
    assertFalse(comparator.hasChanged("<div><span>Hello</span></div>", "<p>Hello</p>"),
        "False if HTML structure changes but extracted text is the same");
  }

}
