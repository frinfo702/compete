#include <iostream>
#include <vector>
using namespace std;

// time complexity: O(N)

int main() {
  int N, v;
  cin >> N >> v;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int found_idx = -1;

  for (int i = 0; i < N; i++) {
    if (a[i] == v) {
      found_idx = i;
    }
  }

  if (found_idx >= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
