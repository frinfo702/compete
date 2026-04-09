#include <cstdlib>
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

  vector<long long> dp(N, INF); // minimum cost

  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    if (i + 1 < N) {
      chmin(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
      continue;
    }
    if (i + 2 < N) {
      chmin(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }
  }

  cout << dp[N - 1] << endl;
}
