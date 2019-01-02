import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 1/1/19.
 */
class PowerOfTwoTest {
    @Test
    void isPowerOfTwo() {
        assertTrue(PowerOfTwo.isPowerOfTwo(1));
        assertTrue(PowerOfTwo.isPowerOfTwo(2));
        assertTrue(PowerOfTwo.isPowerOfTwo(16));
        assertTrue(PowerOfTwo.isPowerOfTwo(256));

        assertFalse(PowerOfTwo.isPowerOfTwo(0));
        assertFalse(PowerOfTwo.isPowerOfTwo(5));
        assertFalse(PowerOfTwo.isPowerOfTwo(117));
    }

}