/**
 * Created by briancho on 1/1/19.
 */
public class PowerOfTwo {
    public static boolean isPowerOfTwo (int n) {
        return countOnes(n) == 1;
    }

    private static int countOnes (int n) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            count += n & 1;
            n = n >> 1;
        }

        return count;
    }
}
