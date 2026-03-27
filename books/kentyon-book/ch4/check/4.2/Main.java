import java.util.Arrays;

public class Main {

    // Time complexity: O(N)
    // Space complexity: O(N) + O(N) = O(N)
    static class Solution {

        int[] memo = new int[50];

        Solution() {
            Arrays.fill(memo, -1);
        }

        public int tribonacci(int N) {
            if (N == 0 || N == 1) {
                return 0;
            } else if (N == 2) {
                return 1;
            }

            if (memo[N] != -1) {
                return memo[N];
            }

            int result =
                tribonacci(N - 1) + tribonacci(N - 2) + tribonacci(N - 3);
            System.out.println(result);
            return memo[N] = result;
        }
    }

    static class TestCase {

        int n;
        int expected;

        TestCase(int n, int expected) {
            this.n = n;
            this.expected = expected;
        }
    }

    static void runTests() {
        Solution solution = new Solution();
        TestCase[] testCases = {
            new TestCase(3, 1),
            new TestCase(4, 2),
            new TestCase(9, 44),
        };

        for (TestCase test : testCases) {
            int actual = solution.tribonacci(test.n);
            assert (actual == test.expected);
        }
    }

    public static void main(String[] args) {
        runTests();
        System.out.println("ok");
    }
}
