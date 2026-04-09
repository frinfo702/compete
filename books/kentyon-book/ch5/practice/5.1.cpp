#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1000000000;

int main() {
  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  vector<long long> dp(N, INF);

  dp[0] = h[0];
  dp[1] = h[1] - h[0];
  for (int i = 2; i < N; i++) {
    int smallerCost =
        min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    dp[i] = smallerCost;
  }

  cout << dp[N - 1] << endl;
}


