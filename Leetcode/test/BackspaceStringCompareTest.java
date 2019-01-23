import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 1/22/19.
 */
class BackspaceStringCompareTest {
    @Test
    void backspaceCompare() {
        String S = "ab#c";
        String T = "ad#c";

        assertTrue(BackspaceStringCompare.backspaceCompare(S, T));

        String S2 = "ab##";
        String T2 = "c#d#";

        assertTrue(BackspaceStringCompare.backspaceCompare(S2, T2));

        String S3 = "a#c";
        String T3 = "b";

        assertFalse(BackspaceStringCompare.backspaceCompare(S3, T3));
    }

}