//There are a total of n courses you have to take, labeled from 0 to n-1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?


public class CourseSchedule {
    public static boolean canFinish (int numCourses, int[][] prerequisites) {
        boolean[][] prerequisitiesMatrix = new boolean[numCourses][numCourses];

        for (int i = 0; i < prerequisites.length; i++) {
            prerequisitiesMatrix[prerequisites[i][0]][prerequisites[i][1]] = true;
        }

        for (int i = 0; i < numCourses; i++) {
            boolean[] visited = new boolean[numCourses];

            if (detectCycle(i, numCourses, prerequisitiesMatrix, visited))
                return false;
        }

        return true;
    }

    private static boolean detectCycle (int course, int numCourses, boolean[][] prerequisitiesMatrix, boolean[] visited) {
        if (visited[course])
            return true;

        visited[course] = true;

        for (int i = 0; i < numCourses; i++) {
            if (prerequisitiesMatrix[course][i]) {
                if (detectCycle(i, numCourses, prerequisitiesMatrix, visited))
                    return true;

                visited[i] = false;
            }

        }

        return false;
    }
}
