#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int solution(vector<int> nums, int W) {
    int N = nums.size();

    // dp[i][w] := 先頭からi個までからいくつか選択して総和がwを作れるかどうか
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
      for (int w = 0; w <= W; w++) {
        dp[i + 1][w] = dp[i][w];

        if (w - nums[i] >= 0) {
          dp[i + 1][w] = dp[i][w] || dp[i][w - nums[i]];
        }
      }
    }

    int count = 0;
    for (int w = 1; w <= W; w++) {
      if (dp[N][w]) {
        count += 1;
      }
    }

    return count;
  }
};

struct testCase {
  vector<int> nums;
  int W;
  int expected;
};

void run_tests() {
  vector<testCase> testCases = {
      {{1, 2, 3}, 3, 3},     {{2}, 2, 1},        {{3, 5}, 4, 1},
      {{40, 30, 50}, 10, 0}, {{}, 5, 0},         {{1, 1, 1}, 3, 3},
      {{5, 5}, 5, 1},        {{2, 4, 6}, 12, 6}, {{1, 4, 8}, 10, 5},
      {{1}, 1, 1},           {{1, 2, 2}, 5, 5}};
  Solution s;
  for (testCase test : testCases) {
    if (s.solution(test.nums, test.W) == test.expected) {
      cout << "passed" << endl;
    } else {
      cout << "failed" << endl;
    }
  }
}

int main() {
  run_tests();
  cout << "tests done" << endl;
}
