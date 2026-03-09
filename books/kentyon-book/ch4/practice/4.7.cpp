#include <iostream>
#include <vector>

using namespace std;

// O(N)
int main() {
  vector<long long> fibo(50);
  fibo[0] = 0;
  fibo[1] = 1;

  for (int n = 2; n < 50; n++) {
    fibo[n] = fibo[n - 1] + fibo[n - 2];
  }
  cout << fibo[49] << endl;
}
