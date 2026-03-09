#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo(50);

long long fibonacci(int N) {
  if (N == 0) {
    return 0;
  } else if (N == 1) {
    return 1;
  }

  if (memo[N] != -1) {
    return memo[N];
  }

  return memo[N] = fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
  memo.assign(50, -1);

  fibonacci(49);

  for (int i = 0; i < 50; i++) {
    cout << memo[i] << endl;
  }
}
