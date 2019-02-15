import java.util.ArrayList;
import java.util.List;

/**
 * Created by briancho on 2/13/19.
 */
public class PalindromePairs {
    public static List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> output = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i == j)
                    continue;

                if (isPalindrome(words[i] + words[j])) {
                    List<Integer> tuple = new ArrayList<>();

                    tuple.add(i);
                    tuple.add(j);

                    output.add(tuple);
                }
            }
        }

        return output;
    }

    private static boolean isPalindrome (String str) {
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - i - 1))
                return false;
        }

        return true;
    }
}
