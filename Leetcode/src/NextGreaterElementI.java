//You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2. 
//
//The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number. 
// 
// All elements in nums1 and nums2 are unique. 
// The length of both nums1 and nums2 would not exceed 1000.  

public class NextGreaterElementI {
    public static int[] nextGreaterElement (int[] nums1, int[] nums2) {
        int[] output = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            output[i] = getNextGreaterElementFromIndex(findIndex(nums1[i], nums2), nums2);
        }

        return output;
    }
    
    private static int findIndex (int val, int[] nums2) {
        for (int i = 0; i < nums2.length; i++) {
            if (nums2[i] == val)
                return i;
        }
        return -1;
    }
    
    private static int getNextGreaterElementFromIndex (int index, int[] nums2) {
        for (int i = index + 1; i < nums2.length; i++) {
            if (nums2[i] > nums2[index])
            return nums2[i];
        }

        return -1;
    }
}
