public class Main {

    
    static class Solution {

        boolean canSolve(int[] nums, int target) {
            return dfs(0, nums, target);
        }

        private boolean dfs(int idx, int[] nums, int target) {
            if (idx == nums.length) {
                return target == 0;
            }

            return (
                dfs(idx + 1, nums, target) ||
                dfs(idx + 1, nums, target - nums[idx])
            );
        }
    }

    static class testCase {

        int[] nums;
        int target;
        boolean expected;

        testCase(int[] nums, int target, boolean expected) {
            this.nums = nums;
            this.target = target;
            this.expected = expected;
        }
    }

    static void runTests() {
        testCase[] testCases = {
            new testCase(new int[] { 1, 2, 3 }, 6, true),
            new testCase(new int[] { 1, 2, 3 }, 5, true),
            new testCase(new int[] { 1, 2, 3 }, 7, false),
            new testCase(new int[] { 4, 7, 10 }, 11, true),
            new testCase(new int[] { 4, 7, 10 }, 3, false),
        };

        Solution solution = new Solution();
        for (testCase test : testCases) {
            if (solution.canSolve(test.nums, test.target) == test.expected) {
                System.err.println("test case passed");
            } else {
                System.err.println("test case failed");
            }
        }
    }

    public static void main(String[] args) {
        runTests();
        System.err.println("All tests passed");
    }
}
