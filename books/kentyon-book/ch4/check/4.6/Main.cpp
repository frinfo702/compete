#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// time complexity: O(N)
class Solution {

public:
  bool can_solve(vector<int> &nums, int target) {
    memo.assign(nums.size(), vector<int>(target + 1, -1));
    return dfs(0, nums, target);
  };

private:
  vector<vector<int>> memo; // -1: yet calculated, 0: false, 1: true
  bool dfs(int idx, vector<int> &nums, int target) {
    if (target < 0)
      return false;
    if (idx == nums.size()) {
      return target == 0;
    }

    if (memo[idx][target] != -1) {
      return memo[idx][target];
    }

    /*
     1. nums[idx]を使わない -> 残りの要素でtargetを作れないといけない
     2. nums[idx]を使う -> 残りの要素でtarget - nums[idx]を作れないといけない
     */
    // 両方のパターンで失敗した場合のみfalse
    bool res =
        dfs(idx + 1, nums, target) || dfs(idx + 1, nums, target - nums[idx]);

    memo[idx][target] = res ? 1 : 0;

    return res;
  }
};

struct testCase {
  vector<int> nums;
  int target;
  bool expected;
};

void run_tests() {
  vector<testCase> test_cases = {{{1, 2, 3}, 6, true},
                                 {{1, 2, 3}, 5, true},
                                 {{1, 2, 3}, 7, false},
                                 {{4, 7, 10}, 11, true},
                                 {{4, 7, 10}, 3, false}};

  Solution solution;
  for (testCase test : test_cases) {
    if (solution.can_solve(test.nums, test.target) == test.expected) {
      cout << "test passed" << endl;
    } else {
      cout << "test failed" << endl;
    }
  }
}

int main() { run_tests(); }
