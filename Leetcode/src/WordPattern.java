import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by briancho on 1/24/19.
 */
public class WordPattern {
    public static boolean wordPattern (String pattern, String str) {
        Map<Character, String> patternMap = new HashMap<Character, String>();

        List<String> strings = parseString(str);

        for (int i = 0; i < pattern.length(); i++) {
            if(patternMap.containsKey(pattern.charAt(i))) {
                if (!strings.get(i).equals(patternMap.get(pattern.charAt(i))))
                    return false;
            } else {
                patternMap.put(pattern.charAt(i), strings.get(i));
            }
        }

        return true;
    }

    private static List<String> parseString (String str) {
        List<String> output = new ArrayList<String>();

        String temp = "";

        for (char c : str.toCharArray()) {

            if (c == ' ') {
                output.add(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        if (!temp.equals("")) {
            output.add(temp);
        }

        return output;
    }
}
