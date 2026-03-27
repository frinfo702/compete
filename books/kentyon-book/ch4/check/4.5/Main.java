public class Main {

    static class Solution {

        public int shichigosan(int N) {
            return dfs(0, N, false, false, false);
        }

        private int dfs(
            long current,
            int N,
            boolean has3,
            boolean has5,
            boolean has7
        ) {
            int count = 0;
            if (current > N) {
                return 0;
            }

            if (has3 && has5 && has7) {
                count += 1;
            }

            // 新しい桁を追加
            count += dfs(current * 10 + 3, N, true, has5, has7);
            count += dfs(current * 10 + 5, N, has3, true, has7);
            count += dfs(current * 10 + 7, N, has3, has5, true);

            return count;
        }
    }

    static class TestCase {

        int N;
        int expected;

        TestCase(int N, int expected) {
            this.N = N;
            this.expected = expected;
        }
    }

    static void runTests() {
        Solution solution = new Solution();
        TestCase[] testCases = {
            new TestCase(1, 0),
            new TestCase(10, 0),
            new TestCase(100, 0),
            new TestCase(356, 0),
            new TestCase(358, 1),
            new TestCase(374, 1),
            new TestCase(375, 2),
            new TestCase(575, 4),
            new TestCase(3600, 13),
            new TestCase(999999999, 26484),
        };

        int passed = 0;
        for (TestCase test : testCases) {
            int actual = solution.shichigosan(test.N);
            if (actual != test.expected) {
                System.out.println(
                    "FAILED: N=" +
                        test.N +
                        ", expected=" +
                        test.expected +
                        ", actual=" +
                        actual
                );
            } else {
                passed++;
            }
        }

        System.out.println("passed " + passed + " / " + testCases.length);
    }

    public static void main(String[] args) {
        runTests();
        System.out.println("ok");
    }
}
