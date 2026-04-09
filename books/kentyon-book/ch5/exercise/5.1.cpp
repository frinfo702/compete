#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int vacation(int N, vector<int> a, vector<int> b, vector<int> c) {
    // dp[i][j]: i日目に行動jをした時の1日目からi日目までの幸福度の最大値
    vector<vector<int>> dp(N, vector<int>(3, 0));

    dp[0][0] = a[0];
    dp[0][0] = b[0];
    dp[0][0] = c[0];

    for (int day = 1; day < N; day++) {
      dp[day][0] = max(dp[day - 1][1], dp[day - 1][2]) + a[day];
      dp[day][1] = max(dp[day - 1][0], dp[day - 1][2]) + b[day];
      dp[day][2] = max(dp[day - 1][0], dp[day - 1][1]) + c[day];
    }

    return max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
  }
};
