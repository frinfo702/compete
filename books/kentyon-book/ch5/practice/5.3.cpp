#include <iostream>
#include <vector>
using namespace std;

// グラフの辺に関する緩和の処理
template <class T> void chmin(T &a, T b) {
  if (a > b) {
    a = b;
  }
}

const long long INF = 1LL << 60;

int main() {
  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  vector<long long> dp(N, INF);

  dp[0] = h[0];
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < N; i++) {
    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[N - 1] << endl;
}
