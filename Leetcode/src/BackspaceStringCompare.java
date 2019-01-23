import java.util.Stack;

/**
 * Created by briancho on 1/22/19.
 */
public class BackspaceStringCompare {
    public static boolean backspaceCompare(String S, String T) {
        return transformString(S).equals(transformString(T));
    }

    private static String transformString(String S) {
        Stack<Character> stack = new Stack<Character>();

        for (char c : S.toCharArray()) {
            if (c == '#') {
                if (!stack.isEmpty())
                    stack.pop();
            } else {
                stack.push(c);
            }
        }

        String output = "";

        for (int i = 0; i < stack.size(); i++) {
            output += stack.get(i);
        }

        return output;
    }
}
