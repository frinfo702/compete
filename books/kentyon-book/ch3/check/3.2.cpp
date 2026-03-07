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

  int target_count = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] == target) {
      target_count += 1;
    }
  }

  cout << target_count << endl;
}
