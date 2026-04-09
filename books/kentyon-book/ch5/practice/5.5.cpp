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
int N;
vector<long long> h(N);

// 0からiまでの最小コスト
long long rec(int i) {
  if (i == 0)
    return 0;

  long long res = INF;

  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

  if (i > 1) {
    chmin(res, rec(i - 2) + abs(h[i] - h[i - 1]));
  }

  return res; 
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  vector<long long> dp(N, INF); // minimum cost

  long long ans = rec(N);

  cout << dp[N - 1] << endl;
}
