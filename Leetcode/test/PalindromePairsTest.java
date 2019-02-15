import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 2/13/19.
 */
class PalindromePairsTest {
    @Test
    void palindromePairs() {
        String[] words = {"abcd", "dcba", "lls", "s", "sssll"};

        List<List<Integer>> result = PalindromePairs.palindromePairs(words);

        List<List<Integer>> expectResult = new ArrayList<>();

        List<Integer> tempList = makeTuple(0, 1);
        expectResult.add(tempList);

        tempList = makeTuple(1, 0);
        expectResult.add(tempList);

        tempList = makeTuple(2, 4);
        expectResult.add(tempList);

        tempList = makeTuple(3, 2);
        expectResult.add(tempList);

        assertTrue(expectResult.equals(result));
    }

    List<Integer> makeTuple (int a, int b) {
        return new ArrayList<Integer>() {
            {
                add(a);
                add(b);
            }
        };
    }



}