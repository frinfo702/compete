#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool partialSumWithoutLimitance(vector<int> nums, int W) {
    int N = nums.size();

    // dp[i][j] :=
    // nums[0]からnums[i-1]までを何回でも使って良いとして和jが作れるか
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= W; j++) {
        // nums[i-1]を1回も使わない場合
        dp[i][j] = dp[i - 1][j];

        // nums[i-1]を少なくとも1回使う場合
        if (j >= nums[i - 1] && dp[i][j - nums[i - 1]]) {
          dp[i][j] = true;
        }
      }
    }

    return dp[N][W];
  }
};

int main() {
  Solution sol;

  if (sol.partialSumWithoutLimitance({3, 5}, 11) == true) {
    cout << "Test1 OK\n";
  } else {
    cout << "Test1 NG\n";
  }

  if (sol.partialSumWithoutLimitance({4, 6}, 7) == false) {
    cout << "Test2 OK\n";
  } else {
    cout << "Test2 NG\n";
  }

  if (sol.partialSumWithoutLimitance({2}, 8) == true) {
    cout << "Test3 OK\n";
  } else {
    cout << "Test3 NG\n";
  }

  if (sol.partialSumWithoutLimitance({2}, 7) == false) {
    cout << "Test4 OK\n";
  } else {
    cout << "Test4 NG\n";
  }

  if (sol.partialSumWithoutLimitance({1, 7}, 0) == true) {
    cout << "Test5 OK\n";
  } else {
    cout << "Test5 NG\n";
  }

  return 0;
}
