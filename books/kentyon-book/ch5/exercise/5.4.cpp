#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  const long long INF = 1 << 30;

public:
  bool solution(vector<int> &nums, int W, int k) {
    // 和wを作るのに必要な選択する最小の要素数
    vector<int> dp(W + 1, INF);
    dp[0] = 0;
    int N = nums.size();

    for (int num : nums) {
      for (int w = W; w >= num; w--) {
        dp[w] = min(dp[w], dp[w - num] + 1);
      }
    }

    return dp[W] <= k;
  }
};

struct testCase {
  vector<int> nums;
  int W;
  int k;
  bool expected;
};

void run_tests() {
  vector<testCase> testCases = {
      {{3, 5, 2}, 7, 2, true}, {{}, 1, 1, false},        {{}, 0, 0, true},
      {{1, 1, 2}, 4, 3, true}, {{1, 1, 2}, 4, 2, false},

  };

  Solution s;
  for (testCase test : testCases) {
    if (s.solution(test.nums, test.W, test.k) == test.expected) {
      cout << "passed" << endl;
    } else {
      cout << "failed" << endl;
    }
  }
}

int main() {
  run_tests();
  cout << "All test done" << endl;
}
