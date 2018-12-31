import org.junit.jupiter.api.Test;

import java.util.Arrays;
import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 12/30/18.
 */
class NextGreaterElementITest {
    @Test
    void nextGreaterElement() {
        int[] nums1 = {4, 1, 2};
        int[] nums2 = {1, 3, 4, 2};

        int[] result = NextGreaterElementI.nextGreaterElement(nums1, nums2);

        int[] expectedResult = {-1, 3, -1};
        assertTrue(Arrays.equals(expectedResult, result));
    }
}