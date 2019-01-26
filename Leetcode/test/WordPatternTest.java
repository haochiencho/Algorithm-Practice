import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 1/24/19.
 */
class WordPatternTest {
    @Test
    void wordPattern() {
        String pattern = "abba";
        String str = "dog cat cat dog";

        assertTrue(WordPattern.wordPattern(pattern, str));

        String pattern2 = "abba";
        String str2 = "dog cat cat fish";

        assertFalse(WordPattern.wordPattern(pattern2, str2));
    }
}