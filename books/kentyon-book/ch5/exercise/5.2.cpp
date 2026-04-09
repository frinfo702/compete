#include <vector>
class Solution {
public:
  bool partialSum(int N, std::vector<int> &nums, int W) {
    // dp[i][target] := nums[0...i-1]を使って和targetが作れるか
    std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(W + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= N; i++) {
      for (int target = 0; target <= W; target++) {
        // 下記の分岐を1行で書いてもいい
        // nums[i-1]を使わない
        dp[i][target] = dp[i - 1][target];

        // nums[i-1]を使う
        // ||以降がない場合、使わないOR使うではなく、使えるなら使う結果のみ残す、となってしまう
        // 両方のケースをできるとメモしておきたいのでOR
        if (target >= nums[i - 1]) {
          dp[i][target] = dp[i - 1][target - nums[i - 1]] || dp[i - 1][target];
        }
      }
    }

    return dp[N][W];
  }
};
