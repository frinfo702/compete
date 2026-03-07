#include <iostream>
#include <vector>
using namespace std;

const int INF = 20000000;

// time complexity: O()
int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int min_value = INF;
  for (int idx = 0; idx < N; idx++) {
    if (a[idx] < min_value) {
      min_value = a[idx];
    }
  }

  cout << min_value << endl;
}
