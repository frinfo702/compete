#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, target;
  cin >> N >> target;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int bit = 0; bit < (1 << N); bit++) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        sum += a[i];
      }
    }

    if (sum == target) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
