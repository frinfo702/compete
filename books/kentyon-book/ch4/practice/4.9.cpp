#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// time complexity: O(N)
class Solution {
public:
  bool can_solve(vector<int> &nums, int target) {
    return dfs(0, nums, target);
  };

private:
  bool dfs(int idx, vector<int> &nums, int target) {
    if (idx == nums.size()) {
      return target == 0;
    }

    /*
     1. nums[idx]を使わない -> 残りの要素でtargetを作れないといけない
     2. nums[idx]を使う -> 残りの要素でtarget - nums[idx]を作れないといけない
     */
    // 両方のパターンで失敗した場合のみfalse
    return dfs(idx + 1, nums, target) || dfs(idx + 1, nums, target - nums[idx]);
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
    assert(solution.can_solve(test.nums, test.target) == test.expected);
  }
}

int main() {
  run_tests();
  cout << "ok" << endl;
}
