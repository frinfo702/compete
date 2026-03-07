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

  for (int i = 0; i < N; i++) {
    if (a[i] == v) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
