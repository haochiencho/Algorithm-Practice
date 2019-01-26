import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 1/26/19.
 */
class ArrayOfDoubledPairsTest {
    @Test
    void canReorderDoubled() {
        int[] A = {3, 1, 3, 6};

        assertFalse(ArrayOfDoubledPairs.canReorderDoubled(A));

        int[] A2 = {2, 1, 2, 6};

        assertFalse(ArrayOfDoubledPairs.canReorderDoubled(A2));

        int[] A3 = {4, -2, 2, -4};

        assertTrue(ArrayOfDoubledPairs.canReorderDoubled(A3));

        int[] A4 = {1, 2, 4, 16, 8, 4};

        assertFalse(ArrayOfDoubledPairs.canReorderDoubled(A4));
    }

}