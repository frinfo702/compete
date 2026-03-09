public class Main {

    static class Solution {

        public boolean canSolve(int[] nums, int target) {
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

    static class TestCase {

        int[] nums;
        int target;
        boolean expected;

        TestCase(int[] nums, int target, boolean expected) {
            this.nums = nums;
            this.target = target;
            this.expected = expected;
        }
    }

    static void runTests() {
        TestCase[] testCases = {
            new TestCase(new int[] { 1, 2, 3 }, 6, true),
            new TestCase(new int[] { 1, 2, 3 }, 5, true),
            new TestCase(new int[] { 1, 2, 3 }, 7, false),
            new TestCase(new int[] { 4, 7, 10 }, 11, true),
            new TestCase(new int[] { 4, 7, 10 }, 3, false),
        };

        Solution solution = new Solution();
        for (TestCase test : testCases) {
            assert (solution.canSolve(test.nums, test.target) == test.expected);
        }
    }

    public static void main(String[] args) {
        runTests();
        System.out.println("ok");
    }
}
