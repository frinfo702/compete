#include <iostream>
#include <vector>
using namespace std;

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}

int main() {
  int N;       // a number of items
  long long W; // a sum of weight
  cin >> N >> W;
  vector<long long> weights(N), values(N);
  for (int i = 0; i < N; i++) {
    cin >> weights[i] >> values[i];
  }

  // 先頭からi個のアイテムを選択、その時の重さの合計がwになるように選んだ価値の最大値
  vector<vector<long long>> maxvalue_dp(N + 1, vector<long long>(W + 1, 0));

  for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
      if (w - weights[i] >= 0) {
        chmax(maxvalue_dp[i + 1][w],
              maxvalue_dp[i][w - weights[i]] + values[i]);
      }

      chmax(maxvalue_dp[i + 1][w], maxvalue_dp[i][w]);
    }
  }

  cout << maxvalue_dp[N][W] << endl;
}
