import java.util.*;

/**
 * Created by briancho on 1/26/19.
 */
public class ArrayOfDoubledPairs {
    public static boolean canReorderDoubled (int[] A) {
        List<Integer> positiveArr = new ArrayList<>();
        List<Integer> negativeArr = new ArrayList<>();

        Map<Integer, Integer> positiveMap = new HashMap<>();
        Map<Integer, Integer> negativeMap = new HashMap<>();

        for (int el : A) {
            if (el >= 0) {
                if (el != 0)
                    positiveArr.add(el);

                if (positiveMap.containsKey(el))
                    positiveMap.put(el, positiveMap.get(el) + 1);
                else
                    positiveMap.put(el, 1);
            } else {
                el *= -1;

                negativeArr.add(el);
                if (negativeMap.containsKey(el))
                    negativeMap.put(el, negativeMap.get(el) + 1);
                else
                    negativeMap.put(el, 1);
            }
        }

        return canReorderDoubledHelper(positiveArr, positiveMap) && canReorderDoubledHelper(negativeArr, negativeMap)
                && (positiveMap.containsKey(0) ? positiveMap.get(0) % 2 == 0 : true);
    }

    private static boolean canReorderDoubledHelper (List<Integer> nums, Map<Integer, Integer> map) {
        Collections.sort(nums);

        for (int el : nums) {
            int count = map.get(el);

            if (count > 0) {
                if (!map.containsKey(el * 2))
                    return false;
                else if (count > map.get(el * 2))
                    return false;
                else {
                    map.put(el, 0);
                    map.put(el * 2, map.get(el * 2) - count);
                }

            }
        }

        return true;
    }
}
