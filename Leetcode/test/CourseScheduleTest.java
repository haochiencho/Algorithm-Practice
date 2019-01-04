import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

/**
 * Created by briancho on 1/3/19.
 */
class CourseScheduleTest {
    @Test
    void canFinish() {
        int numCourses = 2;
        int[][] prerequisities = {{1, 0}};

        assertTrue(CourseSchedule.canFinish(numCourses, prerequisities));

        int numCourses2 = 2;
        int[][] prerequisities2 = {{1, 0}, {0, 1}};

        assertFalse(CourseSchedule.canFinish(numCourses2, prerequisities2));

        int numCourses3 = 3;
        int[][] prerequisities3 = {{0, 1}, {0, 2}, {1, 2}};

        assertTrue(CourseSchedule.canFinish(numCourses3, prerequisities3));
    }

}