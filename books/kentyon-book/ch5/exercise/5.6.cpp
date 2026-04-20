#include <vector>
using namespace std;

class Solution {
public:
  bool solution(vector<int> &nums, vector<int> &constraints, int w) {
    // dp[i][j] := numsの0th index~ ith
    // indexまでを制限下で何回かずつ足して和jが作れるか
    int N = nums.size();
    vector<vector<bool>> dp(N, vector<bool>(w, false));
    dp[0][0] = true;
    
    
  }
};
